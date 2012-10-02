;
; Windows Freenet Uninstaller by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk) - http://freenetproject.org/
;
; This is the uninstaller. Should be built before the installer,
; and included into the installer as any other file to be installed.
;

;
; Don't-touch-unless-you-know-what-you-are-doing settings
;
#NoEnv								; Recommended for performance and compatibility with future AutoHotkey releases
#NoTrayIcon							; We won't need this...
#SingleInstance	ignore						; Only allow one instance of at any given time (theoretically, if we allowed multiple, we could run into some temp files problems)

#Include ..\include_translator\Include_Translator.ahk		; Include translation helper

SendMode, Input							; Recommended for new scripts due to its superior speed and reliability
StringCaseSense, Off						; Treat A-Z as equal to a-z when comparing strings. Useful when dealing with folders, as Windows treat them as equals.
DetectHiddenWindows, On						; As we are going to manipulate a hidden widow, we need to actually look for it too

;
; Customizable settings
;
_ProgressFormat = A T W300 FS10					; How our progress bar should look. The 'R' (range) parameter is added later in the script.
_CloseTimeout := 30						; (seconds) How long to wait for the tray manager (and there by the wapper and node) to close before failing with an error

;
; General init stuff
;
InitTranslations()

;
; Setup various stuff and make sure that we are running from the temp folder (we need to, because we can't delete the install folder if we are running the uninstaller from it at the same time)
;
Loop, %A_Temp%, 1
{
	LongTempDirPath = %A_LoopFileLongPath%								; Windows might give us the temp path as an "8.3 short name", so lets get the *real* path
}

If (A_ScriptDir <> (LongTempDirPath . "\FreenetUninstaller"))
{
	_InstallDir := A_ScriptDir

	FileRemoveDir, %A_Temp%\FreenetUninstaller, 1							; Remove any old temp dir
	FileCreateDir, %A_Temp%\FreenetUninstaller							; Create a new temp dir
	If (ErrorLevel)
	{
		PopupErrorMessage(Trans("Freenet uninstaller") " " Trans("was not able to unpack necessary files to:") "`n`n" A_Temp "\FreenetUninstaller`n`n" Trans("Please make sure that this program has full access to the system's temporary files folder."))
		ExitApp
	}

	FileCopy, %A_ScriptFullPath%, %A_Temp%\FreenetUninstaller
	Run, %A_Temp%\FreenetUninstaller\%A_ScriptName% "%_InstallDir%", , UseErrorLevel

	ExitApp
}
Else
{
	_InstallDir = %1%										; Fetch installdir from the command line parameter

	If (!(FileExist(_InstallDir . "\freenet.jar") || FileExist(_InstallDir . "\freenet.jar.new")) || !FileExist(_InstallDir . "\installid.dat"))
	{
		PopupErrorMessage(Trans("Freenet uninstaller") " " Trans("was unable to recognize your Freenet installation at:") "`n`n" _InstallDir "`n`n" Trans("Please run this program from a Freenet installation directory."))
		ExitApp
	}

	FileReadLine, _InstallSuffix, %_InstallDir%\installid.dat, 1

	SetWorkingDir, %A_ScriptDir%									; Switch to our temp dir as working dir. *NO* FileInstall lines before this!
}

;
; Ask for confirmation
;
MsgBox, 33, % Trans("Freenet uninstaller"), % Trans("Do you really want to uninstall Freenet?")		; 1 = OK/Cancel, 32 = Icon Question
IfMsgBox, Cancel
{
	ExitApp
}

;
; Alright. No way back!
;
Progress, %_ProgressFormat% R0-3, ..., , % Trans("Freenet uninstaller")					; "Rx-y" defines number of "ticks" in the progress bar. Should match the numbers below.

;
; Shut down node
;
Progress, , % Trans("Closing Freenet...")

FileRead, _TrayPID, %_InstallDir%\freenet.pid

If (ErrorLevel == 0)
{
	WinClose, ahk_pid %_TrayPID%, , _CloseTimeout

	; Double-check
	Process, Exist, %_TrayPID%

	If (ErrorLevel != 0)
	{
		PopupErrorMessage(Trans("Freenet uninstaller") " " Trans("was unable to close Freenet.") "`n`n" Trans("Please manually close all Freenet processes (including java.exe) before continuing."))
	}
}

Progress, 1

;
; Remove files
;
Progress, , % Trans("Removing files...")
RemoveFiles:

FileRemoveDir, %_InstallDir%, 1
If (ErrorLevel)
{
	MsgBox, 18, % Trans("Freenet uninstaller error"), % Trans("Freenet uninstaller") " " Trans("was unable to delete the Freenet files located at:") "`n`n" _InstallDir "`n`n" Trans("Please close all applications with open files inside this directory.")	; 2 = Abort/Retry/Ignore, 16 = Icon Hand (stop/error)

	IfMsgBox, Abort
	{
		PopupErrorMessage(Trans("The uninstallation was aborted.") "`n`n" Trans("Please manually remove the rest of your Freenet installation."))
		ExitApp
	}
	IfMsgBox, Retry
	{
		Goto, RemoveFiles
	}
}

; We don't really care if deletion of shortcuts fail, as the user probably just deleted / renamed / moved them around.
FileDelete, %A_Startup%\Start Freenet%_InstallSuffix%.lnk
FileRemoveDir, %A_Programs%\Freenet%_InstallSuffix%, 1
FileDelete, %A_Desktop%\Freenet%_InstallSuffix%.lnk

Progress, 2

;
; Remove registry edits
;
Progress, , % Trans("Removing registry information...")

RegDelete, HKEY_CURRENT_USER, SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Freenet%_InstallSuffix%

Progress, 3

;
; Done!
;
Progress, Off
MsgBox, 64, % Trans("Freenet uninstaller"), % Trans("Freenet has been uninstalled!")			; 64 = Icon Asterisk (info)

ExitApp

;
; Helper functions
;
PopupErrorMessage(_ErrorMessage)
{
	MsgBox, 16, % Trans("Freenet uninstaller error"), %_ErrorMessage%	; 16 = Icon Hand (stop/error)
}
