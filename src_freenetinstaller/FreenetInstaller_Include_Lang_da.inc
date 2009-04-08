;
; Windows Freenet Installer - Include file - Localization - Danish (da)
;

LoadLanguage_da()
{
	; Common
	Trans_Add("Freenet Installer", "Freenet Installer")
	Trans_Add("Freenet Installer (Beta)", "Freenet Installer (Beta)")
	Trans_Add("Welcome to the Freenet Installer!", "Velkommen til Freenet Installer!")
	Trans_Add("Installation Problem", "Installationsproblem")
	Trans_Add("Freenet Installer fatal error", "Freenet Installer fatal fejl")
	Trans_Add("Freenet Installer error", "Freenet Installer fejl")
	Trans_Add("Error: ", "Fejl: ")
	Trans_Add("E&xit", "&Afslut")

	; Error messageboxes
	Trans_Add("Freenet Installer was not able to unpack necessary installation files to:", "Freenet Installer kunne ikke udpakke nødvendige installationsfiler til:")
	Trans_Add("Please make sure that Freenet Installer has full access to the system's temporary files folder.", "Kontrollér at Freenet Installer har ubegrænset adgang til systemets mappe til midlertidige filer.")
	Trans_Add("Freenet Installer requires administrator privileges to install Freenet.`nPlease make sure that your user account has administrative access to the system,`nand Freenet Installer is executed with access to use these privileges.", "Freenet Installer kræver administratorrettigheder for at installere Freenet.`nKontrollér at din brugerkonto har administrativ adgang til systemet,`nog at Freenet Installer køres med adgang til at udnytte disse rettigheder.")
	Trans_Add("Freenet Installer was not able to write to the selected installation directory.`nPlease select one to which you have write access.", "Freenet Installer kunne ikke skrive til den valgte installationsmappe.`nVælg venligst en mappe du har skriveadgang til.")
	Trans_Add("Freenet Installer was not able to find a free port on your system in the range ", "Freenet Installer kunne ikke finde en fri port på dit system i intervallet ")
	Trans_Add("Please free a system port in this range to install Freenet.", "For at installere Freenet er du nødt til at frigøre en port i dette interval.")
	Trans_Add("Freenet Installer was not able to create a Winsock 2.0 socket`nfor port availability testing.", "Freenet Installer kunne ikke oprette en Winsock 2.0-sokkel`ntil porttestning.")

	; Unsupported Windows version
	Trans_Add("Freenet only supports the following versions of the Windows operating system:", "Freenet understøtter kun følgende versioner af Windows-operativsystemet:")
	Trans_Add("Please install one of these versions if you want to use Freenet on Windows.", "Hvis du vil bruge Freenet er du nødt til at installere en af disse versioner.")

	; Java missing
	Trans_Add("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:", "Freenet kræver Java Runtime Environment, men dit system har tilsyneladende ikke en opdateret version installeret. Du kan installere Java ved hjælp af den inkluderede online-installer som automatisk vil downloade og installere filerne fra Javas hjemmeside:")
	Trans_Add("&Install Java", "&Installer Java")
	Trans_Add("The installation will continue once Java version ", "Installationen vil fortsætte når Java version ")
	Trans_Add(" or later has been installed.", " eller nyere er blevet installeret.")

	; Old installation detected
	Trans_Add("Freenet Installer has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:", "Freenet Installer har opdaget at Freenet allerede er installeret, men af et ældre, ikke længere understøttet, installationsprogram. For at fortsætte skal du først afinstallere din nuværende version ved hjælp af det tidligere oprettede afinstallationsprogram:")
	Trans_Add("&Uninstall", "A&finstaller")
	Trans_Add("The installation will continue once the old installation has been removed.", "Installationen vil fortsætte når den tidligere installation er blevet fjernet.")

	; Main GUI - Header
	Trans_Add("Please check the following default settings before continuing with the installation of Freenet.", "Kontrollér nedenstående standardindstillinger før du fortsætter med installationen af Freenet.")

	; Main GUI - Install folder
	Trans_Add("Installation directory", "Installationsmappe")
	Trans_Add("Freenet requires at least ", "Freenet kræver mindst ")
	Trans_Add(" MB free disk space, but will not install with less than ", " MB fri diskplads, men vil ikke installere med mindre end ")
	Trans_Add(" MB free. The amount of space reserved can be changed after installation.", " MB fri. Mængden af reserveret diskplads kan justeres efter installationen.")
	Trans_Add("&Browse", "&Gennemse")
	Trans_Add("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.", "Hvis du ikke vælger en mappe der indeholder 'Freenet' i stien vil en mappe automatisk blive oprettet for dig.")
	Trans_Add("De&fault", "&Standard")
	Trans_Add("Status:", "Status:")
	Trans_Add("Invalid install path!", "Ugyldig installationssti!")
	Trans_Add("Invalid install path! (Too long for file system to handle)", "Ugyldig installationssti! (For lang til filsystemet)")
	Trans_Add("Not enough free space on installation drive!", "Ikke nok fri plads på installationsdrevet!")
	Trans_Add("Freenet already installed! Please uninstall first or choose another directory!", "Freenet allerede installeret! Afinstaller først eller vælg en anden mappe!")
	Trans_Add("Installation directory OK!", "Installationsmappe OK!")

	; Main GUI - System service
	Trans_Add("System service", "Systemtjeneste")
	Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "Freenet vil automatisk starte i baggrunden som en systemtjeneste. Denne er nødvendigt for at være en del af Freenet-netværket, og vil bruge en lille andel systemresurser. Mængden af resurser kan justeres efter installationen.")

	; Main GUI - Additional settings
	Trans_Add("Additional settings", "Yderligere indstillinger")
	Trans_Add("Install &start menu shortcuts (All users: Browse Freenet, Start Freenet, Stop Freenet)", "Installer start&menugenveje (Alle brugere: Åbn Freenet, Start Freenet, Stop Freenet)")
	Trans_Add("Install &desktop shortcut (All users: Browse Freenet)", "Installer s&krivebordsgenvej (Alle brugere: Åbn Freenet)")
	Trans_Add("Browse Freenet &after the installation", "Åbn Freenet &efter installationen")

	; Main GUI - Footer
	Trans_Add("Version ", "Version ")
	Trans_Add(" - Build ", " - Build ")
	Trans_Add("&Install", "&Installer")

	; Installation itself
	Trans_Add("Freenet Background Service", "Freenet baggrundstjeneste")
	Trans_Add("Browse Freenet", "Åbn Freenet") ; Shortcut name
	Trans_Add("Opens the Freenet proxy homepage in a web browser", "Åbner Freenet-proxyen i en webbrowser")
	Trans_Add("Start Freenet", "Start Freenet") ; Shortcut name
	Trans_Add("Starts the background service needed to use Freenet", "Starter baggrundstjenesten krævet for at bruge Freenet")
	Trans_Add("Stop Freenet", "Stop Freenet") ; Shortcut name
	Trans_Add("Stops the background service needed to use Freenet", "Stopper baggrundstjenesten krævet for at bruge Freenet")
	Trans_Add("Installation finished successfully!", "Installationen gennemført med succes!")
}

