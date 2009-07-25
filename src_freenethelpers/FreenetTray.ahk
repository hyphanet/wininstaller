;
; Freenet Windows Tray Manager by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk) - http://freenetproject.org/
;
; Extra credits:
; - Service state function: heresy (http://www.autohotkey.com/forum/topic34984.html)
;

;
; Don't-touch-unless-you-know-what-you-are-doing settings
;
#NoEnv									; Recommended for performance and compatibility with future AutoHotkey releases
#Persistent								; Keep script alive even after we "return" from the main function
#SingleInstance	OFF							; Allow several instances at the same time

#Include ..\src_translationhelper\Include_TranslationHelper.ahk		; Include translation helper

SendMode, Input								; Recommended for new scripts due to its superior speed and reliability
StringCaseSense, Off							; Treat A-Z as equal to a-z when comparing strings. Useful when dealing with folders, as Windows treat them as equals.
_LastState := -1							; Variable to keep track of the last known state of the service. -1 = Unknown, 0 = Disabled, 1 = Enabled

;
; Customizable settings
;
_FileRequirements = installid.dat|freenet.ico|freenetoffline.ico|bin\start.exe|bin\stop.exe|freenetlauncher.exe|update.cmd	; List of files that must exist for the tray manager to work. Paths are relative to own location.
_UpdateInterval := 5000							; (ms) How long between each service status check? Must not be greater than however long the uninstaller waits for us to respond to a shutdown signal (see the status update function)

;
; General init stuff
;
_FreenetDir := RegExReplace(A_ScriptDir, "i)\\bin$", "")		; If we are located in the \bin folder, go back a step.
SetWorkingDir, %_FreenetDir%						; Look for other files relative to our own location

InitTranslations()

Loop, Parse, _FileRequirements, |
{
	IfNotExist, %A_LoopField%
	{
		PopupErrorMessage(Trans("Freenet Tray") " " Trans("was unable to find the following file:") "`n`n" A_LoopField "`n`n" Trans("Make sure that you are running ") Trans("Freenet Tray") Trans(" from a Freenet installation directory.") "`n`n" Trans("If the problem keeps occurring, try reinstalling Freenet or report this error message to the developers."))
		ExitApp, 1
	}	
}

FileReadLine, _InstallSuffix, installid.dat, 1				; Read our install suffix from installid.dat
_ServiceName = freenet%_InstallSuffix%					; Put together our service name

;
; Fix up a tray icon and a tray menu
;
Menu, TRAY, NoStandard							; Remove default tray menu items
Menu, TRAY, Icon, freenetoffline.ico, , 1				; As we don't know if the node is running yet, show as offline
Menu, TRAY, Tip, % Trans("Freenet Tray") _InstallSuffix

Menu, TRAY, Add, % Trans("Launch Freenet"), BrowseFreenet
Menu, TRAY, Add								; Separator
Menu, TRAY, Add, % Trans("Start Freenet service"), Start
Menu, TRAY, Add, % Trans("Stop Freenet service"), Stop
Menu, TRAY, Add								; Separator
Menu, TRAY, Add, % Trans("Manual update check"), Update
Menu, TRAY, Add, % Trans("View logfile"), OpenLog
Menu, TRAY, Add								; Separator
Menu, TRAY, Add, % Trans("About"), About
Menu, TRAY, Add, % Trans("Exit"), Exit

Menu, TRAY, Disable, % Trans("Launch Freenet")
Menu, TRAY, Disable, % Trans("Start Freenet service")
Menu, TRAY, Disable, % Trans("Stop Freenet service")

;
; Display a welcome balloontip if requested in the command line
;
_Arg1 = %1%
If (_Arg1 == "/welcome")
{
	TrayTip, % Trans("Freenet Tray"),% Trans("You can browse, start and stop Freenet along with other useful things from this tray icon.") "`n`n" Trans("Doubleclick: Start/Browse Freenet") "`n" Trans("Right-click: Advanced menu"), , 1	; 1 = Info icon
}

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
; Label subroutine: Start
;
Start:

RunWait, bin\start.exe /silent, , UseErrorLevel
DoStatusUpdate()

return

;
; Label subroutine: Stop
;
Stop:

RunWait, bin\stop.exe /silent, , UseErrorLevel
DoStatusUpdate()

return

;
; Label subroutine: Update
;
Update:

MsgBox, 49, % Trans("Freenet Tray"), % Trans("Warning: Using the manual update check will update Freenet and its helper tools from the official Freenet website.") "`n`n" Trans("Freenet already has a secure built-in autoupdate feature that will keep itself up-to-date automatically.") "`n`n" Trans("You should only use this manual update check if your installation is broken or you need updated versions of the helper tools.")	; 1 (OK/Cancel) + 48 (Icon Exclamation)

IfMsgBox, OK
{
	Run, update.cmd, , UseErrorLevel
}

return

;
; Label subroutine: OpenLog
;
OpenLog:

Run, notepad.exe wrapper.log, , UseErrorLevel				; We really should just call "wrapper.log" directly and let Windows choose the viewer, but until we know for sure that all supported versions of Windows actually *have* a default .log association, we explicitly ask for Notepad. (See https://bugs.freenetproject.org/view.php?id=3245)

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

	_CurrentState := Service_State(_ServiceName)

	If (_LastState <> 1 && _CurrentState == 4)
	{
		_LastState := 1

		Menu, TRAY, Icon, freenet.ico, , 1

		Menu, TRAY, Enable, % Trans("Launch Freenet")
		Menu, TRAY, Disable, % Trans("Start Freenet service")
		Menu, TRAY, Enable, % Trans("Stop Freenet service")

		Menu, TRAY, Default, % Trans("Launch Freenet")
	}
	Else If (_LastState <> 0 && _CurrentState <> 4)
	{
		_LastState := 0

		Menu, TRAY, Icon, freenetoffline.ico, , 1

		Menu, TRAY, Disable, % Trans("Launch Freenet")
		Menu, TRAY, Enable, % Trans("Start Freenet service")
		Menu, TRAY, Disable, % Trans("Stop Freenet service")

		Menu, TRAY, Default, % Trans("Start Freenet service")
	}
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
