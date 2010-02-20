;
; Windows Freenet Installer by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk) - http://freenetproject.org/
;
; Extra credits:
; - Charset conversion functions: Sean (http://www.autohotkey.com/forum/topic17343.html)

;
; Don't-touch-unless-you-know-what-you-are-doing settings
;
#NoEnv									; Recommended for performance and compatibility with future AutoHotkey releases
#NoTrayIcon								; We won't need this...
#SingleInstance	ignore							; Only allow one instance of at any given time (theoretically, if we allowed multiple, we could run into some temp files problems)

#Include FreenetInstaller_Include_Info.inc				; Include version and build info (which should be updated by the compiler bot before compiling this installer) as well as localizations
#Include ..\src_translationhelper\Include_TranslationHelper.ahk		; Include translation helper

SendMode, Input								; Recommended for new scripts due to its superior speed and reliability
SetFormat, FLOAT, 0.0							; Remove trailing zeroes on floats. We won't need the precision and it looks stupid with numbers printed with 27 trailing zeroes
StringCaseSense, Off							; Treat A-Z as equal to a-z when comparing strings. Useful when dealing with folders, as Windows treat them as equals.
_FontSize := 9								; Our font size. Changing this *might* mess up some of the margin calculations! See comment for _TextHeight calculation below as well.
Gui, +OwnDialogs							; Make messageboxes "stick" to the main GUI

;
; Customizable settings
;
_GuiWidth := 475+10+10							; Main GUI width. Should be the same size as the header image + default element margins (used for the GUI window itself)
_StandardMargin := 12							; Our standard margin. Must be at least 8 px.
_ButtonWidth := 100							; Width of our buttons
_LanguageListWidth := 100						; Width of language drop-down list

_RequiredJRE := 1.6							; Java version required by Freenet. If not found, user will be asked to upgrade/install via the bundled online installer
_RequiredFreeSpace := 10+256+384					; In MB, how much free space do we require to install? (x MB installed files + x MB minimum datastore size + x MB free space for Windows and other applications to continue operating without running low)
_InternalPathLength := 75						; Length of longest path within the Freenet installation. Installation will refuse to continue if install path + this number exceeds 255 (FAT32 and NTFS limit)

_DefaultInstallDir = %A_ProgramFiles%\Freenet				; Default installation directory
_cAutoStartTrayManager := 1						; Automatically start the tray manager on Windows startup by default?
_cInstallStartMenuShortcuts := 1					; Install start menu shortcut(s) by default?
_cInstallDesktopShortcuts := 0						; Install desktop shorctu(s) by default?
_cBrowseAfterInstall := 0						; Browse Freenet after installation by default?

;
; General init stuff
;
InitTranslations()

FileRemoveDir, %A_Temp%\FreenetInstaller, 1								; Remove any old temp dir
FileCreateDir, %A_Temp%\FreenetInstaller								; Create a new temp dir
If (ErrorLevel)
{
	MsgBox, 16, % Trans("Freenet Installer error"), % Trans("Freenet Installer") " " Trans("was not able to unpack necessary files to:") "`n`n" A_Temp "\FreenetInstaller`n`n" Trans("Please make sure that this program has full access to the system's temporary files folder.")	; 16 = Icon Hand (stop/error)
	ExitApp
}
SetWorkingDir, %A_Temp%\FreenetInstaller								; Switch to our new temp dir as working dir. *NO* FileInstall lines before this!

FileInstall, FreenetInstaller_Icon.ico, %A_WorkingDir%\FreenetInstaller_Icon.ico			; Unpack our small icon
Menu, Tray, Icon, FreenetInstaller_Icon.ico								; Set tray and GUI icon to our icon. Must be done before any Gui command to work

Gui, Font, s%_FontSize%, MS sans serif									; As default font may vary (and thereby mess up custom positioning and layout), we should force a specific

_StandardMargin2 := _StandardMargin-8
Gui, Margin, , %_StandardMargin2%				; 0=8px (which is minimum?). (A margin of 2px seems to be used outside groupboxes. Need to figure out why that is.)

_TextHeight := 2+_FontSize+2					; 9px has 2px built-in margin on top on bottom, making a normal line 13px high (except groupbox header text on classic theme, which seem to have 3px on top and 1px on bottom)
_GuiWidth2 := _GuiWidth-10-10					; GuiWidth - element left margin - element right margin (used for main elements such as header image, groupboxes and headlines)
_GBTopMargin := _TextHeight+(_StandardMargin/2)			; Pixels from y coordinate of start of groupbox whereafter content should begin
_GBBottomMargin := 2+(_StandardMargin/2)			; Bottom margin inside a groupbox
_VSpacingFromGBBottom := _GBBottomMargin+_StandardMargin	; Used when extra vertical spacing after a groupbox is wanted
_GBHorMargin := 2+_StandardMargin				; Horizontal margin for text within a groupbox (2px groupbox border + our standard margin)
_GuiWidth3 := _GuiWidth2-_GBHorMargin-_GBHorMargin		; GuiWidth2 - groupbox left margin - groupbox right margin (used for groupbox elements)
_MixLineTextPush := (24/2)-(_TextHeight/2)			; Used for vertically centering text on the same lines as one or more buttons. (Buttonheight/2)-(Textheight/2)

;
; Check for administrator privileges.
;
If not (A_IsAdmin)
{
	MsgBox, 16, % Trans("Freenet Installer error"), % Trans("Freenet Installer") " " Trans("requires administrator privileges to manage the Freenet service. Please make sure that your user account has administrative access to the system, and this program is executed with access to use these privileges.")	; 16 = Icon Hand (stop/error)
	Exit()
}

;
; Main GUI starts here!
;
GuiStart:												; Label to jump back to if we want to start over

;
; Image: Header logo
;
FileInstall, FreenetInstaller_Header.png, %A_WorkingDir%\FreenetInstaller_Header.png
Gui, Add, Picture, Section Center, FreenetInstaller_Header.png

;
; Welcome text
;
Gui, Font, bold
_TextWidth := _GuiWidth2-_LanguageListWidth-_StandardMargin
Gui, Add, Text, xs W%_TextWidth% Center Section, % "`n" Trans("Welcome to the Freenet Installer!") "`n"
Gui, Font, norm

;
; Drop-down list: Language selector
;
_LanguageList =

Loop % _LangArray-1
{
	_LanguageList := _LanguageList UTF82Ansi(_LanguageNames%A_Index%) "|"
}
_Listx := _GuiWidth2-_LanguageListWidth
_Listy := ((_TextHeight*3)/2)-(21/2)
Gui, Add, DropDownList, xp+%_Listx% yp+%_Listy% W%_LanguageListWidth% Choose%_LangNum% R10 v_cLanguageSelector g_ListSelectLanguage AltSubmit, %_LanguageList%

;
; Check for unsupported Windows version
;
If A_OSVersion not in WIN_XP,WIN_2003,WIN_VISTA	; Windows 7 falls under WIN_VISTA here
{
	;
	; Groupbox: Installation problem (OS requirement not met)
	;
	_GBHeight := CalculateGroupBoxHeight(8,0,0,0)
	Gui, Add, GroupBox, xs w%_GuiWidth2% h%_GBHeight% Section, % Trans("Installation problem")

	Gui, Add, Text, W%_GuiWidth3% xs+%_GBHorMargin% ys+%_GBTopMargin%, % Trans("Freenet only supports the following versions of the Windows operating system:") "`n`n- Windows XP`n- Windows Server 2003`n- Windows Vista`n- Windows 7`n`n" Trans("Please install one of these versions if you want to use Freenet on Windows.")

	;
	; Exit button
	;
	_Buttonx := (_GuiWidth2/2)-(_ButtonWidth/2)							; Center our button
	Gui, Add, Button, Default xs%_Buttonx% W%_ButtonWidth% gButtonExit, % Trans("E&xit")		; Label "Exit" is triggered upon activation

	Gui, Show, W%_GuiWidth%, % Trans("Freenet Installer")
	return
}

;
; Check for missing/old version of JRE
;
If (!CheckJavaVersion())
{
	;
	; Groupbox: Installation problem (Java requirement not met)
	;
	_GBHeight := CalculateGroupBoxHeight(4,1,0,2)
	Gui, Add, GroupBox, xs w%_GuiWidth2% h%_GBHeight% Section, % Trans("Installation problem")

	Gui, Add, Text, W%_GuiWidth3% xs+%_GBHorMargin% ys+%_GBTopMargin%, % Trans("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:")

	_Buttonx := (_GuiWidth2/2)-(_ButtonWidth/2)							; Center our button
	Gui, Add, Button, xs%_Buttonx% y+%_StandardMargin% W%_ButtonWidth% v_cInstallJavaButton gButtonInstallJava, % Trans("&Install Java")

	Gui, Add, Text, xs+%_GBHorMargin% y+%_StandardMargin% W%_GuiWidth3%, % Trans("The installation will continue once Java version") " " _RequiredJRE " " Trans("or later has been installed.")

	;
	; Exit button
	;
	_Buttonx := (_GuiWidth2/2)-(_ButtonWidth/2)							; Center our button
	Gui, Add, Button, Default xs%_Buttonx% W%_ButtonWidth% gButtonExit, % Trans("E&xit")

	Gui, Show, W%_GuiWidth%, % Trans("Freenet Installer")
	SetTimer, RecheckJavaVersionTimer, 5000
	return
}

;
; Check for old uninstaller
;
If (CheckForOldUninstaller())
{
	;
	; Groupbox: Installation problem (Old uninstaller detected)
	;
	_GBHeight := CalculateGroupBoxHeight(4,1,0,2)
	Gui, Add, GroupBox, xs w%_GuiWidth2% h%_GBHeight% Section, % Trans("Installation problem")

	Gui, Add, Text, W%_GuiWidth3% xs+%_GBHorMargin% ys+%_GBTopMargin%, % Trans("Freenet Installer") " " Trans("has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:")

	_Buttonx := (_GuiWidth2/2)-(_ButtonWidth/2)							; Center our button
	Gui, Add, Button, xs+%_Buttonx% y+%_StandardMargin% W%_ButtonWidth% v_cUninstallButton gButtonUninstall, % Trans("&Uninstall")

	Gui, Add, Text, xs+%_GBHorMargin% y+%_StandardMargin% W%_GuiWidth3%, % Trans("The installation will continue once the old installation has been removed.")

	;
	; Exit button
	;
	_Buttonx := (_GuiWidth2/2)-(_ButtonWidth/2)							; Center our button
	Gui, Add, Button, Default xs%_Buttonx% W%_ButtonWidth% gButtonExit, % Trans("E&xit")

	Gui, Show, W%_GuiWidth%, % Trans("Freenet Installer")
	SetTimer, RecheckOldUninstallerTimer, 5000
	return
}

;
; Text: Install guideline header
;
Gui, Add, Text, xs W%_GuiWidth2% Section, % Trans("Please check the following default settings before continuing with the installation of Freenet.")

;
; Groupbox: Install directory
;
_GBHeight := CalculateGroupBoxHeight(4,1,0,3)
Gui, Add, GroupBox, xs w%_GuiWidth2% h%_GBHeight% Section, % Trans("Installation directory")

Gui, Add, Text, xs+%_GBHorMargin% ys+%_GBTopMargin% W%_GuiWidth3% v_cInstallDirText, ...

_Buttonx := (_GuiWidth3+_GBHorMargin)-1*(_StandardMargin+_ButtonWidth)-_ButtonWidth
_Buttony := _GBTopMargin+_TextHeight+_StandardMargin
Gui, Add, Button, xs+%_Buttonx% ys%_Buttony% W%_ButtonWidth% v_cBrowseButton gButtonBrowse, % Trans("&Browse")
Gui, Add, Button, x+%_StandardMargin% W%_ButtonWidth% v_cDefaultButton gButtonDefault, % Trans("De&fault")

_Texty := 24+_StandardMargin
Gui, Add, Text, xs+%_GBHorMargin% yp+%_Texty% W%_GuiWidth3%, % Trans("Freenet requires the installation drive to have at least") " " _RequiredFreeSpace " " Trans("MB free disk space. The actual amount of space reserved to Freenet will be configured after the installation.")

_StatusWidth := _GuiWidth3-50										; We won't have a whole _GuiWidth3 to play around with, as the "Status: " part will use some of it (but we don't know how much because of localization). Allocating too much space will cause a small cosmetic bug (overlapping groupbox border), so make a proper guesstimate
Gui, Add, Text, , % Trans("Status:")
Gui, Add, Text, W%_StatusWidth% x+4 v_cInstallDirStatusText, ...						

;
; Groupbox: Node service
;
_GBHeight := CalculateGroupBoxHeight(3,0,0,0)
Gui, Add, GroupBox, xs w%_GuiWidth2% h%_GBHeight% Section, % Trans("System service")

Gui, Add, Text, xs+%_GBHorMargin% ys+%_GBTopMargin% W%_GuiWidth3%, % Trans("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.")

;
; Groupbox: Additional settings
;
_GBHeight := CalculateGroupBoxHeight(0,0,4,0)
Gui, Add, GroupBox, xs w%_GuiWidth2% h%_GBHeight% Section, % Trans("Additional settings")

Gui, Add, Checkbox, xs+%_GBHorMargin% ys+%_GBTopMargin% W%_GuiWidth3% v_cAutoStartTrayManager Checked%_cAutoStartTrayManager%, % Trans("Start Freenet &Tray Manager on Windows startup") " " Trans("(Recommended)")
Gui, Add, Checkbox, v_cInstallStartMenuShortcuts Checked%_cInstallStartMenuShortcuts%, % Trans("Install &start menu shortcuts") " " Trans("(Recommended)")
Gui, Add, Checkbox, v_cInstallDesktopShortcuts Checked%_cInstallDesktopShortcuts%, % Trans("Install &desktop shortcut") " " Trans("(Optional)")
Gui, Add, Checkbox, v_cBrowseAfterInstall Checked%_cBrowseAfterInstall%, % Trans("Launch Freenet &after the installation") " " Trans("(Optional)")

;
; Status bar and main buttons
;
Gui, Add, Button, Default xs W%_ButtonWidth% v_cExitButton Section gButtonExit, % Trans("E&xit")

_StatusSize := _GuiWidth2-2*(_StandardMargin+_ButtonWidth)						; Calculate size of our status bar

Gui, Add, Progress, x+%_StandardMargin% yp+%_MixLineTextPush% W%_StatusSize% Hidden h%_TextHeight% -Smooth v_cProgressBar
Gui, Add, Text, Center xp yp W%_StatusSize% v_cStatusText, % Trans("Version ") _Inc_FreenetVersion Trans(" - Build ") _Inc_FreenetBuild

Gui, Add, Button, x+%_StandardMargin% ys W%_ButtonWidth% v_cInstallButton gButtonInstall, % Trans("&Install")

;
; Gui layout finished, do GUI init stuff and return to "idle" state...
;
SetInstallDir("")
SetTimer, UpdateInstallDirStatusTimer, 10000
Gui, Show, W%_GuiWidth%, % Trans("Freenet Installer")
return

;
; Actual installation thread starts here (when user presses "Install")
;
ButtonInstall:
Gui, +OwnDialogs											; Make an eventual messagebox "stick" to the main GUI
VisualInstallStart(8)											; Freeze GUI, show progress bar, etc... Argument is number of "ticks" in the progress bar. Should match the number of +1's during the rest of the installation
FindInstallSuffix()											; Figure out if we already have existing installations we need to take into consideration, and if so, find a proper install suffix

;
; Test write access to install folder. For usability reasons we should not write anything to disk before user presses "install", hence placed here
;
If (!TestInstallDirWriteAccess())
{
	MsgBox, 48, % Trans("Freenet Installer error"), % Trans("Freenet Installer") " " Trans("was not able to write to the selected installation directory. Please select one to which you have write access.")	; 48 = Icon Exclamation
	VisualInstallEnd()
	return				
}
GuiControl, , _cProgressBar, +1

;
; Find a free port for fproxy
;
_FProxyPort := FindFreePort(8888)
If (_FProxyPort = -1)											; The actual error message will be displayed by FindFreePort(), so just handle the GUI recovery
{
	VisualInstallEnd()
	return
}
GuiControl, , _cProgressBar, +1

;
; Find a free port for fcp
;
_FCPPort := FindFreePort(9481)
If (_FCPPort = -1)
{
	VisualInstallEnd()
	return
}
GuiControl, , _cProgressBar, +1

;
; Install the actual node files, as defined in the include
;
#Include FreenetInstaller_Include_FileInstalls.inc
GuiControl, , _cProgressBar, +1

;
; Patch files, file permissions and the registry
;
FileAppend, %_InstallSuffix%,											%_InstallDir%\installid.dat	; Write id file in case third party software needs it. Will be empty if we are not using a suffix.

; Write freenet.ini stuff
FileAppend, fproxy.port=%_FProxyPort%`n,									%_InstallDir%\freenet.ini
FileAppend, fcp.port=%_FCPPort%`n,										%_InstallDir%\freenet.ini
FileAppend, pluginmanager.loadplugin=JSTUN;KeyExplorer;ThawIndexBrowser;UPnP;Library`n,				%_InstallDir%\freenet.ini
FileAppend, node.updater.autoupdate=true`n,									%_InstallDir%\freenet.ini
FileAppend, node.l10n=WINDOWS%A_Language%`n,									%_InstallDir%\freenet.ini
FileAppend, End`n,												%_InstallDir%\freenet.ini

; Write memory limits/info stuff
_TotalPhysMem := GetTotalPhysMem()
_NodeMaxMem := CalcNodeMaxMem(_TotalPhysMem)
FileAppend, %_TotalPhysMem%,											%_InstallDir%\memory.autolimit
FileAppend, `n,													%_InstallDir%\wrapper.conf
FileAppend, # Memory limit for the node`n,									%_InstallDir%\wrapper.conf
FileAppend, wrapper.java.maxmemory=%_NodeMaxMem%`n,								%_InstallDir%\wrapper.conf

; Write service settings stuff
FileAppend, `n,													%_InstallDir%\wrapper.conf
FileAppend, # Name of the service`n,										%_InstallDir%\wrapper.conf
FileAppend, wrapper.ntservice.name=freenet%_InstallSuffix%`n,							%_InstallDir%\wrapper.conf
FileAppend, `n,													%_InstallDir%\wrapper.conf
FileAppend, # Display name of the service`n,									%_InstallDir%\wrapper.conf
FileAppend, wrapper.ntservice.displayname=Freenet background service%_InstallSuffix%`n,				%_InstallDir%\wrapper.conf
FileAppend, `n,													%_InstallDir%\wrapper.conf
FileAppend, # User account to run the serve runder`n,								%_InstallDir%\wrapper.conf
FileAppend, wrapper.ntservice.account=NT AUTHORITY\LocalService`n,						%_InstallDir%\wrapper.conf

; Give LocalService full permissions to the install folder (it won't have write access by default)
If (A_OSVersion = "WIN_VISTA")
{
	RunWait, %comspec% /c "icacls "%_InstallDir%" /grant LocalService:(OI)(CI)F /T /C", , Hide UseErrorLevel	; If Vista (or Win7)
}
Else
{
	RunWait, %comspec% /c "cacls "%_InstallDir%" /E /T /C /G LocalService:F", , Hide UseErrorLevel			; Else we are XP
}

; Write uninstall stuff to registry
RegWrite, REG_SZ, HKEY_LOCAL_MACHINE, SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Freenet%_InstallSuffix%, DisplayIcon, %_InstallDir%\freenet.ico
RegWrite, REG_SZ, HKEY_LOCAL_MACHINE, SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Freenet%_InstallSuffix%, DisplayName, Freenet%_InstallSuffix%
RegWrite, REG_SZ, HKEY_LOCAL_MACHINE, SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Freenet%_InstallSuffix%, UninstallString, %_InstallDir%\bin\freenetuninstaller.exe
GuiControl, , _cProgressBar, +1

;
; Install service
;
RunWait, %_InstallDir%\bin\wrapper-windows-x86-32.exe -i ../wrapper.conf, , Hide UseErrorLevel
GuiControl, , _cProgressBar, +1

;
; Install shortcuts
;
If (_cAutoStartTrayManager)
{
	FileCreateShortcut, %_InstallDir%\bin\freenettray.exe, %A_StartupCommon%\Freenet Tray%_InstallSuffix%.lnk, , , % Trans("Opens Freenet Tray Manager in the notification area"), %_InstallDir%\Freenet.ico
}
If (_cInstallStartMenuShortcuts)
{
	FileCreateDir, %A_ProgramsCommon%\Freenet%_InstallSuffix%
	FileCreateShortcut, %_InstallDir%\freenetlauncher.exe, %A_ProgramsCommon%\Freenet%_InstallSuffix%\Freenet.lnk, , , % Trans("Opens the Freenet proxy homepage in a web browser"), %_InstallDir%\Freenet.ico
	FileCreateShortcut, %_InstallDir%\bin\freenettray.exe, %A_ProgramsCommon%\Freenet%_InstallSuffix%\Freenet Tray.lnk, , , % Trans("Opens Freenet Tray Manager in the notification area"), %_InstallDir%\Freenet.ico
}
If (_cInstallDesktopShortcuts)
{
	FileCreateDir, %A_DesktopCommon%
	FileCreateShortcut, %_InstallDir%\freenetlauncher.exe, %A_DesktopCommon%\Freenet%_InstallSuffix%.lnk, , , % Trans("Opens the Freenet proxy homepage in a web browser"), %_InstallDir%\Freenet.ico
}
GuiControl, , _cProgressBar, +1

;
; Start the node
;
RunWait, %_InstallDir%\bin\start.exe /verysilent, , UseErrorLevel
GuiControl, , _cProgressBar, +1

;
; Installation (almost) finished! (launching of stuff is done below for usability reasons)
;
MsgBox, 64, % Trans("Freenet Installer"), % Trans("Installation finished successfully!") "`n`n" Trans("Freenet Installer by:") " Christian Funder Sommerlund (Zero3)`n" Trans("English localization by: Christian Funder Sommerlund (Zero3)")	; 64 = Icon Asterisk (info)

;
; Launch stuff 	(Unfortunately, launched executables will inherit our UAC-elevation. There doesn't seem to be any easy way around this. They will be executed non-elevated the next time.
;
If (_cAutoStartTrayManager)
{
	Run, %_InstallDir%\bin\freenettray.exe /welcome, , UseErrorLevel
}
If (_cBrowseAfterInstall)
{
	Run, %_InstallDir%\freenetlauncher.exe, , UseErrorLevel
}

;
; Installation (completely) finished!
;
Exit()
return

;
; Include helpers
;
#Include FreenetInstaller_Include_Helpers.inc								; Include our helper functions. Should be placed at the very end because of labels
