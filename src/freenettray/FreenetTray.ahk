;
; Freenet Windows Tray Manager by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk) - http://freenetproject.org/
;

;
; Don't-touch-unless-you-know-what-you-are-doing settings
;
#NoEnv									; Recommended for performance and compatibility with future AutoHotkey releases
#Persistent								; Keep script alive even after we "return" from the main function
#SingleInstance	OFF							; Allow several instances at the same time

#Include ..\include_translator\Include_Translator.ahk			; Include translator

SendMode, Input								; Recommended for new scripts due to its superior speed and reliability
StringCaseSense, Off							; Treat A-Z as equal to a-z when comparing strings. Useful when dealing with folders, as Windows treat them as equals.

;
; Customizable settings
;
_FileRequirements = installid.dat|freenet.ico|freenetlauncher.exe	; List of files that must exist for the tray manager to work. Paths are relative to own location.

;
; General init stuff
;
SetWorkingDir, %A_ScriptDir%						; Look for other files relative to our own location

InitTranslations()

Loop, Parse, _FileRequirements, |
{
	IfNotExist, %A_LoopField%
	{
		PopupErrorMessage(Trans("Freenet Tray") " " Trans("was unable to find the following file:") "`n`n" A_LoopField "`n`n" Trans("Make sure that you are running") " " Trans("Freenet Tray") " " Trans("from a Freenet installation directory.") "`n`n" Trans("If the problem keeps occurring, try reinstalling Freenet or report this error message to the developers."))
		ExitApp, 1
	}	
}

FileReadLine, _InstallSuffix, installid.dat, 1				; Read our install suffix from installid.dat

;
; Fix up a tray icon and a tray menu
;
Menu, TRAY, NoStandard							; Remove default tray menu items
Menu, TRAY, Click, 1							; Activate default menu entry after a single click only (instead of default which most likely is doubleclick)
Menu, TRAY, Icon, freenet.ico, , 1					; As we don't know if the node is running yet, show as offline
Menu, TRAY, Tip, % Trans("Freenet Tray") _InstallSuffix

Menu, TRAY, Add, % Trans("Open Freenet"), BrowseFreenet
Menu, TRAY, Add								; Separator
Menu, TRAY, Add, % Trans("View logfile"), OpenLog
Menu, TRAY, Add								; Separator
Menu, TRAY, Add, % Trans("About"), About
Menu, TRAY, Add, % Trans("Exit"), Exit

Menu, TRAY, Disable, % Trans("Open Freenet")
MsgBox, TODO: Disable Open Freenet while node is still not running. Add offline icon?

;
; Display a welcome balloontip if requested in the command line
;
_Arg1 = %1%
If (_Arg1 == "/welcome")
{
	TrayTip, % Trans("Freenet Tray"),% Trans("You can browse, start and stop Freenet along with other useful things from this tray icon.") "`n`n" Trans("Left-click: Start/Browse Freenet") "`n" Trans("Right-click: Advanced menu"), , 1	; 1 = Info icon
}

;
; Start wrapper
;
Run, freenetwrapper.exe -c freenetwrapper.conf

;
; Setup regular status checks and do one now. Then return to idle.
;
SetTimer, StatusUpdate, %_UpdateInterval%
DoStatusUpdate()

return

;
; Label subroutine: BrowseFreenet
;
BrowseFreenet:

RunWait, freenetlauncher.exe, , UseErrorLevel

return

;
; Label subroutine: OpenLog
;
OpenLog:

Run, wrapper.log, , UseErrorLevel

return

;
; Label subroutine: About
;
About:

MsgBox, 64, % Trans("Freenet Tray"), % Trans("Freenet Windows Tray Manager") "`n`nhttp://freenetproject.org/"	; 64 = Icon Asterisk (info)

return

;
; Label subroutine: Exit
;
Exit:

ExitApp

return

;
; Label subroutine: StatusUpdate
;
StatusUpdate:

DoStatusUpdate()

return

;
; Helper functions
;
PopupErrorMessage(_ErrorMessage)
{
	MsgBox, 16, % Trans("Freenet Tray"), %_ErrorMessage%		; 16 = Icon Hand (stop/error)
}

DoStatusUpdate()
{
	global

	IfExist, tray_die.dat
	{
		ExitApp							; An external process (most likely the uninstaller) requested that we shutdown, so we better do so!
	}

	_CurrentState := 1
}

