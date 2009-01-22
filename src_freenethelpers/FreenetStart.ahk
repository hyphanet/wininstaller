;
; Windows Freenet start script by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk) - http://freenetproject.org/
;
; Extra credits:
; - Service state function: heresy (http://www.autohotkey.com/forum/topic34984.html)
;

;
; Don't-touch-unless-you-know-what-you-are-doing settings
;
#NoEnv								; Recommended for performance and compatibility with future AutoHotkey releases
#NoTrayIcon							; We won't need this...
#SingleInstance	ignore						; Only allow one instance at any given time

SendMode, Input							; Recommended for new scripts due to its superior speed and reliability
StringCaseSense, Off						; Treat A-Z as equal to a-z when comparing strings. Useful when dealing with folders, as Windows treat them as equals.

_WorkingDir := RegExReplace(A_ScriptDir, "i)\\bin$", "")	; If we are located in the \bin folder, go back a step
SetWorkingDir, %_WorkingDir%					; Look for other files relative to install root

;
; Customizable settings
;
_ServiceTimeout := 20						; Maximum number of seconds we wait before "timing out" and throwing an error when managing the system service

;
; Check for administrator privileges.
;
If not (A_IsAdmin)
{
	PopupErrorMessage("Freenet start script requires administrator privileges to start the Freenet service.`nPlease make sure that your user account has administrative access to the system,`nand the start script is executed with access to use these privileges.")
	ExitApp, 1
}

;
; Check node status
;
IfNotExist, installid.dat
{
	PopupErrorMessage("Freenet start script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet start script from the 'bin' folder of a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.")
	ExitApp, 1
}

FileReadLine, _InstallSuffix, installid.dat, 1
_ServiceName = freenet%_InstallSuffix%

Loop
{
	_ServiceState := Service_State(_ServiceName)

	If (A_Index > _ServiceTimeout)
	{
		PopupErrorMessage("Freenet start script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.")
		ExitApp, 1
	}
	Else If (_ServiceState == -1 || _ServiceState == -4)
	{
		PopupErrorMessage("Freenet start script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.")
		ExitApp, 1
	}
	Else If (_ServiceState == 2 || _ServiceState == 3 || _ServiceState == 5 || _ServiceState == 6)
	{
		Sleep, 1000
		Continue
	}
	Else If (_ServiceState == 1 || _ServiceState == 7)
	{
		_ReturnCode := Service_Start(_ServiceName)
		If (_ReturnCode <> 1)
		{
			PopupErrorMessage("Freenet start script was unable to start the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.")
			ExitApp, 1
		}
		Else
		{
			ExitApp, 0
		}
	}
	Else
	{
		ExitApp, 2					; Service must be running then!
	}
}

;
; Helper functions
;
PopupErrorMessage(_ErrorMessage)
{
	MsgBox, 16, Freenet start script error, %_ErrorMessage%	; 16 = Icon Hand (stop/error)
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

Service_Start(ServiceName)
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
			, "UInt", 0x10)) ;SERVICE_START (0x0010)
	result := -4 ;Service Not Found

	if !result
	result := DllCall("advapi32\StartServiceA"
			, "UInt", SC_HANDLE
			, "Int", 0
			, "Int", 0)

	DllCall("advapi32\CloseServiceHandle", "UInt", SC_HANDLE)
	DllCall("advapi32\CloseServiceHandle", "UInt", SCM_HANDLE)

	return result
}
