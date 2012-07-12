;
; Translation file - Polish (pl) - by Arkadiusz B³asiak (ares1112 that-a-thingy gmail that-dot-thingy com)
;

LoadLanguage_pl()
{
; Translation credit string. Remember to change language and name to your own in the translated string (not in the english one). Don't add personal comments or website links here - add those to the header of this file instead if you want.
Trans_Add("English localization by: Christian Funder Sommerlund (Zero3)", "Polskie t³umaczenie przez: Arkadiusz B³asiak (Ares)")

; Shared strings (Installer, Uninstaller)
Trans_Add("was not able to unpack necessary files to:", "nie móg³ wypakowaæ potrzebnych plików do:")
Trans_Add("Please make sure that this program has full access to the system's temporary files folder.", "Proszê upewniæ siê, ¿e ten program ma pe³ny dostêp do plików tymczasowych.")

; Shared strings (Installer, Uninstaller, Service starter, Service stopper)
Trans_Add("requires administrator privileges to manage the Freenet service. Please make sure that your user account has administrative access to the system, and this program is executed with access to use these privileges.", "wymagane uprawnienia administratora, aby zarz¹dzaæ us³ug¹ Freenet. Proszê siê upewniæ czy twoje konto u¿ytkownika posiada dostêp administracyjny do systemu i program jest uruchomiony z tymi uprawnieniami.")

; Installer - Common
Trans_Add("Freenet Installer error", "B³¹d instalatora Freenet")
Trans_Add("Freenet Installer", "Instalator Freenet")
Trans_Add("Welcome to the Freenet Installer!", "Witaj w instalatorze programy Freenet!")
Trans_Add("Installation Problem", "B³¹d podczas instalacji")
Trans_Add("E&xit", "&Wyjœcie")

; Installer - Unsupported Windows version
Trans_Add("Freenet only supports the following versions of the Windows operating system:", "Freenet obs³uguje wy³¹cznie nastêpuj¹ce wersje systemu Windows:")
Trans_Add("Please install one of these versions if you want to use Freenet on Windows.", "Proszê zainstalowaæ jedn¹ z tych wersji, je¿eli chcesz u¿ywaæ Freenet w systemie Windows.")

; Installer - Java missing
Trans_Add("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:", "Freenet wymaga pakiet Java Runtime Environment, jednak twój system nie posiada aktualnej wersji. Mo¿esz zainstalowaæ Javê poprzez zawarty instalator online, który pobierze i zainstaluje wymagane pliki automatycznie ze strony Javy:")
Trans_Add("&Install Java", "&Zainstaluj Javê")
Trans_Add("The installation will continue once Java version", "Instalacja bêdzie kontynuowana, gdy wersja Javy")
Trans_Add("or later has been installed.", "lub pó¿niejszej zakoñczy siê.")

; Installer - Old installation detected
Trans_Add("has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:", "wykry³, ¿e Freenet jest ju¿ zainstalowany. Obecna instalacja by³a zainstalowana przez starszy, niewspierany instalator. Aby kontynuowaæ, nale¿y usun¹æ aktualn¹ wersjê Freenet poprzez uprzedni deinstalator:")
Trans_Add("&Uninstall", "&Usuñ")
Trans_Add("The installation will continue once the old installation has been removed.", "Instalacja bêdzie kontynuowana, gdy starsza instalacja zostanie usuniêta.")

; Installer - Main GUI - Header
Trans_Add("Please check the following default settings before continuing with the installation of Freenet.", "Proszê sprawdziæ nastêpuj¹ce domyœlne ustawienia przed kontunuowaniem instalacji Freenet.")

; Installer - Main GUI - Install folder
Trans_Add("Installation directory", "Œcie¿ka instalacji")
Trans_Add("&Browse", "&Przegl¹daj")
Trans_Add("De&fault", "Do&myœlne")
Trans_Add("Freenet requires the installation drive to have at least", "Freenet wymaga, aby dysk mia³ przynajmniej")
Trans_Add("MB free disk space. The actual amount of space reserved to Freenet will be configured after the installation.", "MB wolnej przestrzeni. Aktualna wartoœæ przestrzeni zarezerwowanej dla Freenet bêdzie skonfigurowana po instalacji.")
Trans_Add("Status:", "Status:")
Trans_Add("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.", "Jeœli folder o nazwie zawieraj¹cej s³owo 'Freenet' nie bêdzie wybrany, zostanie utworzony automatycznie.")
Trans_Add("Invalid install path!", "Niew³aœciwa œcie¿ka instalacji!")
Trans_Add("(Too long for file system to handle)", "(Zbyt d³ugie dla systemu plików)")
Trans_Add("Not enough free space on installation drive!", "Brak wystarczaj¹cej iloœci wolnego miejsca na dysku!")
Trans_Add("Freenet already installed! Please uninstall first or choose another directory!", "Freenet jest ju¿ zainstalowany! Proszê go usun¹æ lub wybraæ inn¹ œcie¿kê!")
Trans_Add("Installation directory OK!", "Œcie¿ka instalacji OK!")

; Installer - Main GUI - System service
Trans_Add("System service", "Us³uga systemowa")
Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "Freenet uruchomi siê automatycznie w tle jako us³uga systemowa. Jest to wymagane, aby byæ czêœci¹ sieci Freenet i zu¿ywa niewielkie iloœci zasobów systemu. Iloœæ u¿ywanych zasobów mo¿e byæ zmieniona po instalacji.")

; Installer - Main GUI - Additional settings
Trans_Add("Additional settings", "Dodatkowe ustawienia")
Trans_Add("Start Freenet &Tray Manager on Windows startup", "Uruchom mened¿er &tray'a Freenet podczas uruchamiania Windows")
Trans_Add("(Recommended)", "(Zalecane)")
Trans_Add("Install &start menu shortcuts", "Zainstaluj skróty w menu &start")
Trans_Add("(Optional)", "(Opcjonalne)")
Trans_Add("Install &desktop shortcut", "Zainstaluj skrót na pu&lpicie")
Trans_Add("Launch Freenet &after the installation", "Uruchom Freenet po &instalacji")

; Installer - Main GUI - Footer
Trans_Add("Version ", "Wersja")
Trans_Add(" - Build ", " - Kompilacja")
Trans_Add("&Install", "I&nstaluj")

; Installer - Actual installation
Trans_Add("Opens Freenet Tray Manager in the notification area", "Otwiera mened¿er tray'a Freenet w obszarze powiadomieñ")
Trans_Add("Opens the Freenet proxy homepage in a web browser", "Otwiera stronê domow¹ Freenet proxy w przegl¹darce")
Trans_Add("Start Freenet", "Uruchom Freenet")
Trans_Add("Stop Freenet", "Zatrzymaj Freenet")
Trans_Add("Installation finished successfully!", "Instalacja ukoñczona pomyœlnie!")
Trans_Add("Freenet Installer by:", "Instalator Freenet przez:")

; Installer - Error messageboxes
Trans_Add("was not able to find a free port on your system in the range", "nie móg³ znaleŸæ wolnego portu na twoim systemie w zakresie")
Trans_Add("Please free a system port in this range to install Freenet.", "Proszê zwolniæ port w tym zakresie, aby zainstalowaæ Freenet.")
Trans_Add("was not able to create a Winsock 2.0 socket for port availability testing.", "nie móg³ stworzyæ Winsock 2.0 socket dla testu dostêpnoœci portów.")
Trans_Add("was not able to write to the selected installation directory. Please select one to which you have write access.", "nie móg³ zapisaæ do wybranej œcie¿ki instalacji. Proszê wybraæ taki, do którego masz dostêp zapisu.")
Trans_Add("Error: ", "B³¹d: ")

; Shared strings (Uninstaller, Service starter, Service stopper)
Trans_Add("was unable to control the Freenet system service.", "nie móg³ kontrolowaæ us³ugi systemowej Freenet")
Trans_Add("Reason:", "Powód:")
Trans_Add("Timeout while managing the service.", "Timeout podczas zarz¹dzania us³ug¹.")
Trans_Add("Could not access the service.", "Brak dostêpu do us³ugi.")
Trans_Add("Service did not respond to signal.", "Us³uga nie odpowiedzia³a na sygna³.")

; Uninstaller
Trans_Add("Freenet uninstaller", "Deinstalator Freenet")
Trans_Add("was unable to recognize your Freenet installation at:", "nie móg³ rozpoznaæ instalacji Freenet w:")
Trans_Add("Please run this program from the 'bin' folder of a Freenet installation.", "Proszê uruchomiæ ten program z folderu 'bin' instalacji Freenet.")
Trans_Add("Do you really want to uninstall Freenet?", "Czy na pewno chcesz usun¹æ Freenet?")
Trans_Add("Stopping system service...", "Zatrzymywanie us³ugi systemowej...")
Trans_Add("Shutting down tray managers...", "Wy³¹czanie mened¿erów tray'a")
Trans_Add("Removing system service...", "Usuwanie us³ugi systemowej...")
Trans_Add("Removing files...", "Usuwanie plików...")
Trans_Add("Freenet uninstaller error", "B³¹d deinstalatora Freenet")
Trans_Add("was unable to delete the Freenet files located at:", "nie móg³ usun¹æ plików programu Freenet w:")
Trans_Add("Please close all applications with open files inside this directory.", "Proszê zamkn¹æ wszystkie aplikacje, które maj¹ otwarte pliki w tej œcie¿ce.")
Trans_Add("The uninstallation was aborted.", "Proces deinstalacji zosta³ przerwany.")
Trans_Add("Please manually remove the rest of your Freenet installation.", "Proszê rêcznie usun¹æ resztê pozosta³ych plików instalacji Freenet.")
Trans_Add("Removing registry modifications...", "Usuwanie modyfikacji rejestru...")
Trans_Add("Freenet has been uninstalled!", "Freenet zosta³ pomyœlnie usuniêty!")

; Shared strings (Launcher, Tray manager)
Trans_Add("was unable to find the following file:", "nie móg³ odnaleŸæ nastêpuj¹cego pliku:")
Trans_Add("Make sure that you are running", "Upewnij siê, ¿e jest uruchomiony")
Trans_Add("from a Freenet installation directory.", "z œcie¿ki instalacyjnej Freenet.")

; Shared Strings (Launcher, Service starter, Service stopper, Tray manager)
Trans_Add("If the problem keeps occurring, try reinstalling Freenet or report this error message to the developers.", "Jeœli problem nadal wystêpuje, proszê zainstalowaæ Freenet ponownie lub zg³osiæ ten komunikat deweloperom.")

; Launcher
Trans_Add("Freenet Launcher", "Freenet Launcher")
Trans_Add("Freenet Launcher error", "B³¹d Freenet Launcher")
Trans_Add("was unable to read the 'fproxy.port' value from the 'freenet.ini' configuration file.", "nie móg³ odczytaæ wartoœci 'fproxy.port' z pliku konfiguracyjnego 'freenet.ini'.")

; Shared strings (Service starter, Service stopper)
Trans_Add("Command line options (only use one):", "Opcje wiersza poleceñ (u¿ywaj tylko jednej):")
Trans_Add("Hide info messages", "Ukryj powiadomienia")
Trans_Add("Hide info and status messages", "Ukryj powiadomienia i informacje o statusie")
Trans_Add("Return codes:", "Kody zwrotne:")
Trans_Add("Success", "Sukces")
Trans_Add("Error occurred", "Wyst¹pi³ b³¹d")
Trans_Add("(no action)", "(brak akcji)")

; Service starter
Trans_Add("(service started)", "(us³uga uruchomiona)")
Trans_Add("Service was already running", "Us³uga ju¿ dzia³a")
Trans_Add("Freenet Starter", "Starter Freenet")
Trans_Add("The Freenet service is starting...", "Us³uga Freenet jest uruchamiana...")
Trans_Add("The Freenet service has been started!", "Us³uga Freenet zosta³a uruchomiona!")
Trans_Add("The Freenet service is already running!", "Us³uga Freenet jest ju¿ uruchomiona!")
Trans_Add("Freenet Starter error", "B³¹d Startera Freenet")

; Service stopper
Trans_Add("(service stopped)", "(us³uga zatrzymana)")
Trans_Add("Service was not running", "Us³uga nie by³a uruchomiona")
Trans_Add("Freenet Stopper", "Stopper Freenet")
Trans_Add("The Freenet service is stopping...", "Us³uga Freenet jest zatrzymywana...")
Trans_Add("The Freenet service has been stopped!", "Us³uga Freenet zosta³a zatrzymana!")
Trans_Add("The Freenet service is already stopped!", "Us³uga Freenet jest ju¿ zatrzymana!")
Trans_Add("Freenet Stopper error", "B³¹d Stoppera Freenet")

; Tray manager
Trans_Add("Freenet Tray", "Freenet Tray")
Trans_Add("Launch Freenet", "Uruchom Freenet")
Trans_Add("Start Freenet service", "Uruchom us³ugê Freenet")
Trans_Add("Stop Freenet service", "Zatrzymaj us³ugê Freenet")
Trans_Add("Manual update check", "Rêczne sprawdzenie aktualizacji")
Trans_Add("View logfile", "Poka¿ logfile")
Trans_Add("About", "O...")
Trans_Add("Exit", "Wyjœcie")
Trans_Add("You can browse, start and stop Freenet along with other useful things from this tray icon.", "Mo¿esz przegl¹daæ, startowaæ i zatrzymywaæ Freenet wraz z innymi przydatnymi rzeczami z tej ikony tray'a.")
Trans_Add("Left-click: Start/Browse Freenet", "Lewe klikniêcie: Start/Przegl¹daj Freenet")
Trans_Add("Right-click: Advanced menu", "Prawe klikniêcie: Menu zaawansowane")
Trans_Add("Warning: Using the manual update check will update Freenet and its helper tools from the official Freenet website.", "Ostrze¿enie: U¿ycie rêcznej aktualizacji zaktualizuje Freenet i jego narzêdzia pomocy z oficjalnej strony Freenet.")
Trans_Add("Freenet already has a secure built-in autoupdate feature that will keep itself up-to-date automatically.", "Freenet posiada bezpieczne, wbudowane narzêdzie do automatycznej aktualizacji, które bêdzie na bie¿¹co aktualizowa³o program.")
Trans_Add("You should only use this manual update check if your installation is broken or you need updated versions of the helper tools.", "Powinieneœ u¿ywaæ to rêczne narzêdzie sprawdzania aktualizacji, jeœli instalacja jest zepsuta, b¹dŸ potrzebujesz zaktualizowane wersje narzêdzi pomocy.")
Trans_Add("Freenet Windows Tray Manager", "Mened¿er Tray'a Freenet")
}
