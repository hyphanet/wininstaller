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
	Trans_Add(" MB free. The amount of space reserved can be changed after installation.", " MB d'espace disque. La quantité d'espace réservée pourra être changée après l'installation.")
	Trans_Add("&Browse", "&Parcourir")
	Trans_Add("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.", "Si vous ne choisissez pas de dossier contenant 'Freenet' dans son nom, un dossier sera créé automatiquement pour vous.")
	Trans_Add("De&fault", "&Défaut")
	Trans_Add("Status:", "Statut :")
	Trans_Add("Invalid install path!", "Répertoire d'installation invalide !")
	Trans_Add("Invalid install path! (Too long for file system to handle)", "Répertoire d'installation invalide ! (Nom trop long)")
	Trans_Add("Not enough free space on installation drive!", "Pas assez d'espace disque disponible sur le disque dur choisi !")
	Trans_Add("Freenet already installed! Please uninstall first or choose another directory!", "Freenet est déjà installé ! Vous devez d'abord désinstaller Freenet, ou choisir un autre dossier.")
	Trans_Add("Installation directory OK!", "Répertoire d'installation OK.")

	; Installer - Main GUI - System service
	Trans_Add("System service", "Service système")
	Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "Freenet sera automatiquement lancé en arrière plan en tant que service système. Cela est nécessaire pour faire partie du réseau Freenet, et cela utilisera un petit peu de ressources système. La quantité de ressources qui sera utilisée pourra être ajustée après l'installation.")

	; Installer - Main GUI - Additional settings
	Trans_Add("Additional settings", "Paramètres supplémentaires")
	Trans_Add("Install &start menu shortcuts (All users: Browse Freenet, Start Freenet, Stop Freenet)", "Installer des raccourcis dans le menu &démarrer (Parcourir Freenet, Démarrer Freenet, Arrêter Freenet)")
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
}

