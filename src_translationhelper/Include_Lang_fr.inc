;
; Translation file - French (fr)
;

LoadLanguage_fr()
{
	; Installer - Common
	Trans_Add("Freenet Installer", "Installeur Freenet")
	Trans_Add("Freenet Installer (Beta)", "Installeur Freenet (Bêta)")
	Trans_Add("Welcome to the Freenet Installer!", "L'Installeur Freenet vous souhaite la bienvenue !")
	Trans_Add("Installation Problem", "Problème lors de l'installation")
	Trans_Add("Freenet Installer fatal error", "Erreur fatale de l'Installeur Freenet")
	Trans_Add("Freenet Installer error", "Erreur de l'Installeur Freenet")
	Trans_Add("Error: ", "Erreur : ")
	Trans_Add("E&xit", "&Quitter")

	; Installer - Error messageboxes
	Trans_Add("Freenet Installer was not able to unpack necessary installation files to:", "L'Installeur Freenet n'a pas pu décompresser les fichiers nécessaires à l'installation dans :")
	Trans_Add("Please make sure that Freenet Installer has full access to the system's temporary files folder.", "Assurez-vous que l'Installeur Freenet a les droits d'écriture dans le dossier des fichiers temporaires du système.")
	Trans_Add("Freenet Installer requires administrator privileges to install Freenet.`nPlease make sure that your user account has administrative access to the system,`nand Freenet Installer is executed with access to use these privileges.", "L'Installeur Freenet a besoin des privilèges d'Administrateur pour installer Freenet.`nAssurez-vous que votre compte utilisateur a les droits d'administration,`net que l'Installeur Freenet est exécuté avec les droits d'administration.")
	Trans_Add("Freenet Installer was not able to write to the selected installation directory.`nPlease select one to which you have write access.", "L'Installeur Freenet n'a pas pu écrire dans le dossier d'installation choisi.`nChoisissez un répertoire où vous disposez des droits d'écriture.")
	Trans_Add("Freenet Installer was not able to find a free port on your system in the range ", "L'Installeur Freenet n'a pas pu trouver un port libre dans la plage de ports ")
	Trans_Add("Please free a system port in this range to install Freenet.", "Vous devez libérer un port dans cette plage pour pouvoir installer Freenet.")
	Trans_Add("Freenet Installer was not able to create a Winsock 2.0 socket`nfor port availability testing.", "L'Installeur Freenet n'a pas pu créer un socket Winsock 2.0`npour tester la disponibilité d'un port.")

	; Installer - Unsupported Windows version
	Trans_Add("Freenet only supports the following versions of the Windows operating system:", "Freenet ne supporte que les versions suivantes du système d'exploitation Windows :")
	Trans_Add("Please install one of these versions if you want to use Freenet on Windows.", "Vous devez installer une de ces versions si vous voulez utiliser Freenet sur Windows.")

	; Installer - Java missing
	Trans_Add("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:", "Freenet a besoin d'une machine virtuelle Java, mais votre système n'a pas l'air d'en posséder une. Vous pouvez installer Java en utilisant l'installeur fourni, qui téléchargera et installera les fichiers nécessaires automatiquement :")
	Trans_Add("&Install Java", "&Installer Java")
	Trans_Add("The installation will continue once Java version ", "L'installation continuera une fois que Java version ")
	Trans_Add(" or later has been installed.", " ou ultérieur aura été installé.")

	; Installer - Old installation detected
	Trans_Add("Freenet Installer has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:", "L'Installeur Freenet a détécté une précédente installation de Freenet sur votre système. Votre installation actuelle de Freenet a été installée en utilisant une version plus ancienne et non supportée de l'installeur Freenet. Pour continuer, vous devez tout d'abord désinstaller votre version actuelle de Freenet en utilisant le programme de désinstallation créé précédemment :")
	Trans_Add("&Uninstall", "&Désinstaller")
	Trans_Add("The installation will continue once the old installation has been removed.", "L'installation continuera une fois que l'ancienne installation aura été supprimée.")

	; Installer - Main GUI - Header
	Trans_Add("Please check the following default settings before continuing with the installation of Freenet.", "Vérifiez les paramètres par défaut suivants avant de continuer l'installation de Freenet.")

	; Installer - Main GUI - Install folder
	Trans_Add("Installation directory", "Répertoire d'installation")
	Trans_Add("Freenet requires at least ", "Freenet a besoin au minimum de ")
	Trans_Add(" MB free disk space, but will not install with less than ", " MB d'espace disque, mais l'installation ne se fera pas sans au moins ")
	Trans_Add(" MB free. The amount of space reserved can be changed after installation.", " MB d'espace disque (modifiable ultérieurement).")
	Trans_Add("&Browse", "&Parcourir")
	Trans_Add("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.", "Si vous ne choisissez pas de dossier contenant 'Freenet' dans son nom, un dossier sera créé automatiquement pour vous.")
	Trans_Add("De&fault", "&Défaut")
	Trans_Add("Status:", "Statut :")
	Trans_Add("Invalid install path!", "Répertoire d'installation invalide !")
	Trans_Add("Invalid install path! (Too long for file system to handle)", "Répertoire d'installation invalide ! (Nom trop long)")
	Trans_Add("Not enough free space on installation drive!", "Pas assez d'espace disque disponible sur le disque dur choisi !")
	Trans_Add("Freenet already installed! Please uninstall first or choose another directory!", "Freenet est déjà installé ! Désinstallez Freenet ou choisissez un autre dossier.")
	Trans_Add("Installation directory OK!", "Répertoire d'installation OK.")

	; Installer - Main GUI - System service
	Trans_Add("System service", "Service système")
	Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "Freenet sera automatiquement lancé en arrière plan en tant que service système. Cela est nécessaire pour faire partie du réseau Freenet, et cela utilisera un petit peu de ressources système. La quantité de ressources qui sera utilisée pourra être ajustée après l'installation.")

	; Installer - Main GUI - Additional settings
	Trans_Add("Additional settings", "Paramètres supplémentaires")
	Trans_Add("Install &start menu shortcuts (All users: Browse Freenet, Start Freenet, Stop Freenet)", "Installer des raccourcis dans le menu &démarrer (Parcourir, Démarrer, Arrêter Freenet)")
	Trans_Add("Install &desktop shortcut (All users: Browse Freenet)", "Installer un raccourci sur le &bureau (Parcourir Freenet)")
	Trans_Add("Browse Freenet &after the installation", "Commencer à parcourir Freenet &après l'installation")

	; Installer - Main GUI - Footer
	Trans_Add("Version ", "Version ")
	Trans_Add(" - Build ", " - Build ")
	Trans_Add("&Install", "&Installeur")

	; Installer - Actual installation
	Trans_Add("Freenet Background Service", "Service Freenet (arrière plan)")
	Trans_Add("Browse Freenet", "Parcourir Freenet") ; Shortcut name
	Trans_Add("Opens the Freenet proxy homepage in a web browser", "Ouvre la page d'accueil du proxy Freenet dans un navigateur internet")
	Trans_Add("Start Freenet", "Démarrer Freenet") ; Shortcut name
	Trans_Add("Starts the background service needed to use Freenet", "Démarre le service d'arrière plan nécessaire pour utiliser Freenet.")
	Trans_Add("Stop Freenet", "Arrêter Freenet") ; Shortcut name
	Trans_Add("Stops the background service needed to use Freenet", "Arrête le service d'arrière plan nécessaire pour utiliser Freenet.")
	Trans_Add("Installation finished successfully!", "L'installation s'est terminée avec succès !")

;	; Uninstaller - Common
;	Trans_Add("Freenet uninstaller", "Freenet afinstallationsprogram")
;	Trans_Add("Freenet uninstaller error", "Freenet afinstallationsprogram fejl")
;
;	; Uninstaller - General
;	Trans_Add("Freenet has been uninstalled!", "Freenet er blevet afinstalleret!")
;	Trans_Add("Do you really want to uninstall", "Vil du virkelig afinstallere")
;	Trans_Add("The development team would appreciate it very much if you can`nspare a moment and fill out a short, anonymous online`nsurvey about the reason for your uninstallation.`n`nThe survey, located on the Freenet website, will be opened`nin your browser after the uninstallation.`n`nTake the uninstallation survey?", "Udviklingsholdet vil sætte stor pris på hvis du kan undvære et`npar minutter, og udfylde et kort, anonymt, online spørgsskema`nomkring grunden til at du afinstallerer Freenet.`n`nSpørgeskemaet, placeret på Freenets hjemmeside, vil blive`nåbnet i din browser efter afinstallationen.`n`nUdfyld spørgeskemaet?")
;
;	; Uninstaller - Error messageboxes
;	Trans_Add("The uninstaller requires administrator privileges to uninstall Freenet. Please make sure that your user account has administrative access to the system, and the uninstaller is executed with access to use these privileges.", "Afinstallationsprogrammet kræver administratorrettigheder for at afinstallere Freenet. Kontrollér at din brugerkonto har administrativ adgang til systemet, og at afinstallationsprogrammet køres med adgang til at udnytte disse rettigheder.")
;	Trans_Add("The uninstaller was not able to unpack necessary files to:", "Afinstallationsprogrammet kunne ikke udpakke nødvendige filer til:")
;	Trans_Add("Please make sure that the uninstaller has full access to the system's temporary files folder.", "Kontrollér at afinstallationsprogrammet har ubegrænset adgang til systemets mappe til midlertidige filer.")
;	Trans_Add("The uninstaller was unable to recognize your Freenet installation at:", "Afinstallationsprogrammet kunne ikke genkende din Freenet-installation i:")
;	Trans_Add("Please run this uninstaller from the 'bin' folder of a Freenet installation.", "Kør venligst dette afinstallationsprogram fra 'bin'-mappen af en Freenet-installation.")
;
;	; Uninstaller - Service problems
;	Trans_Add("The uninstaller was unable to control the Freenet system service as it appears to be stuck.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Afinstallationsprogrammet kunne ikke styre Freenet-systemtjenesten da den tilsyneladende har sat sig fast.`n`nPrøv igen.`n`nHvis problemet fortsætter så indrapporter venligst denne fejlbesked til udviklerne.")
;	Trans_Add("The uninstaller was unable to find and control the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Afinstallationsprogrammet kunne ikke finde og styre Freenet-systemtjenesten.`n`nPrøv igen.`n`nHvis problemet fortsætter så indrapporter venligst denne fejlbesked til udviklerne.")
;	Trans_Add("The uninstaller was unable to stop the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Afinstallationsprogrammet kunne ikke stoppe Freenet-systemtjenesten.`n`nPrøv igen.`n`nHvis problemet fortsætter så indrapporter venligst denne fejlbesked til udviklerne.")
;
;	; Uninstaller - Files undeletable
;	Trans_Add("The uninstaller was unable to delete the Freenet files located at:", "Afinstallationsprogrammet kunne ikke slette Freenet-filerne placeret i:")
;	Trans_Add("Please close all applications with open files inside this directory.", "Luk venligst alle programmer med åbne filer inden i denne mappe.")
;	Trans_Add("The uninstallation was aborted.`n`nPlease manually remove the rest of your Freenet installation.", "Afinstallationen blev afbrudt.`n`nDu bliver nødt til manuelt at fjerne resten af din Freenet-installation.")
;
;	; Uninstaller - Progress statuses
;	Trans_Add("Stopping system service...", "Stopper systemtjeneste...")
;	Trans_Add("Removing system service...", "Fjerner systemtjeneste...")
;	Trans_Add("Removing custom user account rights...", "Fjerner specielle kontorettigheder...")
;	Trans_Add("Removing files...", "Fjerner filer...")
;	Trans_Add("Removing registry modifications...", "Fjerner registreringsdatabaseændringer...")
;	Trans_Add("Removing custom user...", "Fjerner speciel bruger...")
;
;	; Launcher
;	Trans_Add("Freenet Launcher error", "Freenet Starter fejl")
;	Trans_Add("Freenet Launcher was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Freenet Starter kunne ikke finde installid.dat ID-filen.`n`nKontrollér at du kører Freenet Starter fra en Freenet-installationsmappe.`nHvis du allerede gør dette, så indrapporter venligst denne fejlbesked til udviklerne.")
;	Trans_Add("Freenet Launcher was unable to find the bin\start.exe launcher.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet Starter kunne ikke finde bin\start.exe startfilen.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
;	Trans_Add("Freenet Launcher was unable to find the freenet.ini configuration file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Freenet Starter kunne ikke finde freenet.ini konfigurationsfilen.`n`nKontrollér at du kører Freenet Starter fra en Freenet-installationsmappe.`nHvis du allerede gør dette, så indrapporter venligst denne fejlbesked til udviklerne.")
;	Trans_Add("Freenet Launcher was unable to read the 'fproxy.port' value from the freenet.ini configuration file.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet Starter kunne ikke læse 'fproxy.port' værdien fra freenet.ini konfigurationsfilen.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
;	Trans_Add("Freenet Launcher was unable to find a supported browser.`n`nPlease install one of the supported browsers, or manually`nnavigate to: ", "Freenet Starter kunne ikke finde en understøttet browser.`n`nInstaller en af de understøttede browsere, eller naviger`nmanuelt til: ")
;	Trans_Add("Freenet Launcher supports the following browsers:", "Freenet Starter understøtter følgende browsere:")
;	Trans_Add("not recommended", "ikke anbefalet")
}

