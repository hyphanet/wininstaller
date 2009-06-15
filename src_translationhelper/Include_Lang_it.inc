;
; Translation file - Italian (it) - by Luke771 (luke771 that-a-thingy gmail that-dot-thingy com / www.apophis.ch / FAFS freesite)
;

LoadLanguage_it()
{
	; Installer - Common
	Trans_Add("Freenet Installer", "Programma di Installazione di Freenet")
	Trans_Add("Welcome to the Freenet Installer!", "Benvenuti nel programma di installazione di Freenet")
	Trans_Add("Installation Problem", "Problema nell'installazione")
	Trans_Add("Freenet Installer fatal error", "Errore irreparabile nel programma di installazione di Freenet")
	Trans_Add("Freenet Installer error", "Errore nel programma di installazione di Freenet")
	Trans_Add("Error: ", "Errore")
	Trans_Add("E&xit", "E&sci")

	; Installer - Error messageboxes
	Trans_Add("Freenet Installer was not able to unpack necessary installation files to:", "non è stato possibile estrarre i necessari file di installzione in:")
	Trans_Add("Please make sure that Freenet Installer has full access to the system's temporary files folder.", "Si prega di accertarsi che il Programma di Installazione di Freenet abbia pieno accesso alla cartella dei file temporanei del sistema.")
	Trans_Add("Freenet Installer requires administrator privileges to install Freenet.`nPlease make sure that your user account has administrative access to the system", "Il Programma di Installazione di Freenet necessita di privilegi amministrativi per poter installare Freenet`n Si prega di accertarsi che l'account in uso abbia accesso amministrativo al sistema,")
	Trans_Add("Freenet Installer was not able to write to the selected installation directory.`nPlease select one to which you have write access.", "Il programma di installazione di Freenet non è riuscito ad iscrivere i dati nella cartella selezionata.`nSi prega di selezionare una cartella alla quale nella quale sia possibile scrivere")
	Trans_Add("Freenet Installer was not able to find a free port on your system in the range ", "Il programma di installazione di Freenet non è riuscito a rilevare una porta libera sul sistema in range ")
	Trans_Add("Please free a system port in this range to install Freenet.", "Si prega di liberare una porta in questo segmento per poter installare Freenet")
	Trans_Add("Freenet Installer was not able to create a Winsock 2.0 socket`nfor port availability testing.", "Non è stato possibile creare un socket Winsock 2.0`n per il testing disponibilità porte")

	; Installer - Unsupported Windows version
	Trans_Add("Freenet only supports the following versions of the Windows operating system:", "Freenet supporta soltanto le seguenti versioni del sistema operativo Windows")
	Trans_Add("Please install one of these versions if you want to use Freenet on Windows.", "Si prega di installare una di queste versioni se si vuole usare Freenet su Windows")

	; Installer - Java missing
	Trans_Add("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:", "Freenet necessita di Java Runtime Environment per poter funzionare, ma il sistema non sembra disporre di una versione aggiornata. E' possibile installare Java usando il programma di installazione on-line integrato, il quale scaricherà i file necessari dal sito web di Java e li installerà automaticamente.")
	Trans_Add("&Install Java", "&Installa Java")
	Trans_Add("The installation will continue once Java version ", "L'installazione continuerà dopo che Java versione")
	Trans_Add(" or later has been installed.", "o posteriore sarà stata installata")

	; Installer - Old installation detected
	Trans_Add("Freenet Installer has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:", "Il Programma di Installazione di Freenet ha rilevato l'esistenza  di una precedente installazione di Freenet creata da un programma di installazione obsoleto e non più supportato. Si Prega di rimuovere l'attuale installazione prima di continuare")
	Trans_Add("&Uninstall", "Rim&uovi")
	Trans_Add("The installation will continue once the old installation has been removed.", "L'installazione continuerà dopo che la vecchia copia di Freenet sarà stata rimossa")

	; Installer - Main GUI - Header
	Trans_Add("Please check the following default settings before continuing with the installation of Freenet.", "Si prega di controllare le seguenti impostazioni di default prima di continuare")

	; Installer - Main GUI - Install folder
	Trans_Add("Installation directory", "Directory installazione")
	Trans_Add("Freenet requires at least ", "Freenet necessita di ")
	Trans_Add(" MB free disk space, but will not install with less than ", " MB liberi su disco, Minimo necessario per installare ")
	Trans_Add(" MB free. The amount of space reserved can be changed after installation.", " MB a disposizione. Questa impostazione può essere cambiata dopo l'installazione")
	Trans_Add("&Browse", "Cam&bia")
	Trans_Add("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.", "Se il percorso non contiene 'Freenet', una nuova cartella verrà creata automaticamente")
	Trans_Add("De&fault", "Prede&finita")
	Trans_Add("Status:", "Stato")
	Trans_Add("Invalid install path!", "Percorso di installazione non valido!")
	Trans_Add("Invalid install path! (Too long for file system to handle)", "Percorso di installazione non valido (troppo lungo per porter essere gestito dal file system")
	Trans_Add("Not enough free space on installation drive!", "Spazio disponibile sul drive di installazione non sufficiente!")
	Trans_Add("Freenet already installed! Please uninstall first or choose another directory!", "Preesistente installazione di Freenet rilevata! Si prega di disinstallare o scegliere una directory diversa da quella attuale")
	Trans_Add("Installation directory OK!", "Directory di installazione: OK")

	; Installer - Main GUI - System service
	Trans_Add("System service", "Servizio di sistema")
	Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "Freenet si avvierà automaticamente in background come servizio di sistema. Ciò è necessario per entrare a far parte della rete Freenet, ad un piccolo costo in termini di risorse di sistema. La quantità di risorse utilizzate può essere configurata dopo l'installazione")

	; Installer - Main GUI - Additional settings
	Trans_Add("Additional settings", "Altre Opzioni")
	Trans_Add("Install &start menu shortcuts (Freenet, Start Freenet, Stop Freenet)", "Installa controlli nel menu &start (Freenet, Avvia Freenet, Arresta Freeneet)")
	Trans_Add("Install &desktop shortcut (Freenet)", "Installa icone sul &desktop")
	Trans_Add("Launch Freenet &after the installation", "&Esplora Freenet dopo l'installazione")

	; Installer - Main GUI - Footer
	Trans_Add("Version ", "Versione")
	Trans_Add(" - Build ", " - Build")
	Trans_Add("&Install", "&Installa")

	; Installer - Actual installation
	Trans_Add("Opens the Freenet proxy homepage in a web browser", "Apre la homepage di Freenet proxy in un web browser")
	Trans_Add("Start Freenet", "Avvia Freenet")
	Trans_Add("Starts the background service needed to use Freenet", "Avvia il servizio in background necessario ad usare Freenet")
	Trans_Add("Stop Freenet", "Arresta Freenet")
	Trans_Add("Stops the background service needed to use Freenet", "Arresta il servizio in background necessario ad usare Freenet")
	Trans_Add("Installation finished successfully!", "Installazione completata con successo!")

	; Uninstaller - Common
	Trans_Add("Freenet uninstaller", "Rimozione di Freenet")
	Trans_Add("Freenet uninstaller error", "Errore nella rimozione di Freenet")

	; Uninstaller - General
	Trans_Add("Freenet has been uninstalled!", "Rimozione di Freenet completata!")
	Trans_Add("Do you really want to uninstall Freenet?", "Conferma di voler rimuovere Freenet?")
	Trans_Add("The development team would appreciate it very much if you can`nspare a moment and fill out a short, anonymous online`nsurvey about the reason for your uninstallation.`n`nThe survey, located on the Freenet website, will be opened`nin your browser after the uninstallation.`n`nTake the uninstallation survey?", "Il team di Freenet apprezzerebbe grandemente se Lei potesse`nrispondere in modo anonimo	e veloce ad un breve questionario`non-line sui motivi della disinstallazione.`n`n Il questionario ospitato sul sito di Freenet`nsi aprirà nel suo browser al termine della disinstallazione di Freenet`n`nRisponde questionario di disinatallazione?")

	; Uninstaller - Error messageboxes
	Trans_Add("The uninstaller requires administrator privileges to uninstall Freenet. Please make sure that your user account has administrative access to the system, and the uninstaller is executed with access to use these privileges.", "Il programma di disinstallazione necessita dei privilegi di amministratore per poter rimuovere Freenet. Si prega di assicurarsi che l'account in uso abbia accesso amministrativo al sistema e che il programma di disinstallazione di Freenet sia eseguito con accesso all'uso di tali privilegi ")
	Trans_Add("The uninstaller was not able to unpack necessary files to:", "Il programma di disinstallazione non è riuscito ad estrarre i file necessari in:")
	Trans_Add("Please make sure that the uninstaller has full access to the system's temporary files folder.", "Si prega di accertarsi che il programma di disinstallazione abbia pieno accesso alla cartella dei file temporanei del sistema.")
	Trans_Add("The uninstaller was unable to recognize your Freenet installation at:", "Il programma di disinstallazione non è riuscito a rilevare la presenza dell' installazione Freenet in:")
	Trans_Add("Please run this uninstaller from the 'bin' folder of a Freenet installation.", "Si prega di lanciare questo programma	di disinstallazione dalla cartella 'bin' di un'installazione di Freenet")

	; Uninstaller - Service problems
	Trans_Add("The uninstaller was unable to control the Freenet system service as it appears to be stuck.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Il programma	di disinstallazione non è riuscito ad assumere il controllo del servizio di sistema Freenet perché esso appare bloccato.`n`nISe il problema persiste, riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("The uninstaller was unable to find and control the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Il programma	di disinstallazione non è riuscito ad identificare e controllare il servizio di sistema Freenet.`n`nSi Prega di riprovare.`n`nISe il problema persiste, riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("The uninstaller was unable to stop the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Il programma	di disinstallazione non è riuscito ad arrestare il servizio di sistema Freenet.`n`n Si Prega di riprovare`n`nSe il problema persiste, si prega di riportare questo messaggio di errore agli sviluppatori.")

	; Uninstaller - Files undeletable
	Trans_Add("The uninstaller was unable to delete the Freenet files located at:", "Il programma	di disinstallazione non è riuscito	a rimuovere i file di Freenet da:")
	Trans_Add("Please close all applications with open files inside this directory.", "Si prega di chiuidere tutte le applicazioni che hanno file aperti in questa directory")
	Trans_Add("The uninstallation was aborted.`n`nPlease manually remove the rest of your Freenet installation.", "La disinstallazione è stata interrotta.`n`nSi prega di rimuovere manualmente quanto resta dell'installazione Freenet ")

	; Uninstaller - Progress statuses
	Trans_Add("Stopping system service...", "Arresto del servizio di sistema in corso...")
	Trans_Add("Removing system service...", "Rimozione del servizio di sistema in corso...")
	Trans_Add("Removing custom user account rights...", "Rimozione dei privilegi dell'utente Freenet corso...")
	Trans_Add("Removing files...", "Rimozione dei file in corso... ")
	Trans_Add("Removing registry modifications...", "Rimozione delle modifiche di registro in corso...")
	Trans_Add("Removing custom user...", "Rimozione dell'utente Freenet in corso...")

	; Launcher
	Trans_Add("Freenet Launcher error", "Errore nel Programma di Avvio di Freemet")
	Trans_Add("Freenet Launcher was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Il programma di avvio di Freenet non è riuscito a rilevare il file ID installid.dati`n`nAccertarsi che il programma di avvio di Freenet sia stato lanciato da una directory di installazione Freenet.`nSe lo è stato, si prega di riportare questo messaggio agli sviluppatori.")
	Trans_Add("Freenet Launcher was unable to find the bin\start.exe launcher.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Il programma di avvio di Freenet non è riuscito a rilevare il launcher bin\start.exe.`n`nSi prega di reinstallare Freenet`n`nSe il problema persiste, si prega di riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("Freenet Launcher was unable to find the freenet.ini configuration file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Il programma di avvio di Freenet non è riuscito a rilevare il file configurazione freeneet.ini`n`nControllare che il programma di avvio sia stato lanciato da una directory di installazione Freenet.`nSe lo è stato, si prega di riportare questo messaggio agli sviluppatori")
	Trans_Add("Freenet Launcher was unable to read the 'fproxy.port' value from the freenet.ini configuration file.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Il programma di avvio di Freenet non è riuscito a leggere il valore 'fproxy port' dal file di configurazione conf.ini.`n`nSi prega di reinstallare Freenet`n`nSe il problema persiste, riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("Freenet Launcher was unable to find a supported browser.`n`nPlease install one of the supported browsers, or manually`nnavigate to: ", "Il programma di avvio di Freenet non è riuscito a rilevare la resenza di un browser supportato.`n`nSi prega di installare uno dei browser supportati, o navigare`nmanualmente a: ")
	Trans_Add("Freenet Launcher supports the following browsers:", "Il programma di avvio di Freenet supporta i seguenti browser:")
	Trans_Add("not recommended", "sconsigliato")

	; Service starter
	Trans_Add("Command line options (only use one):`n/silent - Hide info messages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service started)`n1 - Error occurred`n2 - Service was already running (no action)", "Opzioni riga di comando (usare una sola):`n/silenzioso - nasconde messaggi di informazioni`n/molto silenzioso - nasconde messaggi di informazione e di stato`nCodici di ritorno:`n0 - Successo (servizio avviato)`n1 - Si è verificato un errore`n2 - Il servizio era già avviato (nessuna azione)")
	Trans_Add("Freenet start script requires administrator privileges to start the Freenet service. Please make sure that your user account has administrative access to the system, and the start script is executed with access to use these privileges.", "Lo script di avvio di Freenet necessita di privilegi amministrativi per avviare il servizio Freenet. Si prega di accertarsi che l'account in uso abbia accesso amministrativo al sistema e che lo script di avvio venga eseguito con accesso all'uso di tali privilegi")
	Trans_Add("Freenet start script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet start script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "Lo script di avvio di Freenet non è riuscito a rilevare il file ID installid.dat`n`nControllare che lo script di avvio sia stato lanciato da una directory di installazione Freenet.`nSe lo è stato, si prega di riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("Freenet start script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Lo script di avvio di Freenet non è riuscito ad assumere il controllo del servizio di sistema Freenet perché esso appare bloccato.`n`nSi prega di reinstallare Freenet.`n`nSe il problema persiste, si prega di riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("Freenet start script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Lo script di avvio di Freenet non è riuscito a assumere il controllo del servizio di sistema Freenet`n`nSi prega di reinstallare Freenet.`n`nSe il problema persiste, si prega di riportare questo messaggio agli sviluppatori")
	Trans_Add("Waiting for the Freenet background service to start...", "Avvio del servizio Freenet in background in corso...")
	Trans_Add("Freenet start script", "Script di avvio Freenet")
	Trans_Add("Freenet start script was unable to start the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Lo script di avvio di Freenet non è riuscito ad avviare il servizio di sistema Freenet.`n`nSi prega di reinstallare Freenet.`n`nSe il problema persiste, si prega di riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("The Freenet service has been started!", "Il servizio Freenet è stato avviato")
	Trans_Add("The Freenet service is already running!", "Il servizio Freenet è già attivo")
	Trans_Add("Freenet start script error", "Errore nello script di avvio Freenet")

	; Service stopper
	Trans_Add("Command line options (only use one):`n/silent - Hide info messages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service stopped)`n1 - Error occurred`n2 - Service was not running (no action)", "Opzioni riga di comando (usare una sola):`n/silenzioso - nasconde messaggi di informazioni`n/molto silenzioso - nasconde messaggi di informazione e di stato`nCodici di ritorno:`n0 - Successo (servizio avviato)`n1 - Si è verificato un errore`n2 - Il servizio era già avviato (nessuna azione)")
	Trans_Add("Freenet stop script requires administrator privileges to stop the Freenet service. Please make sure that your user account has administrative access to the system, and the stop script is executed with access to use these privileges.", "Lo script di arresto di Freenet necessita di privilegi amministrativi per avviare il servizio Freenet. Si prega di accertarsi che l'account in uso abbia accesso amministrativo al sistema e che lo script di avvio venga eseguito con accesso all'uso di tali privilegi")
	Trans_Add("Freenet stop script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet stop script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "Lo script di arresto di Freenet non è riuscito a rilevare il file ID installid.dat`n`nAccertarsi che lo script di arresto sia stato lanciato da una directory di installazione Freenet.`nSe lo è stato, si prega di riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("Freenet stop script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Lo script di arresto di Freenet non è riuscito ad acquisire il controllo del servizio di sistema Freenet perché esso appare bloccato.`n`nSi prega di reinstallare Freenet.`n`nSe il problema persiste, si prega di riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("Freenet stop script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Lo script di arresto di Freenet non è riuscito a rilevare il servizio di sistema Freenet ed assumerne il controllo.`n`nSi prega di reinstallare Freenet.`n`nSe il problema persiste, si prega di riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("Waiting for the Freenet background service to stop...", "Arresto del servizio Freenet in background in corso...")
	Trans_Add("Freenet stop script", "Script di arresto di Freenet")
	Trans_Add("The Freenet service has been stopped!", "Il servizio Freenet è stato disattivato")
	Trans_Add("The Freenet service is already stopped!", "Il servizio Freenet è già inattivo")
	Trans_Add("Freenet stop script was unable to stop the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Lo script di arresto di Freenet non è riuscito ad arrestare il servizio di sistema Freenet.`n`nSi prega di reinstallare Freenet.`n`nSe il problema persiste, si prega di riportare questo messaggio di errore agli sviluppatori")
	Trans_Add("Freenet stop script error", "Errore nello script di arresto di Freenet")
}

