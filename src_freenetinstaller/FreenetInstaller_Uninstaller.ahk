;
; Windows Freenet Uninstaller by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk) - http://freenetproject.org/
;
; This is the uninstaller. Should be built before the installer,
; and included into the installer as any other file to be installed.
;
; Extra credits:
; - Service functions: heresy (http://www.autohotkey.com/forum/topic34984.html)
; - RemProf.exe: Ctrl-Alt-Del IT Consultancy (http://www.ctrl-alt-del.com.au/CAD_TSUtils.htm)
;

;
; Don't-touch-unless-you-know-what-you-are-doing settings
;
#NoEnv								; Recommended for performance and compatibility with future AutoHotkey releases
#NoTrayIcon							; We won't need this...
#SingleInstance	ignore						; Only allow one instance of at any given time (theoretically, if we allowed multiple, we could run into some temp files problems)

#Include ..\src_translationhelper\Include_TranslationHelper.ahk	; Include translation helper

SendMode, Input							; Recommended for new scripts due to its superior speed and reliability
StringCaseSense, Off						; Treat A-Z as equal to a-z when comparing strings. Useful when dealing with folders, as Windows treat them as equals.

;
; Customizable settings
;
_ServiceTimeout := 120						; Maximum number of seconds we wait before "timing out" and throwing an error when managing the system service
_ProgressFormat = A T W300 FS10					; How our progress bar should look. The 'R' (range) parameter is added later in the script.

;
; General init stuff
;
InitTranslations()

;
; Check for administrator privileges.
;
If not (A_IsAdmin)
{
	PopupErrorMessage(Trans("The uninstaller requires administrator privileges to uninstall Freenet. Please make sure that your user account has administrative access to the system, and the uninstaller is executed with access to use these privileges."))
	ExitApp
}

;
; Setup various stuff and make sure that we are running from the temp folder (we need to, because we can't delete the install folder if we are running the uninstaller from it at the same time)
;
Loop, %A_Temp%, 1
{
	LongTempDirPath = %A_LoopFileLongPath%								; Windows might give us the temp path as an "8.3 short name", so lets get the *real* path
}

If (A_ScriptDir <> (LongTempDirPath . "\FreenetUninstaller"))
{
	_InstallDir := RegExReplace(A_ScriptDir, "i)\\bin$", "")					; If uninstaller is located in the \bin folder, go back a step.

	FileRemoveDir, %A_Temp%\FreenetUninstaller, 1							; Remove any old temp dir
	FileCreateDir, %A_Temp%\FreenetUninstaller							; Create a new temp dir
	If (ErrorLevel)
	{
		PopupErrorMessage(Trans("The uninstaller was not able to unpack necessary files to:") "`n`n" A_Temp "\FreenetUninstaller`n`n" Trans("Please make sure that the uninstaller has full access to the system's temporary files folder."))
		ExitApp
	}

	FileCopy, %A_ScriptFullPath%, %A_Temp%\FreenetUninstaller
	Run, %A_Temp%\FreenetUninstaller\%A_ScriptName% "%_InstallDir%", , UseErrorLevel

	ExitApp
}
Else
{
	_InstallDir = %1%										; Fetch installdir from the command line parameter

	If (!FileExist(_InstallDir . "\freenet.jar") || !FileExist(_InstallDir . "\installid.dat"))
	{
		PopupErrorMessage(Trans("The uninstaller was unable to recognize your Freenet installation at:") "`n`n" _InstallDir "`n`n" Trans("Please run this uninstaller from the 'bin' folder of a Freenet installation."))
		Exit()
	}

	FileReadLine, _InstallSuffix, %_InstallDir%\installid.dat, 1

	SetWorkingDir, %A_ScriptDir%									; Switch to our temp dir as working dir. *NO* FileInstall lines before this!
}

;
; Ask for confirmation and about the uninstallation survey
;
MsgBox, 33, % Trans("Freenet uninstaller"), % Trans("Do you really want to uninstall Freenet?")		; 1 = OK/Cancel, 32 = Icon Question
IfMsgBox, Cancel
{
	Exit()
}

MsgBox, 36, % Trans("Freenet uninstaller"), % Trans("The development team would appreciate it very much if you can`nspare a moment and fill out a short, anonymous online`nsurvey about the reason for your uninstallation.`n`nThe survey, located on the Freenet website, will be opened`nin your browser after the uninstallation.`n`nTake the uninstallation survey?")	; 4 = Yes/No, 32 = Icon Question
IfMsgBox, Yes
{
	_DoSurvey := 1
}
Else
{
	_DoSurvey := 0
}

;
; Allright. No way back!
;
Progress, %_ProgressFormat% R0-7, ..., , % Trans("Freenet uninstaller")					; "R0-6" defines number of "ticks" in the progress bar. Should match the numbers below.

;
; Shut down node
;
Progress, , % Trans("Stopping system service...")

_ServiceHasBeenStopped := 0										; Used to make sure that we only stop the service once (to avoid UAC spam on Vista, among other things)

Loop
{
	_ServiceState := Service_State("freenet" . _InstallSuffix)

	If (A_Index > _ServiceTimeout)
	{
		PopupErrorMessage(Trans("The uninstaller was unable to control the Freenet system service as it appears to be stuck.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers."))
		Exit()
	}
	Else If (_ServiceState == -1 || _ServiceState == -4)
	{
		PopupErrorMessage(Trans("The uninstaller was unable to find and control the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers."))
		Exit()
	}
	Else If (_ServiceState == 2 || _ServiceState == 3 || _ServiceState == 5 || _ServiceState == 6)
	{
		Sleep, 1000
		Continue
	}
	Else If (_ServiceState == 1)
	{
		Break						; Service is not running. Continue!
	}
	Else
	{
		If (!_ServiceHasBeenStopped)
		{
			_ServiceHasBeenStopped := 1
			Service_Stop("freenet" . _InstallSuffix)
			Continue
		}
		Else
		{
			PopupErrorMessage(Trans("The uninstaller was unable to stop the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers."))
			ExitApp, 1
		}
	}
}

Progress, 1

;
; Shut down tray managers
;
Progress, , % Trans("Shutting down tray managers...")

FileAppend, Die, %_InstallDir%\tray_die.dat	; Send a "die" signal to any tray managers hooked to this installation
Sleep, 10000					; Should be at least as long as the update interval in any tray manager that might be running
FileDelete, tray_die.dat

Progress, 1

;
; Remove service
;
Progress, , % Trans("Removing system service...")

RunWait, %_InstallDir%\bin\wrapper-windows-x86-32.exe -r ../wrapper.conf, , Hide UseErrorLevel

Progress, 2

;
; Remove special account rights for our custom user
;
Progress, , % Trans("Removing custom user account rights...")

FileInstall, files_bundle\Ntrights.exe, %A_WorkingDir%\Ntrights.exe					; Extract 3rd party "Ntrights" tool. Taken from old installer. (Apparently belongs to the resource kit and is OK to redistribute)
RunWait, %A_WorkingDir%\Ntrights.exe -u Freenet%_InstallSuffix% -r SeServiceLogonRight, , Hide UseErrorLevel
RunWait, %A_WorkingDir%\Ntrights.exe -u Freenet%_InstallSuffix% -r SeIncreaseBasePriorityPrivilege, , Hide UseErrorLevel
RunWait, %A_WorkingDir%\Ntrights.exe -u Freenet%_InstallSuffix% -r SeDenyNetworkLogonRight, , Hide UseErrorLevel
RunWait, %A_WorkingDir%\Ntrights.exe -u Freenet%_InstallSuffix% -r SeDenyInteractiveLogonRight, , Hide UseErrorLevel
FileDelete, %A_WorkingDir%\Ntrights.exe

Progress, 3

;
; Remove files
;
Progress, , % Trans("Removing files...")
RemoveFiles:

FileRemoveDir, %_InstallDir%, 1
If (ErrorLevel)
{
	MsgBox, 18, % Trans("Freenet uninstaller error"), % Trans("The uninstaller was unable to delete the Freenet files located at:") "`n`n" _InstallDir "`n`n" Trans("Please close all applications with open files inside this directory.")	; 2 = Abort/Retry/Ignore, 16 = Icon Hand (stop/error)

	IfMsgBox, Abort
	{
		PopupErrorMessage(Trans("The uninstallation was aborted.`n`nPlease manually remove the rest of your Freenet installation."))
		Exit()
	}
	IfMsgBox, Retry
	{
		Goto, RemoveFiles
	}
}

; We don't really care if deletion of shortcuts fail, as the user probably just deleted / renamed / moved them around.
FileRemoveDir, %A_ProgramsCommon%\Freenet%_InstallSuffix%, 1
FileDelete, %A_DesktopCommon%\Freenet%_InstallSuffix%.lnk

Progress, 4

;
; Remove registry edits
;
Progress, , % Trans("Removing registry modifications...")

RegDelete, HKEY_LOCAL_MACHINE, SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\SpecialAccounts\UserList, Freenet%_InstallSuffix%
RegDelete, HKEY_LOCAL_MACHINE, SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Freenet%_InstallSuffix%

Progress, 5

;
; Remove our custom user
;
Progress, , % Trans("Removing custom user...")

FileInstall, files_bundle\RemProf.exe, %A_WorkingDir%\RemProf.exe					; Extract 3rd party "RemProf" tool from http://www.ctrl-alt-del.com.au/CAD_TSUtils.htm. Freeware, but not open-source :(. Removes the profile folder and its registry entry of specified user
RunWait, %A_WorkingDir%\RemProf.exe Freenet%_InstallSuffix%, , Hide UseErrorLevel
FileDelete, %A_WorkingDir%\RemProf.exe

RunWait, %comspec% /c "net user Freenet%_InstallSuffix% /delete", , Hide UseErrorLevel

Progress, 6

;
; Done!
;
Progress, Off
MsgBox, 64, % Trans("Freenet uninstaller"), % Trans("Freenet has been uninstalled!")			; 64 = Icon Asterisk (info)

If (_DoSurvey)
{
	Run, http://freenetproject.org/uninstall.html, , UseErrorLevel
}

Exit()

;
; Helper functions
;
PopupErrorMessage(_ErrorMessage)
{
	MsgBox, 16, % Trans("Freenet uninstaller error"), %_ErrorMessage%	; 16 = Icon Hand (stop/error)
}

Service_State(ServiceName)
{
	; Return Values:
	; -4: Service not found
	; -1: Service could not be queried
	; 1: SERVICE_STOPPED (The service is not running)
	; 2: SERVICE_START_PENDING (The service is starting)
	; 3: SERVICE_STOP_PENDING (The service is stopping)
	; 4: SERVICE_RUNNING (The service is running)
	; 5: SERVICE_CONTINUE_PENDING (The service continue is pending)
	; 6: SERVICE_PAUSE_PENDING (The service pause is pending)
	; 7: SERVICE_PAUSED (The service is paused)

	SCM_HANDLE := DllCall("advapi32\OpenSCManagerA"
			, "Int", 0 ;NULL for local
			, "Int", 0
			, "UInt", 0x1) ;SC_MANAGER_CONNECT (0x0001)
                           
	if !(SC_HANDLE := DllCall("advapi32\OpenServiceA"
			, "UInt", SCM_HANDLE
			, "Str", ServiceName
			, "UInt", 0x4)) ;SERVICE_QUERY_STATUS (0x0004)
	result := -4 ;Service Not Found

	VarSetCapacity(SC_STATUS, 28, 0) ;SERVICE_STATUS Struct

	if !result
	result := !DllCall("advapi32\QueryServiceStatus"
			, "UInt", SC_HANDLE
			, "UInt", &SC_STATUS)
			? False : NumGet(SC_STATUS, 4) ;-1 or dwCurrentState

	DllCall("advapi32\CloseServiceHandle", "UInt", SC_HANDLE)
	DllCall("advapi32\CloseServiceHandle", "UInt", SCM_HANDLE)

	return result
}

Service_Stop(ServiceName)
{
	SCM_HANDLE := DllCall("advapi32\OpenSCManagerA"
			, "Int", 0 ;NULL for local
			, "Int", 0
			, "UInt", 0x1) ;SC_MANAGER_CONNECT (0x0001)   

	if !(SC_HANDLE := DllCall("advapi32\OpenServiceA"
			, "UInt", SCM_HANDLE
			, "Str", ServiceName
			, "UInt", 0x20)) ;SERVICE_STOP (0x0020)
	result := -4 ;Service Not Found

	if !result
	result := DllCall("advapi32\ControlService"
			, "UInt", SC_HANDLE
			, "Int", 1
			, "Str", "")

	DllCall("advapi32\CloseServiceHandle", "UInt", SC_HANDLE)
	DllCall("advapi32\CloseServiceHandle", "UInt", SCM_HANDLE)

	return result
}

Exit()
{
	global

	If (A_IsCompiled)										; Only do the following if we are compiled... Just in case a test session goes wrong.
	{
		; Request a self-destruct at next reboot (... because we can't delete a running executable)
		DllCall("MoveFileEx", "Str", A_ScriptFullPath, "Int", 0, "UInt", 0x4)
		DllCall("MoveFileEx", "Str", A_ScriptDir, "Int", 0, "UInt", 0x4)
	}

	ExitApp												; Bye Bye
}

