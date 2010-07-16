;
; Windows Freenet start script by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk) - http://freenetproject.org/
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

;#Include ..\src_translationhelper\Include_TranslationHelper.ahk		; Include translation helper

SendMode, Input								; Recommended for new scripts due to its superior speed and reliability
StringCaseSense, Off							; Treat A-Z as equal to a-z when comparing strings. Useful when dealing with folders, as Windows treat them as equals.

;_WorkingDir := RegExReplace(A_ScriptDir, "i)\\bin$", "")		; If we are located in the \bin folder, go back a step
;SetWorkingDir, %_WorkingDir%						; Look for other files relative to install root

_SplashCreated := 0							; Initial value
_Silent := 0								; Initial value

;
; Customizable settings
;
_ServiceTimeout := 120							; Maximum number of seconds we wait before "timing out" and throwing an error when managing the system service
_SplashFormat = A B2 T FS8						; How our splash should look.

;
; General init stuff
;
;InitTranslations()

;
; Check for administrator privileges.
;
If not (A_IsAdmin)
{
	PopupErrorMessage("Freenet start script requires administrator privileges to start the Freenet service. Please make sure that your user account has administrative access to the system, and the start script is executed with access to use these privileges.")
	ExitApp, 1
}


MsgBox ,289,Update non-anonymously over HTTP?,Connect to the Freenetproject.org website and check for updates?
IfMsgBox Ok
    goto continue
else
    MsgBox Update Cancelled.
	ExitApp, 0
	
	
continue:


next:
Gui, Font, S12 CDefault, Verdana
Gui, Add, Text, w280 h30 , Please select release:
Gui, Add, Radio, w320 h40 vRELEASE Checked, Stable  (recommended)
Gui, Add, Radio, w170 h40 , Testing
Gui, Add, Button,w130 h40 Default, Next
;;Generated using SmartGUI Creator 4.0
Gui, Show, Autosize Center, Select Freenet Release
return
ButtonNext:
Gui, Submit ; Save the values of the radio buttons.
if RELEASE = 1
	{
	RELEASE = stablegui
	}
	else
	{
	RELEASE = testinggui
	}
	
;Launching script now...
run update.cmd %RELEASE%

ExitApp, 0

; Helper functions
;
PopupErrorMessage(_ErrorMessage)
{
	MsgBox, 16, % "Freenet start script error", %_ErrorMessage%		; 16 = Icon Hand (stop/error)
}

PopupInfoMessage(_InfoMessage)
{
	global

	If (_Silent < 1)
	{
		MsgBox, 64, % "Freenet start script", %_InfoMessage%		; 64 = Icon Asterisk (info)
	}
}


