;
; Windows Freenet Installer - Include file - Helpers
;
; This file contains helpers (functions) used throughout the installer. Placed here to not clutter
; the main script file. Will be included directly into the installer (at the bottom) at compile time.
;

;
; General helpers
;
Exit()
{
	global

	SetTimer, RecheckOldUninstallerTimer, Off
	SetTimer, RecheckJavaVersionTimer, Off
	SetTimer, UpdateInstallDirStatusTimer, Off

	Gui, Destroy

	FileRemoveDir, %A_Temp%\FreenetInstaller, 1							; Clean up after ourselves

	ExitApp												; Bye Bye
}

;
; General GUI helpers
;
CalculateGroupBoxHeight(_GBTextLines, _GBButtonLines, _GBCheckBoxLines, _GBSpacings)
{
	global

	return _GBTopMargin+(_GBTextLines*_TextHeight)+(_GBButtonLines*24)+(_GBCheckboxLines*17)+(_GBSpacings*_StandardMargin)+_GBBottomMargin
}

_ListSelectLanguage:
	Gui, Submit, NoHide										; Read values of controls into their variables

	If (_cLanguageSelector <> _LangNum)
	{
		Gui, Destroy
		LoadLanguage(_cLanguageSelector)
		SetTimer, GuiStart, -100
	}
return

ButtonExit:
	Exit()
return

GuiClose:												; Triggered if user closes GUI via "the red cross"/ALT+F4/...
	If (!_IsInstalling)
	{
		Exit()
	}
return

;
; Java check helpers
;
CheckJavaVersion()
{
	global

	RegRead, _JavaVersion, HKEY_LOCAL_MACHINE, SOFTWARE\JavaSoft\Java Runtime Environment, CurrentVersion

	If (ErrorLevel || _JavaVersion < _RequiredJRE)
	{
		return 0
	}
	else
	{
		RegRead, _JavaLib, HKEY_LOCAL_MACHINE, SOFTWARE\JavaSoft\Java Runtime Environment\%_JavaVersion%, RuntimeLib

		If (ErrorLevel || !FileExist(_JavaLib))
		{
			return 0
		}
		Else
		{
			return 1
		}
	}
}

ButtonInstallJava:
	GuiControl, +Disabled, _cLanguageSelector
	GuiControl, +Disabled, _cInstallJavaButton
	FileInstall, ..\..\res\install_bundle\jre-online-installer.exe, %A_WorkingDir%\jre-online-installer.exe
	RunWait, %A_WorkingDir%\jre-online-installer.exe, , UseErrorLevel
	GuiControl, -Disabled, _cLanguageSelector
	GuiControl, -Disabled, _cInstallJavaButton
return

RecheckJavaVersionTimer:
	If (CheckJavaVersion())
	{
		SetTimer, RecheckJavaVersionTimer, Off
		Gui, Destroy
		SetTimer, GuiStart, -100
	}
return

;
; Old uninstaller check helpers
;
CheckForOldUninstaller()
{
	global

	RegRead, _OldUninstallerPath, HKEY_LOCAL_MACHINE, SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Freenet 0.7.0 "Darknet", UninstallString

	If (ErrorLevel)
	{
		return 0
	}
	else
	{
		return 1
	}
}

RecheckOldUninstallerTimer:
	If (!CheckForOldUninstaller())
	{
		SetTimer, RecheckOldUninstallerTimer, Off
		Gui, Destroy
		SetTimer, GuiStart, -100
	}
return

ButtonUninstall:
	GuiControl, +Disabled, _cLanguageSelector
	GuiControl, +Disabled, _cUninstallButton
	RunWait, %_OldUninstallerPath%, , UseErrorLevel
	GuiControl, -Disabled, _cLanguageSelector
	GuiControl, -Disabled, _cUninstallButton
return

;
; Install path helpers
;
ButtonBrowse:
	Gui, +OwnDialogs										; Bind the dialog below to the main GUI

	StringLeft, _OldBaseInstallDir, _InstallDir, StrLen(_InstallDir)-8
	FileSelectFolder, _NewInstallDir, *%_OldBaseInstallDir%, 1, % Trans("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.")	; *=Don't restrict user from browsing upwards from default folder, 1=Show a 'new folder' button
	_NewInstallDir := RegExReplace(_NewInstallDir, "\\$")						; Removes the trailing backslash, if present

	If (_NewInstallDir <> "")									; If user cancels, this will be empty, so don't pass it on in that case
	{
		SetInstallDir(_NewInstallDir)
	}
return

ButtonDefault:
	SetInstallDir(_DefaultInstallDir)
return

SetInstallDir(_NewInstallDir)
{
	global

	If (_NewInstallDir == "")
	{
		If (_InstallDir == "")
		{
			_NewInstallDir := _DefaultInstallDir
		}
		Else
		{
			_NewInstallDir := _InstallDir
		}
	}

	IfNotInString, _NewInstallDir, Freenet
	{
		_NewInstallDir = %_NewInstallDir%\Freenet
	}

	_InstallDir := _NewInstallDir

	If (StrLen(_InstallDir) > (_GuiWidth3 / 6))
	{
		StringLeft, _InstallDirTrimmed, _InstallDir, (_GuiWidth3 / 6) - 3
		GuiControl, Text, _cInstallDirText, %_InstallDirTrimmed%...
	}
	Else
	{
		GuiControl, Text, _cInstallDirText, %_InstallDir%
	}

	UpdateInstallDirStatus()
}

UpdateInstallDirStatus()
{
	global

	If (_InstallDir = _DefaultInstallDir)
	{
		GuiControl, +Disabled, _cDefaultButton
	}
	Else
	{
		GuiControl, -Disabled, _cDefaultButton
	}

	RegExMatch(_InstallDir, "i)([a-z]:\\).+", _InstallDrive)					; Check for a valid drive. If found, store in _InstallDrive1 (subpattern match number 1 = array 1)
	If (ErrorLevel || _InstallDrive1 = "")
	{
		GuiControl, +cRed, _cInstallDirStatusText
		GuiControl, Text, _cInstallDirStatusText, % Trans("Invalid install path!")
		GuiControl, +Disabled, _cInstallButton
	}
	Else if (StrLen(_InstallDir) + _InternalPathLength > 255)
	{
		GuiControl, +cRed, _cInstallDirStatusText
		GuiControl, Text, _cInstallDirStatusText, % Trans("Invalid install path!") " " Trans("(Too long for file system to handle)")
		GuiControl, +Disabled, _cInstallButton
	}
	Else
	{
		DriveSpaceFree, _InstallDriveFreeSpace, %_InstallDrive1%
		If (_InstallDriveFreeSpace < _RequiredFreeSpace)
		{
			GuiControl, +cRed, _cInstallDirStatusText
			GuiControl, Text, _cInstallDirStatusText, % Trans("Not enough free space on installation drive!")
			GuiControl, +Disabled, _cInstallButton
		}
		Else If (FileExist(_InstallDir . "\freenet.jar") || FileExist(_InstallDir . "\freenet.jar.new"))
		{
			GuiControl, +cRed, _cInstallDirStatusText
			GuiControl, Text, _cInstallDirStatusText, % Trans("Freenet already installed! Please uninstall first or choose another directory!")
			GuiControl, +Disabled, _cInstallButton
		}
		Else
		{
			GuiControl, +cGreen, _cInstallDirStatusText
			GuiControl, Text, _cInstallDirStatusText, % Trans("Installation directory OK!")
			GuiControl, -Disabled, _cInstallButton
		}
	}
}

UpdateInstallDirStatusTimer:
	UpdateInstallDirStatus()
return

;
; Actual installation helpers
;
FindInstallSuffix()
{
	global

	Loop
	{
		If (A_Index = 1)
		{
			_InstallSuffix =
		}
		Else
		{
			_InstallSuffix = _%A_Index%
		}

		RegRead, _Temp, HKEY_CURRENT_USER, SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Freenet%_InstallSuffix%, UninstallString

		If (ErrorLevel)
		{
			break											; Found a free entry! (...hopefully! Could technically also be an access error)
		}
	}
}

TestInstallDirWriteAccess()
{
	global

	FileCreateDir, %_InstallDir%
	FileAppend, <writetest>, %_InstallDir%\writetest.tmp
	If (ErrorLevel)
	{
		FileRemoveDir, %_InstallDir%									; Will by default not remove dir if it contains anything at all
		return 0
	}
	Else
	{
		FileDelete, %_InstallDir%\writetest.tmp
		return 1
	}
}

VisualInstallStart(_Ticks)
{
	global

	_IsInstalling := 1

	Gui, Submit, NoHide											; Read values of checkboxes etc. into their variables

	; Disable timers and buttons
	SetTimer, UpdateInstallDirStatusTimer, Off
	GuiControl, +Disabled, _cLanguageSelector
	GuiControl, +Disabled, _cBrowseButton
	GuiControl, +Disabled, _cDefaultButton
	GuiControl, +Disabled, _cExitButton
	GuiControl, +Disabled, _cInstallButton
	GuiControl, +Disabled, _cAutoStart
	GuiControl, +Disabled, _cInstallStartMenuShortcuts
	GuiControl, +Disabled, _cInstallDesktopShortcuts
	GuiControl, +Disabled, _cBrowseAfterInstall

	GuiControl, +Range0-%_Ticks%, _cProgressBar

	; Switch status text with progress bar
	GuiControl, +Hidden, _cStatusText
	GuiControl, -Hidden, _cProgressBar
}

VisualInstallEnd()
{
	global

	_IsInstalling := 0

	; Re-enable timers and buttons
	SetTimer, UpdateInstallDirStatusTimer, 5000
	GuiControl, -Disabled, _cLanguageSelector
	GuiControl, -Disabled, _cBrowseButton
	GuiControl, -Disabled, _cExitButton
	GuiControl, -Disabled, _cInstallButton
	GuiControl, -Disabled, _cAutoStart
	GuiControl, -Disabled, _cInstallStartMenuShortcuts
	GuiControl, -Disabled, _cInstallDesktopShortcuts
	GuiControl, -Disabled, _cBrowseAfterInstall

	; Switch status text with progress bar
	GuiControl, -Hidden, _cStatusText
	GuiControl, +Hidden, _cProgressBar

	; Do a check on install dir (mostly to fix default button status)
	UpdateInstallDirStatus()
}

FindFreePort(_StartPort)
{
	global

	Loop
	{
		if (A_Index > 256)										; If this many tries isn't enough, checking any more in this way is probably just a waste of time. Throw an error instead.
		{
			_Endport := _StartPort + 256 - 1
			MsgBox, 48, % Trans("Freenet Installer error"), % Trans("Freenet Installer") " " Trans("was not able to find a free port on your system in the range") " " _StartPort "-" _EndPort ". " Trans("Please free a system port in this range to install Freenet.") ; 48 = Icon Exclamation
			return -1
		}
		Else If (TestPortAvailability(_StartPort+A_Index-1))
		{
			return _StartPort+A_Index-1
		}
	}
}

TestPortAvailability(_Port)
{
	global

	VarSetCapacity(wsaData, 32)
	_Result := DllCall("Ws2_32\WSAStartup", "UShort", 0x0002, "UInt", &wsaData)				; Request Winsock 2.0 (0x0002)

	If (ErrorLevel)
	{
		MsgBox, 16, % Trans("Freenet Installer error"), % Trans("Freenet Installer") " " Trans("was not able to create a Winsock 2.0 socket for port availability testing.") ; 16 = Icon Hand (stop/error)
		Exit()
	}
	Else If (_Result)											; Non-zero, which means it failed (most Winsock functions return 0 upon success)
	{
		_Error := DllCall("Ws2_32\WSAGetLastError")
		DllCall("Ws2_32\WSACleanup")
		MsgBox, 16, % Trans("Freenet Installer error"), % Trans("Freenet Installer") " " Trans("was not able to create a Winsock 2.0 socket for port availability testing.") " (" Trans("Error: ") _Error ")" ; 16 = Icon Hand (stop/error)
		Exit()
	}

	AF_INET = 2
	SOCK_STREAM = 1
	IPPROTO_TCP = 6

	_Socket := DllCall("Ws2_32\socket", "Int", AF_INET, "Int", SOCK_STREAM, "Int", IPPROTO_TCP)
	if (_Socket = -1)
	{
		_Error := DllCall("Ws2_32\WSAGetLastError")
		DllCall("Ws2_32\WSACleanup")
		MsgBox, 16, % Trans("Freenet Installer error"), % Trans("Freenet Installer") " " Trans("was not able to create a Winsock 2.0 socket for port availability testing.") " (" Trans("Error: ") _Error ")" ; 16 = Icon Hand (stop/error)
		Exit()
	}

	SizeOfSocketAddress = 16
	VarSetCapacity(SocketAddress, SizeOfSocketAddress)
	InsertInteger(2, SocketAddress, 0, AF_INET)
	InsertInteger(DllCall("Ws2_32\htons", "UShort", _Port), SocketAddress, 2, 2)
	InsertInteger(DllCall("Ws2_32\inet_addr", "Str", "127.0.0.1"), SocketAddress, 4, 4)

	If DllCall("Ws2_32\connect", "UInt", _Socket, "UInt", &SocketAddress, "Int", SizeOfSocketAddress)
	{
		_Available := 1											; DllCall returned non-zero, e.g. fail - which means port is most likely free
	}
	Else
	{
		_Available := 0
	}

	DllCall("Ws2_32\WSACleanup")										; Do a cleanup (including closing of any open sockets)
	return _Available
}

InsertInteger(pInteger, ByRef pDest, pOffset = 0, pSize = 4)
{
	global

	Loop, %pSize%												; Copy each byte in the integer into the structure as raw binary data.
	{
		DllCall("RtlFillMemory", "UInt", &pDest + pOffset + A_Index-1, "UInt", 1, "UChar", pInteger >> 8*(A_Index-1) & 0xFF)
	}

}

GetTotalPhysMem()
{
	VarSetCapacity(_MEMORYSTATUSEX, 64, 0)				; MEMORYSTATUSEX struct is 2*4+7*8=64 bytes long
	NumPut(64, _MEMORYSTATUSEX)					; Put this size into dwLength (first variable of struct) as required

	DllCall("GlobalMemoryStatusEx", UInt, &_MEMORYSTATUSEX)		; Fill out struct with memory info from kernel

	return NumGet(_MEMORYSTATUSEX, 8, "Int64") / 1024 / 1024	; Return the float at position 8 (struct variable ullTotalPhys), divide by 1024 twice for MB
}

CalcNodeMaxMem(_TotalMemory)
{
	If (_TotalMemory > (2 * 1024))
	{
		_MaxMem := 512
	}
	else if (_TotalMemory > (1024))
	{
		_MaxMem := 256
	}
	else if (_TotalMemory > (512))
	{
		_MaxMem := 192
	}
	else
	{
		_MaxMem := 128
	}

	return _MaxMem
}
