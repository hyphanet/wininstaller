;
; Windows Freenet Stopper by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk) - http://freenetproject.org/
;
; Extra credits:
; - Service state function: heresy (http://www.autohotkey.com/forum/topic34984.html)
;

;
; Don't-touch-unless-you-know-what-you-are-doing settings
;
#NoEnv									; Recommended for performance and compatibility with future AutoHotkey releases
#NoTrayIcon								; We won't need this...
#SingleInstance	ignore							; Only allow one instance at any given time

#Include ..\src_translationhelper\Include_TranslationHelper.ahk		; Include translation helper

SendMode, Input								; Recommended for new scripts due to its superior speed and reliability
StringCaseSense, Off							; Treat A-Z as equal to a-z when comparing strings. Useful when dealing with folders, as Windows treat them as equals.

SetWorkingDir, % RegExReplace(A_ScriptDir, "i)\\bin$", "")		; Look for other files relative to install root (regex: If we are located in the \bin folder, go back a step)

_SplashCreated := 0							; Initial value
_SignalSent := 0							; Used to make sure that we only try to manage the service once (if it doesn't work the first time, chances are that something is wrong)

;
; Customizable settings
;
_ServiceTimeout := 120							; Maximum number of seconds we wait before "timing out" and throwing an error when managing the system service
_SplashFormat = A M T FS8						; How our splash should look.

;
; General init stuff
;
InitTranslations()

;
; Check if we should be silent or not (error messages are always displayed though)
;
_Arg1 = %1%
If (_Arg1 == "/?")
{
	PopupInfoMessage(Trans("Command line options (only use one):") "`n/silent - " Trans("Hide info messages") "`n/verysilent - " Trans("Hide info and status messages") "`n`n" Trans("Return codes:") "`n0 - " Trans("Success") " " Trans("(service stopped)") "`n1 - " Trans("Error occurred") "`n2 - " Trans("Service was not running") " " Trans("(no action)"))
	ExitApp, 0
}
Else If (_Arg1 == "/silent")
{
	_Silent := 1
}
Else If (_Arg1 == "/verysilent")
{
	_Silent := 2
}
Else
{
	_Silent := 0
}

;
; Check for administrator privileges.
;
If not (A_IsAdmin)
{
	PopupErrorMessage(Trans("Freenet Stopper") " " Trans("requires administrator privileges to manage the Freenet service. Please make sure that your user account has administrative access to the system, and this program is executed with access to use these privileges."))
	ExitApp, 1
}

;
; Check node status
;
IfNotExist, installid.dat
{
	PopupErrorMessage(Trans("Freenet Stopper") " " Trans("was unable to find the following file:") "`n`ninstallid.dat`n`n" Trans("Make sure that you are running") " " Trans("Freenet Stopper") " " Trans("from a Freenet installation directory.") "`n`n" Trans("If the problem keeps occurring, try reinstalling Freenet or report this error message to the developers."))
	ExitApp, 1
}

FileReadLine, _InstallSuffix, installid.dat, 1
_ServiceName = freenet%_InstallSuffix%

Loop
{
	_ServiceState := Service_State(_ServiceName)

	If (A_Index > _ServiceTimeout)
	{
		SplashImage, OFF
		PopupErrorMessage(Trans("Freenet Stopper") " " Trans("was unable to control the Freenet system service.") "`n`n" Trans("Reason:") " " Trans("Timeout while managing the service") "`n`n" Trans("If the problem keeps occurring, try reinstalling Freenet or report this error message to the developers."))
		ExitApp, 1
	}
	Else If (_ServiceState == -1 || _ServiceState == -4)
	{
		PopupErrorMessage(Trans("Freenet Stopper") " " Trans("was unable to control the Freenet system service.") "`n`n" Trans("Reason:") " " Trans("Could not access the service.") "`n`n" Trans("If the problem keeps occurring, try reinstalling Freenet or report this error message to the developers."))
		ExitApp, 1
	}
	Else If (_ServiceState == 2 || _ServiceState == 3 || _ServiceState == 5 || _ServiceState == 6)
	{
		If ((_Silent < 2) && !_SplashCreated)
		{
			_SplashCreated := 1
			SplashImage, , %_SplashFormat%, % Trans("The Freenet service is stopping..."), , % Trans("Freenet Stopper")
			WinActivate, % Trans("Freenet Stopper")
		}
		Sleep, 1000
		Continue
	}
	Else If (_ServiceState == 1)
	{
		SplashImage, OFF

		If (_SignalSent)
		{
			PopupInfoMessage(Trans("The Freenet service has been stopped!"))
			ExitApp, 0					; 0 = We stopped it
		}
		Else
		{
			PopupInfoMessage(Trans("The Freenet service is already stopped!"))
			ExitApp, 2					; 2 = No action taken (service was already stopped)
		}
	}
	Else
	{
		If (!_SignalSent)
		{
			_SignalSent := 1
			Service_Stop(_ServiceName)
			Continue
		}
		Else
		{
			PopupErrorMessage(Trans("Freenet Stopper") " " Trans("was unable to control the Freenet system service.") "`n`n" Trans("Reason:") " " Trans("Service did not respond to signal.") "`n`n" Trans("If the problem keeps occurring, try reinstalling Freenet or report this error message to the developers."))
			ExitApp, 1
		}
	}
}

;
; Helper functions
;
PopupErrorMessage(_ErrorMessage)
{
	MsgBox, 16, % Trans("Freenet Stopper error"), %_ErrorMessage%		; 16 = Icon Hand (stop/error)
}

PopupInfoMessage(_InfoMessage)
{
	global

	If (_Silent < 1)
	{
		MsgBox, 64, % Trans("Freenet Stopper"), %_InfoMessage%		; 64 = Icon Asterisk (info)
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

Service_Stop(ServiceName)
{
	; Return values:
	; 0: error
	; 1: success

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
