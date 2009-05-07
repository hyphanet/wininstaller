;
; Translation file - Danish (da) - by Zero3 (zero3 that-a-thingy zero3 that-dot-thingy dk)
;

LoadLanguage_da()
{
	; Installer - Common
	Trans_Add("Freenet Installer", "Freenet Installer")
	Trans_Add("Welcome to the Freenet Installer!", "Velkommen til Freenet Installer!")
	Trans_Add("Installation Problem", "Installationsproblem")
	Trans_Add("Freenet Installer fatal error", "Freenet Installer fatal fejl")
	Trans_Add("Freenet Installer error", "Freenet Installer fejl")
	Trans_Add("Error: ", "Fejl: ")
	Trans_Add("E&xit", "&Afslut")

	; Installer - Error messageboxes
	Trans_Add("Freenet Installer was not able to unpack necessary installation files to:", "Freenet Installer kunne ikke udpakke nødvendige installationsfiler til:")
	Trans_Add("Please make sure that Freenet Installer has full access to the system's temporary files folder.", "Kontrollér at Freenet Installer har ubegrænset adgang til systemets mappe til midlertidige filer.")
	Trans_Add("Freenet Installer requires administrator privileges to install Freenet.`nPlease make sure that your user account has administrative access to the system,`nand Freenet Installer is executed with access to use these privileges.", "Freenet Installer kræver administratorrettigheder for at installere Freenet.`nKontrollér at din brugerkonto har administrativ adgang til systemet,`nog at Freenet Installer køres med adgang til at udnytte disse rettigheder.")
	Trans_Add("Freenet Installer was not able to write to the selected installation directory.`nPlease select one to which you have write access.", "Freenet Installer kunne ikke skrive til den valgte installationsmappe.`nVælg venligst en mappe du har skriveadgang til.")
	Trans_Add("Freenet Installer was not able to find a free port on your system in the range ", "Freenet Installer kunne ikke finde en fri port på dit system i intervallet ")
	Trans_Add("Please free a system port in this range to install Freenet.", "For at installere Freenet er du nødt til at frigøre en port i dette interval.")
	Trans_Add("Freenet Installer was not able to create a Winsock 2.0 socket`nfor port availability testing.", "Freenet Installer kunne ikke oprette en Winsock 2.0-sokkel`ntil porttestning.")

	; Installer - Unsupported Windows version
	Trans_Add("Freenet only supports the following versions of the Windows operating system:", "Freenet understøtter kun følgende versioner af Windows-operativsystemet:")
	Trans_Add("Please install one of these versions if you want to use Freenet on Windows.", "Hvis du vil bruge Freenet er du nødt til at installere en af disse versioner.")

	; Installer - Java missing
	Trans_Add("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:", "Freenet kræver Java Runtime Environment, men dit system har tilsyneladende ikke en opdateret version installeret. Du kan installere Java ved hjælp af den inkluderede online-installer som automatisk vil downloade og installere filerne fra Javas hjemmeside:")
	Trans_Add("&Install Java", "&Installer Java")
	Trans_Add("The installation will continue once Java version ", "Installationen vil fortsætte når Java version ")
	Trans_Add(" or later has been installed.", " eller nyere er blevet installeret.")

	; Installer - Old installation detected
	Trans_Add("Freenet Installer has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:", "Freenet Installer har opdaget at Freenet allerede er installeret, men af et ældre, ikke længere understøttet, installationsprogram. For at fortsætte skal du først afinstallere din nuværende version ved hjælp af det tidligere oprettede afinstallationsprogram:")
	Trans_Add("&Uninstall", "A&finstaller")
	Trans_Add("The installation will continue once the old installation has been removed.", "Installationen vil fortsætte når den tidligere installation er blevet fjernet.")

	; Installer - Main GUI - Header
	Trans_Add("Please check the following default settings before continuing with the installation of Freenet.", "Kontrollér nedenstående standardindstillinger før du fortsætter med installationen af Freenet.")

	; Installer - Main GUI - Install folder
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

	; Installer - Main GUI - System service
	Trans_Add("System service", "Systemtjeneste")
	Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "Freenet vil automatisk starte i baggrunden som en systemtjeneste. Denne er nødvendigt for at være en del af Freenet-netværket, og vil bruge en lille andel systemresurser. Mængden af resurser kan justeres efter installationen.")

	; Installer - Main GUI - Additional settings
	Trans_Add("Additional settings", "Yderligere indstillinger")
	Trans_Add("Install &start menu shortcuts (All users: Freenet, Start Freenet, Stop Freenet)", "Installer start&menugenveje (Alle brugere: Freenet, Start Freenet, Stop Freenet)")
	Trans_Add("Install &desktop shortcut (All users: Freenet)", "Installer s&krivebordsgenvej (Alle brugere: Freenet)")
	Trans_Add("Browse Freenet &after the installation", "Åbn Freenet &efter installationen")

	; Installer - Main GUI - Footer
	Trans_Add("Version ", "Version ")
	Trans_Add(" - Build ", " - Build ")
	Trans_Add("&Install", "&Installer")

	; Installer - Actual installation
	Trans_Add("Opens the Freenet proxy homepage in a web browser", "Åbner Freenet-proxyen i en webbrowser")
	Trans_Add("Start Freenet", "Start Freenet") ; Shortcut name
	Trans_Add("Starts the background service needed to use Freenet", "Starter baggrundstjenesten krævet for at bruge Freenet")
	Trans_Add("Stop Freenet", "Stop Freenet") ; Shortcut name
	Trans_Add("Stops the background service needed to use Freenet", "Stopper baggrundstjenesten krævet for at bruge Freenet")
	Trans_Add("Installation finished successfully!", "Installationen gennemført med succes!")

	; Uninstaller - Common
	Trans_Add("Freenet uninstaller", "Freenet afinstallationsprogram")
	Trans_Add("Freenet uninstaller error", "Freenet afinstallationsprogram fejl")

	; Uninstaller - General
	Trans_Add("Freenet has been uninstalled!", "Freenet er blevet afinstalleret!")
	Trans_Add("Do you really want to uninstall Freenet?", "Vil du virkelig afinstallere Freenet?")
	Trans_Add("The development team would appreciate it very much if you can`nspare a moment and fill out a short, anonymous online`nsurvey about the reason for your uninstallation.`n`nThe survey, located on the Freenet website, will be opened`nin your browser after the uninstallation.`n`nTake the uninstallation survey?", "Udviklingsholdet vil sætte stor pris på hvis du kan undvære et`npar minutter, og udfylde et kort, anonymt, online spørgsskema`nomkring grunden til at du afinstallerer Freenet.`n`nSpørgeskemaet, placeret på Freenets hjemmeside, vil blive`nåbnet i din browser efter afinstallationen.`n`nUdfyld spørgeskemaet?")

	; Uninstaller - Error messageboxes
	Trans_Add("The uninstaller requires administrator privileges to uninstall Freenet. Please make sure that your user account has administrative access to the system, and the uninstaller is executed with access to use these privileges.", "Afinstallationsprogrammet kræver administratorrettigheder for at afinstallere Freenet. Kontrollér at din brugerkonto har administrativ adgang til systemet, og at afinstallationsprogrammet køres med adgang til at udnytte disse rettigheder.")
	Trans_Add("The uninstaller was not able to unpack necessary files to:", "Afinstallationsprogrammet kunne ikke udpakke nødvendige filer til:")
	Trans_Add("Please make sure that the uninstaller has full access to the system's temporary files folder.", "Kontrollér at afinstallationsprogrammet har ubegrænset adgang til systemets mappe til midlertidige filer.")
	Trans_Add("The uninstaller was unable to recognize your Freenet installation at:", "Afinstallationsprogrammet kunne ikke genkende din Freenet-installation i:")
	Trans_Add("Please run this uninstaller from the 'bin' folder of a Freenet installation.", "Kør venligst dette afinstallationsprogram fra 'bin'-mappen af en Freenet-installation.")

	; Uninstaller - Service problems
	Trans_Add("The uninstaller was unable to control the Freenet system service as it appears to be stuck.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Afinstallationsprogrammet kunne ikke styre Freenet-systemtjenesten da den tilsyneladende har sat sig fast.`n`nPrøv igen.`n`nHvis problemet fortsætter så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("The uninstaller was unable to find and control the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Afinstallationsprogrammet kunne ikke finde og styre Freenet-systemtjenesten.`n`nPrøv igen.`n`nHvis problemet fortsætter så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("The uninstaller was unable to stop the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Afinstallationsprogrammet kunne ikke stoppe Freenet-systemtjenesten.`n`nPrøv igen.`n`nHvis problemet fortsætter så indrapporter venligst denne fejlbesked til udviklerne.")

	; Uninstaller - Files undeletable
	Trans_Add("The uninstaller was unable to delete the Freenet files located at:", "Afinstallationsprogrammet kunne ikke slette Freenet-filerne placeret i:")
	Trans_Add("Please close all applications with open files inside this directory.", "Luk venligst alle programmer med åbne filer inden i denne mappe.")
	Trans_Add("The uninstallation was aborted.`n`nPlease manually remove the rest of your Freenet installation.", "Afinstallationen blev afbrudt.`n`nDu bliver nødt til manuelt at fjerne resten af din Freenet-installation.")

	; Uninstaller - Progress statuses
	Trans_Add("Stopping system service...", "Stopper systemtjeneste...")
	Trans_Add("Removing system service...", "Fjerner systemtjeneste...")
	Trans_Add("Removing custom user account rights...", "Fjerner specielle kontorettigheder...")
	Trans_Add("Removing files...", "Fjerner filer...")
	Trans_Add("Removing registry modifications...", "Fjerner registreringsdatabaseændringer...")
	Trans_Add("Removing custom user...", "Fjerner speciel bruger...")

	; Launcher
	Trans_Add("Freenet Launcher error", "Freenet Starter fejl")
	Trans_Add("Freenet Launcher was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Freenet Starter kunne ikke finde installid.dat ID-filen.`n`nKontrollér at du kører Freenet Starter fra en Freenet-installationsmappe.`nHvis du allerede gør dette, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Freenet Launcher was unable to find the bin\start.exe launcher.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet Starter kunne ikke finde bin\start.exe startprogrammet.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Freenet Launcher was unable to find the freenet.ini configuration file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Freenet Starter kunne ikke finde freenet.ini konfigurationsfilen.`n`nKontrollér at du kører Freenet Starter fra en Freenet-installationsmappe.`nHvis du allerede gør dette, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Freenet Launcher was unable to read the 'fproxy.port' value from the freenet.ini configuration file.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet Starter kunne ikke læse 'fproxy.port' værdien fra freenet.ini konfigurationsfilen.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Freenet Launcher was unable to find a supported browser.`n`nPlease install one of the supported browsers, or manually`nnavigate to: ", "Freenet Starter kunne ikke finde en understøttet browser.`n`nInstaller en af de understøttede browsere, eller naviger`nmanuelt til: ")
	Trans_Add("Freenet Launcher supports the following browsers:", "Freenet Starter understøtter følgende browsere:")
	Trans_Add("not recommended", "ikke anbefalet")

	; Service starter
	Trans_Add("Command line options (only use one):`n/silent - Hide info messages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service started)`n1 - Error occurred`n2 - Service was already running (no action)", "Kommandolinjeindstillinger (brug kun én):`n/silent - Skjul infobeskeder`n/verysilent - Skjul info- og statusbeskeder`n`nReturkoder:`n0 - Succes (tjeneste startet)`n1 - Fejl`n2 - Service kørte allerede (ingen handling)")
	Trans_Add("Freenet start script requires administrator privileges to start the Freenet service. Please make sure that your user account has administrative access to the system, and the start script is executed with access to use these privileges.", "Freenet-startprogrammet kræver administratorrettigheder for at starte Freenet-tjenesten. Kontrollér at din brugerkonto har administrativ adgang til systemet, og at Freenet-startprogrammet køres med adgang til at udnytte disse rettigheder.")
	Trans_Add("Freenet start script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet start script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "Freenet startprogrammet kunne ikke finde installid.dat ID-filen.`n`nKontrollér at du kører Freenet startprogrammet fra 'bin'-mappen af en Freenet-installation.`nHvis du allerede gør dette, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Freenet start script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet startprogrammet kunne ikke styre Freenet-systemtjenesten da den tilsyneladende har sat sig fast.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Freenet start script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet startprogrammet kunne ikke finde og styre Freenet-systemtjenesten.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Waiting for the Freenet background service to start...", "Venter på at Freenet-baggrundstjenesten starter...")
	Trans_Add("Freenet start script", "Freenet startprogram")
	Trans_Add("Freenet start script was unable to start the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet startprogrammet kunne ikke starte Freenet-systemtjenesten.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("The Freenet service has been started!", "Freenet-tjenesten er blevet startet!")
	Trans_Add("The Freenet service is already running!", "Freenet-tjenesten kører allerede!")
	Trans_Add("Freenet start script error", "Freenet startprogram fejl")

	; Service stopper
	Trans_Add("Command line options (only use one):`n/silent - Hide info messages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service stopped)`n1 - Error occurred`n2 - Service was not running (no action)", "Kommandolinjeindstillinger (brug kun én):`n/silent - Skjul infobeskeder`n/verysilent - Skjul info- og statusbeskeder`n`nReturkoder:`n0 - Succes (tjeneste stoppet)`n1 - Fejl`n2 - Service kørte ikke (ingen handling)")
	Trans_Add("Freenet stop script requires administrator privileges to stop the Freenet service. Please make sure that your user account has administrative access to the system, and the stop script is executed with access to use these privileges.", "Freenet-stopprogrammet kræver administratorrettigheder for at stoppe Freenet-tjenesten. Kontrollér at din brugerkonto har administrativ adgang til systemet, og at Freenet-stopprogrammet køres med adgang til at udnytte disse rettigheder.")
	Trans_Add("Freenet stop script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet stop script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "Freenet stopprogrammet kunne ikke finde installid.dat ID-filen.`n`nKontrollér at du kører Freenet stopprogrammet fra 'bin'-mappen af en Freenet-installation.`nHvis du allerede gør dette, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Freenet stop script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet stopprogrammet kunne ikke styre Freenet-systemtjenesten da den tilsyneladende har sat sig fast.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Freenet stop script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet stopprogrammet kunne ikke finde og styre Freenet-systemtjenesten.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Waiting for the Freenet background service to stop...", "Venter på at Freenet-baggrundstjenesten stopper...")
	Trans_Add("Freenet stop script", "Freenet stopprogram")
	Trans_Add("The Freenet service has been stopped!", "Freenet-tjenesten er blevet stoppet!")
	Trans_Add("The Freenet service is already stopped!", "Freenet-tjenesten er allerede stoppet!")
	Trans_Add("Freenet stop script was unable to stop the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet stopprogrammet kunne ikke stoppe Freenet-systemtjenesten.`n`nPrøv at geninstallere Freenet.`n`nHvis problemet fortsætter, så indrapporter venligst denne fejlbesked til udviklerne.")
	Trans_Add("Freenet stop script error", "Freenet stopprogram fejl")
}

