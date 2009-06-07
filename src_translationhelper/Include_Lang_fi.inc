;
; Translation file - Finnish (fi) - by Samu Voutilainen (http://smar.fi)
;

LoadLanguage_fi()
{
	; Installer - Common
	Trans_Add("Freenet Installer", "Freenet-asennusohjelma")
	Trans_Add("Welcome to the Freenet Installer!", "Tervetuloa asentamaan Freenettiä")
	Trans_Add("Installation Problem", "Asennusongelma")
	Trans_Add("Freenet Installer fatal error", "Ohittamaton virhe asennuksessa")
	Trans_Add("Freenet Installer error", "Virhe asennuksessa")
	Trans_Add("Error: ", "Virhe: ")
	Trans_Add("E&xit", "&Poistu")

	; Installer - Error messageboxes
	Trans_Add("Freenet Installer was not able to unpack necessary installation files to:", "Freenet-asennusohjelma ei kyennyt purkamaan tarvittavia tiedostoja polkuun:")
	Trans_Add("Please make sure that Freenet Installer has full access to the system's temporary files folder.", "Varmista, että asennusohjelmalla on tarvittavat oikeudet väliaikaishakemistoon.")
	Trans_Add("Freenet Installer requires administrator privileges to install Freenet.`nPlease make sure that your user account has administrative access to the system,`nand Freenet Installer is executed with access to use these privileges.", "Asennusohjelma tarvitsee järjestelmänvalvojan oikeudet asentaakseen Freenetin.`nVarmista, että sinulla on järjestelmänvalvojan oikeudet ja asennusohjelma on käynnistetty näillä oikeuksilla.")
	Trans_Add("Freenet Installer was not able to write to the selected installation directory.`nPlease select one to which you have write access.", "Asennusohjelma ei kyennyt kirjoittamaan valittuun hakemistoon.`nValitse jokin muu, johon sinulla on kirjoitusoikeudet.")
	Trans_Add("Freenet Installer was not able to find a free port on your system in the range ", "Asennusohjelma ei löytänyt yhtään vapaata porttia väliltä ")
	Trans_Add("Please free a system port in this range to install Freenet.", "Sulje jokin ohjelma, joka varaa jonkin halutun alueen portin asentaaksesi Freenetin.")
	Trans_Add("Freenet Installer was not able to create a Winsock 2.0 socket`nfor port availability testing.", "Asennusohjelma ei kyennyt luomaan Winsock 2.0-pistoketta`ntestaakseen porttien saatavuutta.")

	; Installer - Unsupported Windows version
	Trans_Add("Freenet only supports the following versions of the Windows operating system:", "Freenet tukee vain seuraavia Windowsin versioita:")
	Trans_Add("Please install one of these versions if you want to use Freenet on Windows.", "Jos haluat käyttää Freenettiä Windowsilla, asenna vain yksi seuraavista versioista.")

	; Installer - Java missing
	Trans_Add("Freenet requires the Java Runtime Environment, but your system does not appear to have an up-to-date version installed. You can install Java by using the included online installer, which will download and install the necessary files from the Java website automatically:", "Freenet tarvitsee Java Runtime Environmentin, mutta sinulla ei näyttäisi olevan tarpeeksi uutta versiota asennettuna. Voit asentaa Javan käyttämällä mukana tulevaa asennusohjelmaa, joka lataa ja asentaa tarvittavat tiedostot automaattisesti:")
	Trans_Add("&Install Java", "&Asenna Java")
	Trans_Add("The installation will continue once Java version ", "Asennus jatkuu, kun Java-versio ")
	Trans_Add(" or later has been installed.", " tai uudempi on asennettu.")

	; Installer - Old installation detected
	Trans_Add("Freenet Installer has detected that you already have Freenet installed. Your current installation was installed using an older, unsupported installer. To continue, you must first uninstall your current version of Freenet using the previously created uninstaller:", "Asennusohjelma on huomannut, että olet jo asentanut Freenetin. Nykyinen versiosi on asennettu käytten vanhaa, epätuettua asennusohjelmaa. Jatkaaksesi, sinun täytyy poistaa nykyinen versiosi edellisen asennusohjelman poistajalla:")
	Trans_Add("&Uninstall", "&Poista")
	Trans_Add("The installation will continue once the old installation has been removed.", "Asennus jatkuu poistettuasi vanhan version.")

	; Installer - Main GUI - Header
	Trans_Add("Please check the following default settings before continuing with the installation of Freenet.", "Tarkista seuraavat vakioasetukset ennen kuin jatkat Freenetin asentamista.")

	; Installer - Main GUI - Install folder
	Trans_Add("Installation directory", "Asennushakemisto")
	Trans_Add("Freenet requires at least ", "Freenet vaatii vähintään ")
	Trans_Add(" MB free disk space, but will not install with less than ", " megatavua vapaata levytilaa, mutta ei asennu ilman vähintään ")
	Trans_Add(" MB free. The amount of space reserved can be changed after installation.", " megatavua vapaata levylitaa, mutta vaatii vähintään")
	Trans_Add("&Browse", "&Selaa")
	Trans_Add("If you do not choose a folder containing 'Freenet' in the path, a folder will be created for you automatically.", "Jos et valitse polkua, jossa on ”Freenet”, tämänniminen hakemisto luodaan automaattisesti.")
	Trans_Add("De&fault", "&Vakio")
	Trans_Add("Status:", "Tila:")
	Trans_Add("Invalid install path!", "Epäkelpo asennuspolku!")
	Trans_Add("Invalid install path! (Too long for file system to handle)", "Epäkelpo asennuspolku! (liian pitkä käyttöjärjestelmän käsiteltäväksi)")
	Trans_Add("Not enough free space on installation drive!", "Ei tarpeeksi vapaata tilaa kiintolevyllä!")
	Trans_Add("Freenet already installed! Please uninstall first or choose another directory!", "Freenet on jo asennettu! Poista vanha versio tai valitse toinen hakemisto.")
	Trans_Add("Installation directory OK!", "Asennushakemisto kunnossa.")

	; Installer - Main GUI - System service
	Trans_Add("System service", "Järjestelmäpalvelu")
	Trans_Add("Freenet will automatically start in the background as a system service. This is required to be a part of the Freenet network, and will use a small amount of system resources. The amount of resources used can be adjusted after installation.", "Freenet käynnistää itsensä automaattisesti järjestelmäpalveluna. Tämä vaaditaan ollakseen osa Freenet-verkkoa ja se kuluttaa tietyn määrän resursseja. Resurssien käyttöä voi säätää ja hallita asennuksen jälkeen")

	; Installer - Main GUI - Additional settings
	Trans_Add("Additional settings", "Lisäasetukset")
	Trans_Add("Install &start menu shortcuts (Freenet, Start Freenet, Stop Freenet)", "&Asenna käynnistä-valikon pikakuvakkeet (Freenet, Käynnistä Freenet, Pysäytä Freenet)")
	Trans_Add("Install &desktop shortcut (Freenet)", "Asenna työpöytäkuvakkeet (Freenet)")
	Trans_Add("Launch Freenet &after the installation", "Aloita Freenetin selaaminen asennuksen jälkeen")

	; Installer - Main GUI - Footer
	Trans_Add("Version ", "Versio ")
	Trans_Add(" - Build ", " — build ")
	Trans_Add("&Install", "Asenna")

	; Installer - Actual installation
	Trans_Add("Opens the Freenet proxy homepage in a web browser", "Avaa Freenetin selainkäyttöliittymän kotisivu selaimeen")
	Trans_Add("Start Freenet", "Käynnistä Freenet")
	Trans_Add("Starts the background service needed to use Freenet", "Käynnistää taustapalvelun, jota vaaditaan Freenetin käyttämiseen.")
	Trans_Add("Stop Freenet", "Pysäytä Freenet")
	Trans_Add("Stops the background service needed to use Freenet", "Pysäytä Freenetin taustapalvelu.")
	Trans_Add("Installation finished successfully!", "Asennus suoritettiin onnistuneesti.")

	; Uninstaller - Common
	Trans_Add("Freenet uninstaller", "Freenetin poistaja")
	Trans_Add("Freenet uninstaller error", "Freenetin poistajan virhe")

	; Uninstaller - General
	Trans_Add("Freenet has been uninstalled!", "Freenet poistettiin!")
	Trans_Add("Do you really want to uninstall Freenet?", "Haluatko varmasti poistaa Freenetin?")
	Trans_Add("The development team would appreciate it very much if you can`nspare a moment and fill out a short, anonymous online`nsurvey about the reason for your uninstallation.`n`nThe survey, located on the Freenet website, will be opened`nin your browser after the uninstallation.`n`nTake the uninstallation survey?", "Freenetin kehitystiimi arvostaisi, jos voit`nuhrata muutaman sekunnin vastaaksesi lyhyeen ja anonyymiin`nkyselyyn poiston syistä. Kysely on Freenetin kotisivuilla(www) ja se avautuu selaimeesi`npoistamisen jälkeen.`n`nVastaa kyselyyn?")

	; Uninstaller - Error messageboxes
	Trans_Add("The uninstaller requires administrator privileges to uninstall Freenet. Please make sure that your user account has administrative access to the system, and the uninstaller is executed with access to use these privileges.", "Poistaja vaatii järjestelmänvalvojan oikeudet poistaakseen Freenetin. Varmista, että käyttäjätunnuksellasi on tarvittavat oikeudet ja poistaja on käynnistetty näillä oikeuksilla.")
	Trans_Add("The uninstaller was not able to unpack necessary files to:", "Poistaja ei kyennyt purkamaan tarvittavia tiedostoja polkuun:")
	Trans_Add("Please make sure that the uninstaller has full access to the system's temporary files folder.", "Varmista, että poistajalla on täydet oikeudet järjestelmän väliaikaishakemistoon.")
	Trans_Add("The uninstaller was unable to recognize your Freenet installation at:", "Poistaja ei löytänyt Freenet-asennusta polusta:")
	Trans_Add("Please run this uninstaller from the 'bin' folder of a Freenet installation.", "Aja tämä poistaja Freenet-asennuksesi bin-hakemistosta.")

	; Uninstaller - Service problems
	Trans_Add("The uninstaller was unable to control the Freenet system service as it appears to be stuck.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Poistaja ei kyennyt kontrolloimaan Freenetin järjestelmäpalvelua, se näyttäisi olevan jumittunut.`n`nYritä uudelleen.`n`nJos ongelma jatkuu, raportoi tämä ongelma kehittäjille.")
	Trans_Add("The uninstaller was unable to find and control the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Poistaja ei kyennyt löytämään ja hallitsemaan Freenetin järjestelmäpalvelua.`n`nYritä uudelleen.`n`nJos tämä ongelma jatkuu, raportoi se kehittäjille.")
	Trans_Add("The uninstaller was unable to stop the Freenet system service.`n`nPlease try again.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Poistaja ei kyennyt pysäyttämään Freenetin järjestelmäpalvelua.`n`nYritä uudelleen.`n`nJos tämä ongelma jatkuu, raportoi se kehittäjille.")

	; Uninstaller - Files undeletable
	Trans_Add("The uninstaller was unable to delete the Freenet files located at:", "Poistaja ei kyennyt poistamaan Freenetin tiedostoja polusta:")
	Trans_Add("Please close all applications with open files inside this directory.", "Sulje kaikki ohjelmat, jotka ovat käynnistetty tästä hakemistosta.")
	Trans_Add("The uninstallation was aborted.`n`nPlease manually remove the rest of your Freenet installation.", "Poisto keskeytettiin.`n`nPoista loput Freenetin tiedostot käsin.")

	; Uninstaller - Progress statuses
	Trans_Add("Stopping system service...", "Pysäytetään järjestelmäpalvelua...")
	Trans_Add("Removing system service...", "Poistetaan järjestelmäpalvelua...")
	Trans_Add("Removing custom user account rights...", "Poistetaan mukautettuja käyttäjien oikeuksia...")
	Trans_Add("Removing files...", "Poistetaan tiedostoja...")
	Trans_Add("Removing registry modifications...", "Poistetaan rekisteriavaimia...")
	Trans_Add("Removing custom user...", "Poistetaan Freenet-käyttäjä...")

	; Launcher
	Trans_Add("Freenet Launcher error", "Freenet-käynnistäjän virhe")
	Trans_Add("Freenet Launcher was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Freenet-käynnistäjä ei löytänyt installid.dat-tiedostoa.`n`nVarmista, että ajat Freenet-käynnistäjän Freenetin asennushakemistosta.`nJos jo teet näin, raportoi tämä virhe kehittäjille.")
	Trans_Add("Freenet Launcher was unable to find the bin\start.exe launcher.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet-käynnistäjä ei löytänyt bin\start.exe-käynnistäjää.`n`nAsenna Freenet uudelleen.`n`nJos saat tämän virheen uudelleen, raportoi siitä kehittäjille.")
	Trans_Add("Freenet Launcher was unable to find the freenet.ini configuration file.`n`nMake sure that you are running Freenet Launcher from a Freenet installation directory.`nIf you are already doing so, please report this error message to the developers.", "Freenet-käynnistäjä ei löytänyt freenet.ini-asetustiedostoa.`n`nVarmista, että ajat Freenet-käynnistäjän Freenetin asennushakemistosta.`n`nJos teet jo niin, raportoi ongelmasta kehittäjille.")
	Trans_Add("Freenet Launcher was unable to read the 'fproxy.port' value from the freenet.ini configuration file.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet-käynnistäjä ei kyennyt lukemaan fproxy.port-arvoa tiedostosta freenet.ini.`n`nAsenna Freenet uudelleen.`n`nJos tämä ongelma jatkuu, raportoi ongelmasta kehittäjille.")
	Trans_Add("Freenet Launcher was unable to find a supported browser.`n`nPlease install one of the supported browsers, or manually`nnavigate to: ", "Freenet-käynnistäjä ei kyennyt löytämään tuettua selainta.`n`nAsenna yksi tuetuista selaimista tai käy manuaalisesti osoitteessa ")
	Trans_Add("Freenet Launcher supports the following browsers:", "Freenet-käynnistäjä tukee seuraavia selaimia:")
	Trans_Add("not recommended", "ei suositeltu")

	; Service starter
	Trans_Add("Command line options (only use one):`n/silent - Hide info messages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service started)`n1 - Error occurred`n2 - Service was already running (no action)", "Komentoriviasetukset (käytä vain yhtä):`n/silent — Piilota tiedotteet`n/verysilent — Piilota tiedotteet ja tilanneviestit`n`nReturn codes:`n0 = onnistut suoritus(palvelu käynnistetty)`n1 = Virhe`n2=Palvelu on jo käynnissä(ei suoritettuja toimintoja)")
	Trans_Add("Freenet start script requires administrator privileges to start the Freenet service. Please make sure that your user account has administrative access to the system, and the start script is executed with access to use these privileges.", "Freenetin käynnistysskripti vaatii järjestelmänvalvojan oikeudet käynnistääkseen Freenetin. Varmista, että sinulla on järjestelmänvalvojan oikeudet ja tämä skripti on käynnistetty näillä oikeuksilla.")
	Trans_Add("Freenet start script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet start script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "Freenetin käynnistysskripti ei kyennyt löytämään installid.dat-tiedostoa.`n`nVarmista, että ajat skriptiä bin-kansiosta Freenetin hakemistosta. Jos jo teet niin, raportoi tämä bugi.")
	Trans_Add("Freenet start script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenetin käynnistysskripti ei kyennyt kontrolloimaan Freenetin järjestelmäpalvelua, se näyttäisi olevan jumissa.`n`nUudelleenasenna Freenet.")
	Trans_Add("Freenet start script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Käynnistysskripti ei löytänyt Freenetin järjestelmäpalvelua.`n`nAsenna Freenet uudelleen.")
	Trans_Add("Waiting for the Freenet background service to start...", "Käynnistetään Freenetin taustapalvelua...")
	Trans_Add("Freenet start script", "Freenetin käynnistysskripti")
	Trans_Add("Freenet start script was unable to start the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenetin käynnistysskripti ei kyennyt käynnistämään Freenetin järjestelmäpalvelua.`n`nAsenna Freenet uudelleen.")
	Trans_Add("The Freenet service has been started!", "Freenet-palvelu on käynnistetty.")
	Trans_Add("The Freenet service is already running!", "Freenet-palvelu on jo käynnissä!")
	Trans_Add("Freenet start script error", "Freenet-käynnistysskriptivirhe.")

	; Service stopper
	Trans_Add("Command line options (only use one):`n/silent - Hide info messsages`n/verysilent - Hide info and status messages`n`nReturn codes:`n0 - Success (service stopped)`n1 - Error occurred`n2 - Service was not running (no action)", "Komentoriviasetukset (käytä vain yhtä):`n/silent — Piilota tiedotteet`n/verysilent — Piilota tiedotteet ja tilanneviestit`n`nReturn codes:`n0 = onnistut suoritus(palvelu käynnistetty)`n1 = Virhe`n2=Palvelu on jo käynnissä(ei suoritettuja toimintoja)")
	Trans_Add("Freenet stop script requires administrator privileges to stop the Freenet service. Please make sure that your user account has administrative access to the system, and the stop script is executed with access to use these privileges.", "Freenetin pysäytysskripti vaatii järjestelmänvalvojan oikeudet.")
	Trans_Add("Freenet stop script was unable to find the installid.dat ID file.`n`nMake sure that you are running Freenet stop script from the 'bin' folder of a Freenet installation directory. If you are already doing so, please report this error message to the developers.", "Tiedostoa installid.dat ei löytynyt. Varmista, että olet Freenetin bin-hakemistossa.")
	Trans_Add("Freenet stop script was unable to control the Freenet system service as it appears to be stuck.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet-palvelua ei kyetty pysäyttämään, sillä se on jumissa. Asenna Freenet uudelleen.")
	Trans_Add("Freenet stop script was unable to find and control the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet-palvelua ei löytynyt. Asenna Freenet uudelleen.")
	Trans_Add("Waiting for the Freenet background service to stop...", "Odotetaan Freenetin taustapalvelua pysähtymään...")
	Trans_Add("Freenet stop script", "Freenetin pysäytysskripti")
	Trans_Add("The Freenet service has been stopped!", "Freenet-palvelu on pysäytetty.")
	Trans_Add("The Freenet service is already stopped!", "Freenet-palvelu oli jo pysäytetty!")
	Trans_Add("Freenet stop script was unable to stop the Freenet system service.`n`nPlease reinstall Freenet.`n`nIf the problem keeps occurring, please report this error message to the developers.", "Freenet-palvelua ei kyetty pysäyttämään. Asenna Freenet uudelleen.")
	Trans_Add("Freenet stop script error", "Freenetin pysäytysskriptin virhe")
}

