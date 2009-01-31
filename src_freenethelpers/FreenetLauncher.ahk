;
; Windows Freenet Launcher by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk) - http://freenetproject.org/
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

SetWorkingDir, %A_ScriptDir%					; Look for other files relative to our own location

;
; Figure out what our service is called
;
IfNotExist, installid.dat
{
	PopupErrorMessage("Freenet Launcher was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.")
	ExitApp, 1
}
Else
{
	FileReadLine, _InstallSuffix, installid.dat, 1
	_ServiceName = freenet%_InstallSuffix%
}

;
; Make sure that node is running
;
If (Service_State(_ServiceName) <> 4)
{
	IfNotExist, bin\start.exe
	{
		PopupErrorMessage("Freenet Launcher was unable to find the bin\start.exe launcher.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.")
		ExitApp, 1
	}
	Else
	{
		RunWait, bin\start.exe /silent, , UseErrorLevel
	}
}

;
; Compile fproxy URL
;
IfNotExist, freenet.ini
{
	PopupErrorMessage("Freenet Launcher was unable to find the freenet.ini configuration file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.")
	ExitApp, 1
}
Else
{
	FileRead, _INI, freenet.ini
	If (RegExMatch(_INI, "i)fproxy.port=([0-9]{1,5})", _Port) == 0 || !_Port1)
	{
		PopupErrorMessage("Freenet Launcher was unable to read the 'fproxy.port' value from the freenet.ini configuration file.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.")
		ExitApp, 1
	}

	_URL = http://127.0.0.1:%_Port1%/
}

;
; Try browser: Mozilla FireFox (Tetsted versions: 3.0)
;
RegRead, _FFVersion, HKEY_LOCAL_MACHINE, Software\Mozilla\Mozilla Firefox, CurrentVersion

If (!ErrorLevel && _FFVersion <> "")
{
	RegRead, _FFPath, HKEY_LOCAL_MACHINE, Software\Mozilla\Mozilla Firefox\%_FFVersion%\Main, PathToExe

	If (!ErrorLevel && _FFPath <> "" && FileExist(_FFPath))
	{
		Run, %_FFPath% "%_URL%", , UseErrorLevel
		ExitApp, 0
	}
}

;
; Try browser: Opera (Tested versions: 9.6)
;
RegRead, _OperaInstallDir, HKEY_LOCAL_MACHINE, Software\Microsoft\Windows\CurrentVersion\Uninstall\{1BC4026B-1957-4514-9058-2B542557F143}, InstallLocation

If (!ErrorLevel && _OperaInstallDir <> "")
{
	_OperaPath = %_OperaInstallDir%\opera.exe

	IfExist, %_OperaPath%
	{
		Run, %_OperaPath% "%_URL%", , UseErrorLevel
		ExitApp, 0
	}
}

;
; Try browser: Google Chrome (Tested versions: 1.0.154) (no direct registry key to where it is installed, so we will have to do with what we get)
;
RegRead, _ChromeInstallDir, HKEY_CURRENT_USER, Software\Microsoft\Windows\CurrentVersion\Uninstall\Google Chrome, InstallLocation

If (!ErrorLevel && _ChromeInstallDir <> "")
{
	_ChromePath = %_ChromeInstallDir%\chrome.exe

	IfExist, %_ChromePath%
	{
		Run, %_ChromePath% "%_URL%", , UseErrorLevel
		ExitApp, 0
	}
}

;
; Try browser: Internet Explorer (Tested versions: 6.0)
;
IfExist, %A_ProgramFiles%\Internet Explorer\iexplore.exe
{
	Run, %A_ProgramFiles%\Internet Explorer\iexplore.exe "%_URL%", , UseErrorLevel
	ExitApp, 0
}

;
; No usable browser found
;
PopupErrorMessage("Freenet Launcher was unable to find a supported browser.`n`nPlease install one of the supported browsers, or manually`nnavigate to the URL inside freenet.url.dat.`n`nFreenet Launcher supports the following browsers:`n- Mozilla FireFox`n- Opera`n- Google Chrome`n- Internet Explorer (not recommended)")
ExitApp, 1

;
; Helper functions
;
PopupErrorMessage(_ErrorMessage)
{
	MsgBox, 16, Freenet Launcher error, %_ErrorMessage%	; 16 = Icon Hand (stop/error)
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
