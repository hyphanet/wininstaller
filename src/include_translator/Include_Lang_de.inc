;
; Translation file - German (de) [Sie] - by Thomas Bruderer (apophis / www.apophis.ch)
;
 
LoadLanguage_de()
{
	; Translation credit string. Remember to change language and name to your own in the translated string (not in the english one). Don't add personal comments or website links here - add those to the header of this file instead if you want.
	Trans_Add("English localization by: Christian Funder Sommerlund (Zero3)", "")

	; Shared strings (Installer, Uninstaller)
	Trans_Add("was not able to unpack necessary files to:", "")
	Trans_Add("Please make sure that this program has full access to the system's temporary files folder.", "")

	; Shared strings (Installer, Uninstaller, Service starter, Service stopper)
	Trans_Add("requires administrator privileges to manage the Freenet service. Please make sure that your user account has administrative access to the system, and this program is executed with access to use these privileges.", "")

	; Installer - Common
	Trans_Add("Freenet Installer error", "Fehler des Freenetinstallers")
	Trans_Add("Freenet Installer", "Freenetinstaller")
	Trans_Add("Welcome to the Freenet Installer!", "Willkommen zum Freenetinstaller!")
	Trans_Add("Installation Problem", "Installationsproblem")
	Trans_Add("E&xit", "&Beenden")

	; Installer - Unsupported Windows version
	Trans_Add("Freenet only supports the following versions of the Windows operating system:", "Frenet unterstützt nur die folgenden Versionen des Windows Betriebssystems:")
	Trans_Add("Please install one of these versions if you want to use Freenet on Windows.", "Bitte installieren sie eine dieser Windowsversionen wenn Sie Freenet nutzen möchten.")

	; Installer - Java missing
	Trans_Add("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:", "Freenet braucht die Java Laufzeit Umgebung, Ihr System scheint keine aktuelle Version installiert zu haben. Sie können Java mit dem enthaltenen Online-Installer, welcher die nötigen Dateien automatisch von der Java-Webseite holen wird, installieren:")
	Trans_Add("&Install Java", "&Java installieren")
	Trans_Add("The installation will continue once Java version", "")
	Trans_Add("or later has been installed.", "")

	; Installer - Old installation detected
	Trans_Add("has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:", "")
	Trans_Add("&Uninstall", "&Deinstallieren")
	Trans_Add("The installation will continue once the old installation has been removed.", "Die Installation wird fortgeführt, wenn die alte Installation entfernt wurde.")

	; Installer - Main GUI - Header
	Trans_Add("Please check the following default settings before continuing with the installation of Freenet.", "Bitte überprüfen Sie die folgenden Einstellungen bevor Sie mit der Installation fortfahren.")

	; Installer - Main GUI - Install folder
	Trans_Add("Installation directory", "Installationsverzeichnis")
	Trans_Add("&Browse", "Bro&wsen")
	Trans_Add("De&fault", "&Vorgabewert")
	Trans_Add("Freenet requires", "")
	Trans_Add("MB free disk space on the installation drive. The actual amount of space reserved to Freenet will be configured after the installation.", "")
	Trans_Add("Status:", "Status :")
	Trans_Add("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.", "Wenn Sie einen Pfad wählen der nicht 'Freenet' enthält, dann wird ein ensprechendes Verzeichnis automatisch erstellt.")
	Trans_Add("Invalid install path!", "Ungültiger Installationspfad!")
	Trans_Add("(Too long for file system to handle)", "")
	Trans_Add("Not enough free space on installation drive!", "Zu wenig Speicherplatz auf dem Installationslaufwerk!")
	Trans_Add("Freenet already installed! Please uninstall first or choose another directory!", "Freenet ist bereits installiert! Bitte erst deinstallieren oder wählen Sie ein anderes Verzeichnis.")
	Trans_Add("Installation directory OK!", "Installationsverzeichnis OK.")	
	
	; Installer - Main GUI - System service
	Trans_Add("System service", "Systemdienst")
	Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "Freenet wird automatisch im Hintergrund als Systemdienst gestartet. Dies ist nötig um einen Teil des Freenet-Netzes zu sein und wird nur einen kleinen Teil der System Resourcen benutzen. Der Anteil der genutzten Resourcen kann nach der installation angepasst werden.")
	
	; Installer - Main GUI - Additional settings
	Trans_Add("Additional settings", "Zusätzliche Einstellungen")
	Trans_Add("Start Freenet &Tray Manager on Windows startup", "")
	Trans_Add("(Recommended)", "")
	Trans_Add("Install &start menu shortcuts", "")
	Trans_Add("(Optional)", "")
	Trans_Add("Install &desktop shortcut", "")
	Trans_Add("Launch Freenet &after the installation", "Freenet &nach der installation automatisch starten")

	; Installer - Main GUI - Footer
	Trans_Add("Version ", "Version ")
	Trans_Add(" - Build ", " - Build ")
	Trans_Add("&Install", "&Installieren")
	
	; Installer - Actual installation
	Trans_Add("Opens Freenet Tray Manager in the notification area", "")
	Trans_Add("Opens the Freenet proxy homepage in a web browser", "Öffnet die Freenetproxy-Homepage in einem Internetbrowser")
	Trans_Add("Start Freenet", "Freenet starten")
	Trans_Add("Stop Freenet", "Freenet anhalten")
	Trans_Add("Installation finished successfully!", "Installation erfolgreich beended!")
	Trans_Add("Freenet Installer by:", "")
	
	; Installer - Error messageboxes
	Trans_Add("was not able to find a free port on your system in the range", "")
	Trans_Add("Please free a system port in this range to install Freenet.", "Um Freenet zu installieren öffnen Sie bitte einen Port im Bereich von ")
	Trans_Add("was not able to create a Winsock 2.0 socket for port availability testing.", "")
	Trans_Add("was not able to write to the selected installation directory. Please select one to which you have write access.", "")
	Trans_Add("Error: ", "Fehler: ")

	; Shared strings (Uninstaller, Service starter, Service stopper)
	Trans_Add("was unable to control the Freenet system service.", "")
	Trans_Add("Reason:", "")
	Trans_Add("Timeout while managing the service.", "")
	Trans_Add("Could not access the service.", "")
	Trans_Add("Service did not respond to signal.", "")
	
	; Uninstaller
	Trans_Add("Freenet uninstaller", "Freenet Deinstallieren")
	Trans_Add("was unable to recognize your Freenet installation at:", "")
	Trans_Add("Please run this program from the 'bin' folder of a Freenet installation.", "")
	Trans_Add("Do you really want to uninstall Freenet?", "")
	Trans_Add("The development team would appreciate it very much if you can spare a moment and fill out a short, anonymous online survey about the reason for your uninstallation.", "")
	Trans_Add("The survey, located on the Freenet website, will be opened in your browser after the uninstallation.", "")
	Trans_Add("Take the uninstallation survey?", "")
	Trans_Add("Stopping system service...", "Systemdienst stoppen...")
	Trans_Add("Shutting down tray managers...", "")
	Trans_Add("Removing system service...", "Systemdienst entfernen...")
	Trans_Add("Removing files...", "Dateien entfernen...")
	Trans_Add("Freenet uninstaller error", "Fehler beim deinstallieren von Freenet")
	Trans_Add("was unable to delete the Freenet files located at:", "")
	Trans_Add("Please close all applications with open files inside this directory.", "Bitte schliessen Sie alle Anwendungen mit offene Dateien innerhalb des genannten Verzeichnisses.")
	Trans_Add("The uninstallation was aborted.", "")
	Trans_Add("Please manually remove the rest of your Freenet installation.", "")
	Trans_Add("Removing registry modifications...", "Einträge in der Registry entfernen...")
	Trans_Add("Freenet has been uninstalled!", "Freenet wurde deinstalliert!")

	; Shared strings (Launcher, Tray manager)
	Trans_Add("was unable to find the following file:", "")
	Trans_Add("Make sure that you are running", "")
	Trans_Add("from a Freenet installation directory.", "")
	
	; Shared Strings (Launcher, Service starter, Service stopper, Tray manager)
	Trans_Add("If the problem keeps occurring, try reinstalling Freenet or report this error message to the developers.", "")
	
	; Launcher
	Trans_Add("Freenet Launcher", "")
	Trans_Add("Freenet Launcher error", "Freenetstarter Fehler")
	Trans_Add("was unable to read the 'fproxy.port' value from the 'freenet.ini' configuration file.", "")

	; Shared strings (Service starter, Service stopper)
	Trans_Add("Command line options (only use one):", "")
	Trans_Add("Hide info messages", "")
	Trans_Add("Hide info and status messages", "")
	Trans_Add("Return codes:", "")
	Trans_Add("Success", "")
	Trans_Add("Error occurred", "")
	Trans_Add("(no action)", "")
	
	; Service starter
	Trans_Add("(service started)", "")
	Trans_Add("Service was already running", "")
	Trans_Add("Freenet Starter", "")
	Trans_Add("The Freenet service is starting...", "")
	Trans_Add("The Freenet service has been started!", "Der Freenetdiesnt wurde gestartet")
	Trans_Add("The Freenet service is already running!", "Der Freenetdienst ist bereits am laufen!")
	Trans_Add("Freenet Starter error", "")
	
	; Service stopper
	Trans_Add("(service stopped)", "")
	Trans_Add("Service was not running", "")
	Trans_Add("Freenet Stopper", "")
	Trans_Add("The Freenet service is stopping...", "")
	Trans_Add("The Freenet service has been stopped!", "Der Freenetdienst wurde gestoppt!")
	Trans_Add("The Freenet service is already stopped!", "Der Freenetdienst wurde bereits gestoppt!")
	Trans_Add("Freenet Stopper error", "")

	; Tray manager
	Trans_Add("Freenet Tray", "")
	Trans_Add("Launch Freenet", "")
	Trans_Add("Start Freenet service", "")
	Trans_Add("Stop Freenet service", "")
	Trans_Add("Manual update check", "")
	Trans_Add("View logfile", "")
	Trans_Add("About", "")
	Trans_Add("Exit", "")
	Trans_Add("You can browse, start and stop Freenet along with other useful things from this tray icon.", "")
	Trans_Add("Doubleclick: Start/Browse Freenet", "")
	Trans_Add("Right-click: Advanced menu", "")
	Trans_Add("Warning: Using the manual update check will update Freenet and its helper tools from the official Freenet website.", "")
	Trans_Add("Freenet already has a secure built-in autoupdate feature that will keep itself up-to-date automatically.", "")
	Trans_Add("You should only use this manual update check if your installation is broken or you need updated versions of the helper tools.", "")
	Trans_Add("Freenet Windows Tray Manager", "")
}
