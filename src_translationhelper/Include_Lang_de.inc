;
; Translation file - German (de) [Sie] - by Thomas Bruderer (apophis / www.apophis.ch)
;
 
LoadLanguage_de()
{
	; Installer - Common
	Trans_Add("Freenet Installer", "Freenetinstaller")
	Trans_Add("Welcome to the Freenet Installer!", "Willkommen zum Freenetinstaller!")
	Trans_Add("Installation Problem", "Installationsproblem")
	Trans_Add("Freenet Installer fatal error", "Fataler Fehler im Freenetinstaller")
	Trans_Add("Freenet Installer error", "Fehler des Freenetinstallers")
	Trans_Add("Error: ", "Fehler: ")
	Trans_Add("E&xit", "&Beenden")
 
	; Installer - Error messageboxes
	Trans_Add("Freenet Installer was not able to unpack necessary installation files to:", "Der Freenetinstaller konnte die nötigen Dateien nicht installieren:")
	Trans_Add("Please make sure that Freenet Installer has full access to the system's temporary files folder.", "Vergewissern sie sich, dass der Freenetinstaller die nötigen Rechte hat um Vollzugriff auf die temporären Dateien Ihres systems zu erhalten.")
	Trans_Add("Freenet Installer requires administrator privileges to install Freenet.`nPlease make sure that your user account has administrative access to the system,`nand Freenet Installer is executed with access to use these privileges.", "Der Freenetinstaller benötigt Administrator Privilegien um Freenet zu installieren. `nBitte vergewissern Sie sich, dass Ihr Benutzeraccount die nötigen Rechte hat, `nund dass der Freenetinstaller mit den nötigen Rechten gestartet wurde.")
	Trans_Add("Freenet Installer was not able to write to the selected installation directory.`nPlease select one to which you have write access.", "Der Freenetinstaller konnte nicht ins ausgewählte Verzeichnis schreiben.`nBitte wählen Sie ein Verzeichnis aus in welchem Sie Schreibrechte besitzen.")
	Trans_Add("Freenet Installer was not able to find a free port on your system in the range ", "Der Freenetinstaller hat keinen freien Port in Ihrem System gefunden im Bereich von ")
	Trans_Add("Please free a system port in this range to install Freenet.", "Um Freenet zu installieren öffnen Sie bitte einen Port im Bereich von ")
	Trans_Add("Freenet Installer was not able to create a Winsock 2.0 socket`nfor port availability testing.", "Der Freenetinstaller war nicht in der Lage einen Winsock 2.0 Port zu erstellen um die Portverfügbarkeit zu überprüfen.")
 
	; Installer - Unsupported Windows version
	Trans_Add("Freenet only supports the following versions of the Windows operating system:", "Frenet unterstützt nur die folgenden Versionen des Windows Betriebssystems:")
	Trans_Add("Please install one of these versions if you want to use Freenet on Windows.", "Bitte installieren sie eine dieser Windowsversionen wenn Sie Freenet nutzen möchten.")
 
	; Installer - Java missing
	Trans_Add("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:", "Freenet braucht die Java Laufzeit Umgebung, Ihr System scheint keine aktuelle Version installiert zu haben. Sie können Java mit dem enthaltenen Online-Installer, welcher die nötigen Dateien automatisch von der Java-Webseite holen wird, installieren:")
	Trans_Add("&Install Java", "&Java installieren")
	Trans_Add("The installation will continue once Java version ", "Die installation wird fortgeführt wenn die Java-Version ")
	Trans_Add(" or later has been installed.", " oder höher installiert wurde.")
 
	; Installer - Old installation detected
	Trans_Add("Freenet Installer has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:", "Der Installer hat entdeckt, dass Freenet bereits installiert ist. Ihre aktuelle Installation wurde mit einem älteren, nicht mehr unterstützten, Installer gemacht. Um forzufahren müssen sie zunächst Ihre aktuelle Installation mit dem früher erstellten Uninstaller entfernen:")
	Trans_Add("&Uninstall", "&Deinstallieren")
	Trans_Add("The installation will continue once the old installation has been removed.", "Die Installation wird fortgeführt, wenn die alte Installation entfernt wurde.")
 
	; Installer - Main GUI - Header
	Trans_Add("Please check the following default settings before continuing with the installation of Freenet.", "Bitte überprüfen Sie die folgenden Einstellungen bevor Sie mit der Installation fortfahren.")
 
	; Installer - Main GUI - Install folder
	Trans_Add("Installation directory", "Installationsverzeichnis")
	Trans_Add("Freenet requires at least ", "Freenet braucht mindestens ")
	Trans_Add(" MB free disk space, but will not install with less than ", " MB freier Speicher, aber wird nicht installiert mit weniger als ")
	Trans_Add(" MB free. The amount of space reserved can be changed after installation.", " MB Speicher. (Dies kann nach der Installation geändert werden).")
	Trans_Add("&Browse", "Bro&wsen")
	Trans_Add("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.", "Wenn Sie einen Pfad wählen der nicht 'Freenet' enthält, dann wird ein ensprechendes Verzeichnis automatisch erstellt.")
	Trans_Add("De&fault", "&Vorgabewert")
	Trans_Add("Status:", "Status :")
	Trans_Add("Invalid install path!", "Ungültiger Installationspfad!")
	Trans_Add("Invalid install path! (Too long for file system to handle)", "Ungültiger Installationspfad! (Pfadname zu lange für das Dateisystem)")
	Trans_Add("Not enough free space on installation drive!", "Zu wenig Speicherplatz auf dem Installationslaufwerk!")
	Trans_Add("Freenet already installed! Please uninstall first or choose another directory!", "Freenet ist bereits installiert! Bitte erst deinstallieren oder wählen Sie ein anderes Verzeichnis.")
	Trans_Add("Installation directory OK!", "Installationsverzeichnis OK.")
 
	; Installer - Main GUI - System service
	Trans_Add("System service", "Systemdienst")
	Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "Freenet wird automatisch im Hintergrund als Systemdienst gestartet. Dies ist nötig um einen Teil des Freenet-Netzes zu sein und wird nur einen kleinen Teil der System Resourcen benutzen. Der Anteil der genutzten Resourcen kann nach der installation angepasst werden.")
 
	; Installer - Main GUI - Additional settings
	Trans_Add("Additional settings", "Zusätzliche Einstellungen")
	Trans_Add("Install &start menu shortcuts (Freenet, Start Freenet, Stop Freenet)", "&Startmenu Shortcuts installieren (Freenet, Start Freenet, Stop Freenet)")
	Trans_Add("Install &desktop shortcut (Freenet)", "D&esktop Shortcuts installieren (Freenet)")
	Trans_Add("Launch Freenet &after the installation", "Freenet &nach der installation automatisch starten")
 
	; Installer - Main GUI - Footer
	Trans_Add("Version ", "Version ")
	Trans_Add(" - Build ", " - Build ")
	Trans_Add("&Install", "&Installieren")
 
	; Installer - Actual installation
	Trans_Add("Opens the Freenet proxy homepage in a web browser", "Öffnet die Freenetproxy-Homepage in einem Internetbrowser")
	Trans_Add("Start Freenet", "Freenet starten") ; Shortcut name
	Trans_Add("Starts the background service needed to use Freenet", "Startet den Hintergrunddienst um Freenet zu nutzen.")
	Trans_Add("Stop Freenet", "Freenet anhalten") ; Shortcut name
	Trans_Add("Stops the background service needed to use Freenet", "Hält den Hintergrunddienst an, der nötig ist um Freenet zu nutzen")
	Trans_Add("Installation finished successfully!", "Installation erfolgreich beended!")
 
	; Uninstaller - Common
	Trans_Add("Freenet uninstaller", "Freenet Deinstallieren")
	Trans_Add("Freenet uninstaller error", "Fehler beim deinstallieren von Freenet")
 
	; Uninstaller - General
	Trans_Add("Freenet has been uninstalled!", "Freenet wurde deinstalliert!")
	Trans_Add("Do you really want to uninstall", "Möchten Sie Freenet wirklich deinstallieren")
	Trans_Add("The development team would appreciate it very much if you can`nspare a moment and fill out a short, anonymous online`nsurvey about the reason for your uninstallation.`n`nThe survey, located on the Freenet website, will be opened`nin your browser after the uninstallation.`n`nTake the uninstallation survey?", "Das Entwicklerteam würde es sehr begrüssen wenn Sie einen Moment Zeit erübrigen könnten um einen anonyme Onlineumfrage über den Grund der Deinstallation auszufüllen.`n`n Die Umfrage ist auf der Freenetwebseite und wird nach der Deinstallation in Ihrem Internetbrowser geöffnet werden.")
 
	; Uninstaller - Error messageboxes
	Trans_Add("The uninstaller requires administrator privileges to uninstall Freenet. Please make sure that your user account has administrative access to the system, and the uninstaller is executed with access to use these privileges.", "Der Deinstaller braucht Administrator Privilegien um Freenet zu entfernen. Bitte vergewissern Sie sich, dass Ihr Benutzeraccount Administratorzugriff auf das System hat und dass der Uninstaller mit den nötigen Rechten gestartet wurde.")
	Trans_Add("The uninstaller was not able to unpack necessary files to:", "Der Deinstaller war nicht in der Lage benötigte Dateien zu entpacken nach :")
	Trans_Add("Please make sure that the uninstaller has full access to the system's temporary files folder.", "Bitte vergewissern	Sie sich, dass der Deinstaller volle Zugriffsrechte auf den temporären Ordner Ihres Betriebssystems hat.")
	Trans_Add("The uninstaller was unable to recognize your Freenet installation at:", "Der Deinstaller war nicht in der Lage Ihre Freenetinstallation zu finden in:")
	Trans_Add("Please run this uninstaller from the 'bin' folder of a Freenet installation.", "Bitte starten Sie den Deinstaller aus dem 'bin'-Verzeichnisses Ihrer Freenetinstallation.")
 
	; Uninstaller - Service problems
	Trans_Add("The uninstaller was unable to control the Freenet system service as it appears to be stuck.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Der Deinstaller war nicht in der Lage Ihren Freenet Systemdienst zu kontrollieren, er scheint fest zu stecken. `n`nBitte Versuchen Sie es erneut.`nFalls das Problem weiterhin besteht, bitte melden Sie diese Fehlermeldung den Entwicklern.")
	Trans_Add("The uninstaller was unable to find and control the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Der Deinstaller war nicht in der Lage den Freenet Systemdienst zu finden und zu kontrollieren. `n`nBitte Versuchen Sie es erneut.`nFalls das Problem weiterhin besteht, bitte melden Sie diese Fehlermeldung den Entwicklern.")
	Trans_Add("The uninstaller was unable to stop the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Der Deinstaller war nicht in der Lage den Freenet Systemdienst zu stoppen. `n`nBitte Versuchen Sie es erneut.`nFalls das Problem weiterhin besteht, bitte melden Sie diese Fehlermeldung den Entwicklern")
 
	; Uninstaller - Files undeletable
	Trans_Add("The uninstaller was unable to delete the Freenet files located at:", "Der Deinstaller war nicht in der Lage die Freenet Dateien in folgendem Verzeichnis zu löschen:")
	Trans_Add("Please close all applications with open files inside this directory.", "Bitte schliessen Sie alle Anwendungen mit offene Dateien innerhalb des genannten Verzeichnisses.")
	Trans_Add("The uninstallation was aborted.`n`nPlease manually remove the rest of your Freenet installation.", "Die Deinstallation wurde abgebrochen. `nBitte entfernen Sie den Rest der Freenetinstallation von Hand.")
 
	; Uninstaller - Progress statuses
	Trans_Add("Stopping system service...", "Systemdienst stoppen...")
	Trans_Add("Removing system service...", "Systemdienst entfernen...")
	Trans_Add("Removing custom user account rights...", "Besondere Rechte des Benutzers entfernen...")
	Trans_Add("Removing files...", "Dateien entfernen...")
	Trans_Add("Removing registry modifications...", "Einträge in der Registry entfernen...")
	Trans_Add("Removing custom user...", "Benutzeraccount entfernen...")
 
	; Launcher
	Trans_Add("Freenet Launcher error", "Freenetstarter Fehler")
	Trans_Add("Freenet Launcher was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Der Freenetstarter war nicht in der Lage die installid.dat ID Datei zu finden.`n`n Vergewissern Sie sich, dass Sie den Freenetstarter aus dem Freenetinstallationsverzeichnis aufrufen. `nWenn Sie dies bereits gemacht haben bitten wir Sie diese Fehlermeldung den Entwicklern zu melden.")
	Trans_Add("Freenet Launcher was unable to find the bin\start.exe launcher.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Der Freenetstarter war nicht in der Lage den bin\start.exe Starter zu finden. `n`nBitte installieren Sie Freenet neu.`n`n Wenn das Problem weiterhin auftritt bitten wir Sie diese Fehlermeldung den Entwicklern zu melden.")
	Trans_Add("Freenet Launcher was unable to find the freenet.ini configuration file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Der Freenetstarter war nicht in der Lage die Datei freenet.ini zu finden.`n`n Vergewissern Sie sich, dass Sie den Freenetstarter aus dem Freenetinstallationsverzeichnis aufrufen. `n`nWenn Sie dies bereits gemacht haben bitten wir Sie diese Fehlermeldung den Entwicklern zu melden.")
	Trans_Add("Freenet Launcher was unable to read the 'fproxy.port' value from the freenet.ini configuration file.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Der Freenetstarter war nicht in der Lage den Wert für 'fproxy.port' in der freenet.ini zu lesen. `n`nBitte installieren Sie Freenet neu. `n`nWenn das Problem weiterhin auftritt bitten wir Sie diese Fehlermeldung den Entwicklern zu melden.")
	Trans_Add("Freenet Launcher was unable to find a supported browser.`n`nPlease install one of the supported browsers, or manually`nnavigate to: ", "Der Freenetstarter war nicht in der Lage einen unterstützten Internetbrowser zu finden.`n`nBitte installieren Sie einen unterstützen Internetbrowser oder geben Sie von Hand folgende Adresse ein:")
	Trans_Add("Freenet Launcher supports the following browsers:", "Der Freenetstarter unterstützt folgende Internetbrowser:")
	Trans_Add("not recommended", "nicht empfohlen")

	; Service starter
	Trans_Add("Command line options (only use one):`n/silent - Hide info messages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service started)`n1 - Error occurred`n2 - Service was already running (no action)", "Kommandzeilenparameter (nur einen angeben):`n/silent - Keine Infomeldungen:`n/verysilent - Keine Info- oder Statusmeldungen`n`nRückgabewerte:`n0 - Erfolgreich (gestartet)`n1 - Fehler beim starten`n2 - Dienst läuft bereits")
	Trans_Add("Freenet start script requires administrator privileges to start the Freenet service. Please make sure that your user account has administrative access to the system, and the start script is executed with access to use these privileges.", "Das Freenetstartscript benötigt Administrator Privilegien um den Systemdienst zu starten. Bitte vergewissern Sie sich, dass Ihr Benutzeraccount die nötigen Rechte hat, und dass das Script mit den nötigen Rechten gestartet wurde.")
	Trans_Add("Freenet start script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet start script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "Das Freenetstartscript war nicht in der Lage die installid.dat ID Datei zu finden.`n`n Vergewissern Sie sich, dass Sie das Freenetstartscript aus dem 'bin' Verzeichnis von Freenetaufrufen. `nWenn Sie dies bereits gemacht haben bitten wir Sie diese Fehlermeldung den Entwicklern zu melden.")
	Trans_Add("Freenet start script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Das Freenetstartscript war nicht in der Lage Ihren Freenet Systemdienst zu kontrollieren, er scheint fest zu stecken.`n`nBitte installieren Sie Freenet neu.`nFalls das Problem weiterhin besteht, bitte melden Sie diese Fehlermeldung den Entwicklern.")
	Trans_Add("Freenet start script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Das Freenetstartscript war nicht in der Lage den Freenet Systemdienst zu finden und zu kontrollieren. `n`nBitte installieren Sie Freenet neu.`n`nFalls das Problem weiterhin besteht, bitte melden Sie diese Fehlermeldung den Entwicklern.")
	Trans_Add("Waiting for the Freenet background service to start...", "Wir warten bis der Freenethintergrunddienst gestartet wurde...")
	Trans_Add("Freenet start script", "Freenetstartscript")
	Trans_Add("Freenet start script was unable to start the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Das Freenetstartscript war nicht in der Lage den Freenetsystemdienst zu starten.`n`nBitte installieren Sie Freenet neu.`n`n Wenn das Problem weiterhin auftritt bitten wir Sie diese Fehlermeldung den Entwicklern zu melden.")
	Trans_Add("The Freenet service has been started!", "Der Freenetdiesnt wurde gestartet")
	Trans_Add("The Freenet service is already running!", "Der Freenetdienst ist bereits am laufen!")
	Trans_Add("Freenet start script error", "Fehler im Freenetstartscript")

	; Service stopper
	Trans_Add("Command line options (only use one):`n/silent - Hide info messages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service stopped)`n1 - Error occurred`n2 - Service was not running (no action)", "Kommandzeilenparameter (nur einen angeben):`n/silent - Keine Infomeldungen:`n/verysilent - Keine Info- oder Statusmeldungen`n`nRückgabewerte:`n0 - Erfolgreich (gestoppt)`n1 - Fehler beim stoppen`n2 - Dienst bereits beendet")
	Trans_Add("Freenet stop script requires administrator privileges to stop the Freenet service. Please make sure that your user account has administrative access to the system, and the stop script is executed with access to use these privileges.", "Das Freenetstopscript benötigt Administrator Privilegien um den Systemdienst zu starten. Bitte vergewissern Sie sich, dass Ihr Benutzeraccount die nötigen Rechte hat, und dass das Script mit den nötigen Rechten gestartet wurde.")
	Trans_Add("Freenet stop script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet stop script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "Das Freenetstopscript war nicht in der Lage die installid.dat ID Datei zu finden.`n`n Vergewissern Sie sich, dass Sie das Freenetstopscript aus dem 'bin' Verzeichnis von Freenetaufrufen.`n`nWenn Sie dies bereits gemacht haben bitten wir Sie diese Fehlermeldung den Entwicklern zu melden.")
	Trans_Add("Freenet stop script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Das Freenetstopscript war nicht in der Lage Ihren Freenet Systemdienst zu kontrollieren, er scheint fest zu stecken.`n`nBitte installieren Sie Freenet neu.`nFalls das Problem weiterhin besteht, bitte melden Sie diese Fehlermeldung den Entwicklern.")
	Trans_Add("Freenet stop script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Das Freenetstopscript war nicht in der Lage den Freenet Systemdienst zu finden und zu kontrollieren. `n`nBitte installieren Sie Freenet neu.`n`nFalls das Problem weiterhin besteht, bitte melden Sie diese Fehlermeldung den Entwicklern.")
	Trans_Add("Waiting for the Freenet background service to stop...", "Wir warten bis der Freenethintergrunddienst gestopppt wurde...")
	Trans_Add("Freenet stop script", "Freenetstopscript")
	Trans_Add("The Freenet service has been stopped!", "Der Freenetdienst wurde gestoppt!")
	Trans_Add("The Freenet service is already stopped!", "Der Freenetdienst wurde bereits gestoppt!")
	Trans_Add("Freenet stop script was unable to stop the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Das Freenetstopscript war nicht in der Lage den Freenetsystemdienst zu stoppen.`n`nBitte installieren Sie Freenet neu.`n`n Wenn das Problem weiterhin auftritt bitten wir Sie diese Fehlermeldung den Entwicklern zu melden.")
	Trans_Add("Freenet stop script error", "Fehler im Freenetstopscript")
}

