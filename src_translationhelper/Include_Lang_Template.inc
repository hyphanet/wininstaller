;
; Translation template
;
; Quick guide to translating:
; 1.	Save this file as "Include_Lang_xx.inc" (xx being a standard 2-letter lowercase language code, e.g. "en" for English or "da" for Danish)
; 2.	Replace "xx" with the same language code in "LoadLanguage_xx()" below.
; 3.	Translate! Format is: Trans_Add("<original text>", "<translated text>"). Please do not leave empty strings (comment them out instead so the installer will fall back to English for those strings).
; 4.	Submit the translation to SVN or the developer mailing list
; 4.a	Please make sure that either yourself or another developer tests the translation for obvious layout glitches and other bugs (simply launching the installer and verifying that the main GUI looks OK should be enough most of the time)
; 4.b	On the first submission, make sure that the translation is added to Include_TranslationHelper.ahk or nothing will happen ;)
;
; General note about translation:
; Because of the compact GUI design, much of the text are subject to min/max size limitations. A too short translation will leave holes in the GUI and
; a too long will mess up the layout. So try to keep the translations at the approx. same length as the original English text, with the approx. same
; placement of any newline markers. The easiest way to test the translation is to compile the installer and take a look around. The installer runs
; under WINE, but because of WINE bugs the layout will *not* be completely true to a real Windows installation.
;

LoadLanguage_xx()
{
	; Installer - Common
	Trans_Add("Freenet Installer", "")
	Trans_Add("Freenet Installer (Beta)", "")
	Trans_Add("Welcome to the Freenet Installer!", "")
	Trans_Add("Installation Problem", "")
	Trans_Add("Freenet Installer fatal error", "")
	Trans_Add("Freenet Installer error", "")
	Trans_Add("Error: ", "")
	Trans_Add("E&xit", "")

	; Installer - Error messageboxes
	Trans_Add("Freenet Installer was not able to unpack necessary installation files to:", "")
	Trans_Add("Please make sure that Freenet Installer has full access to the system's temporary files folder.", "")
	Trans_Add("Freenet Installer requires administrator privileges to install Freenet.`nPlease make sure that your user account has administrative access to the system, "")
	Trans_Add("Freenet Installer was not able to write to the selected installation directory.`nPlease select one to which you have write access.", "")
	Trans_Add("Freenet Installer was not able to find a free port on your system in the range ", "")
	Trans_Add("Please free a system port in this range to install Freenet.", "")
	Trans_Add("Freenet Installer was not able to create a Winsock 2.0 socket`nfor port availability testing.", "")

	; Installer - Unsupported Windows version
	Trans_Add("Freenet only supports the following versions of the Windows operating system:", "")
	Trans_Add("Please install one of these versions if you want to use Freenet on Windows.", "")

	; Installer - Java missing
	Trans_Add("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:", "")
	Trans_Add("&Install Java", "")
	Trans_Add("The installation will continue once Java version ", "")
	Trans_Add(" or later has been installed.", "")

	; Installer - Old installation detected
	Trans_Add("Freenet Installer has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:", "")
	Trans_Add("&Uninstall", "")
	Trans_Add("The installation will continue once the old installation has been removed.", "Installationen vil fortsætte når den tidligere installation er blevet fjernet.")

	; Installer - Main GUI - Header
	Trans_Add("Please check the following default settings before continuing with the installation of Freenet.", "")

	; Installer - Main GUI - Install folder
	Trans_Add("Installation directory", "")
	Trans_Add("Freenet requires at least ", "")
	Trans_Add(" MB free disk space, but will not install with less than ", "")
	Trans_Add(" MB free. The amount of space reserved can be changed after installation.", "")
	Trans_Add("&Browse", "")
	Trans_Add("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.", "")
	Trans_Add("De&fault", "")
	Trans_Add("Status:", "")
	Trans_Add("Invalid install path!", "")
	Trans_Add("Invalid install path! (Too long for file system to handle)", "")
	Trans_Add("Not enough free space on installation drive!", "")
	Trans_Add("Freenet already installed! Please uninstall first or choose another directory!", "")
	Trans_Add("Installation directory OK!", "")

	; Installer - Main GUI - System service
	Trans_Add("System service", "")
	Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "")

	; Installer - Main GUI - Additional settings
	Trans_Add("Additional settings", "")
	Trans_Add("Install &start menu shortcuts (All users: Freenet, Start Freenet, Stop Freenet)", "")
	Trans_Add("Install &desktop shortcut (All users: Freenet)", "")
	Trans_Add("Browse Freenet &after the installation", "")

	; Installer - Main GUI - Footer
	Trans_Add("Version ", "")
	Trans_Add(" - Build ", "")
	Trans_Add("&Install", "")

	; Installer - Actual installation
	Trans_Add("Opens the Freenet proxy homepage in a web browser", "")
	Trans_Add("Start Freenet", "")
	Trans_Add("Starts the background service needed to use Freenet", "")
	Trans_Add("Stop Freenet", "")
	Trans_Add("Stops the background service needed to use Freenet", "")
	Trans_Add("Installation finished successfully!", "")

	; Uninstaller - Common
	Trans_Add("Freenet uninstaller", "Freenet afinstallationsprogram")
	Trans_Add("Freenet uninstaller error", "Freenet afinstallationsprogram fejl")

	; Uninstaller - General
	Trans_Add("Freenet has been uninstalled!", "")
	Trans_Add("Do you really want to uninstall", "")
	Trans_Add("The development team would appreciate it very much if you can`nspare a moment and fill out a short, anonymous online`nsurvey about the reason for your uninstallation.`n`nThe survey, located on the Freenet website, will be opened`nin your browser after the uninstallation.`n`nTake the uninstallation survey?", "")

	; Uninstaller - Error messageboxes
	Trans_Add("The uninstaller requires administrator privileges to uninstall Freenet. Please make sure that your user account has administrative access to the system, and the uninstaller is executed with access to use these privileges.", "")
	Trans_Add("The uninstaller was not able to unpack necessary files to:", "")
	Trans_Add("Please make sure that the uninstaller has full access to the system's temporary files folder.", "")
	Trans_Add("The uninstaller was unable to recognize your Freenet installation at:", "")
	Trans_Add("Please run this uninstaller from the 'bin' folder of a Freenet installation.", "")

	; Uninstaller - Service problems
	Trans_Add("The uninstaller was unable to control the Freenet system service as it appears to be stuck.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("The uninstaller was unable to find and control the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("The uninstaller was unable to stop the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")

	; Uninstaller - Files undeletable
	Trans_Add("The uninstaller was unable to delete the Freenet files located at:", "")
	Trans_Add("Please close all applications with open files inside this directory.", "")
	Trans_Add("The uninstallation was aborted.`n`nPlease manually remove the rest of your Freenet installation.", "")

	; Uninstaller - Progress statuses
	Trans_Add("Stopping system service...", "")
	Trans_Add("Removing system service...", "")
	Trans_Add("Removing custom user account rights...", "")
	Trans_Add("Removing files...", "")
	Trans_Add("Removing registry modifications...", "")
	Trans_Add("Removing custom user...", "")

	; Launcher
	Trans_Add("Freenet Launcher error", "")
	Trans_Add("Freenet Launcher was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "")
	Trans_Add("Freenet Launcher was unable to find the bin\start.exe launcher.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("Freenet Launcher was unable to find the freenet.ini configuration file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "")
	Trans_Add("Freenet Launcher was unable to read the 'fproxy.port' value from the freenet.ini configuration file.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("Freenet Launcher was unable to find a supported browser.`n`nPlease install one of the supported browsers, or manually`nnavigate to: ", "")
	Trans_Add("Freenet Launcher supports the following browsers:", "")
	Trans_Add("not recommended", "")

	; Service starter
	Trans_Add("Command line options (only use one):`n/silent - Hide info messsages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service started)`n1 - Error occurred`n2 - Service was already running (no action)", "")
	Trans_Add("Freenet start script requires administrator privileges to start the Freenet service. Please make sure that your user account has administrative access to the system, and the start script is executed with access to use these privileges.", "")
	Trans_Add("Freenet start script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet start script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "")
	Trans_Add("Freenet start script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("Freenet start script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("Waiting for the Freenet background service to start...", "")
	Trans_Add("Freenet start script", "")
	Trans_Add("Freenet start script was unable to start the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("The Freenet service has been started!", "")
	Trans_Add("The Freenet service is already running!", "")
	Trans_Add("Freenet start script error", "")

	; Service stopper
	Trans_Add("Command line options (only use one):`n/silent - Hide info messsages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service stopped)`n1 - Error occurred`n2 - Service was not running (no action)", "")
	Trans_Add("Freenet stop script requires administrator privileges to stop the Freenet service. Please make sure that your user account has administrative access to the system, and the stop script is executed with access to use these privileges.", "")
	Trans_Add("Freenet stop script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet stop script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "")
	Trans_Add("Freenet stop script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("Freenet stop script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("Waiting for the Freenet background service to stop...", "")
	Trans_Add("Freenet stop script", "")
	Trans_Add("The Freenet service has been stopped!", "")
	Trans_Add("The Freenet service is already stopped!", "")
	Trans_Add("Freenet stop script was unable to stop the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "")
	Trans_Add("Freenet stop script error", "")
}

