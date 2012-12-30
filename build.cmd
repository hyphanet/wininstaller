@echo off
::
:: This script will build the Freenet Windows Installer.
::
:: To build from a Windows command prompt: "build.cmd"
:: To build from a linux terminal: "wine cmd /c build.cmd"
::
:: The following files are not packed and need to be manually added before compiling:
::
:: From http://l.autohotkey.net/Ahk2Exe_L.zip
:: - res\tool_ahk\Ahk2Exe.exe
:: - res\tool_ahk\Unicode 32-bit.bin
::
:: - res\install_node\freenet.jar (Freenet jar)
:: - res\install_node\freenet-ext.jar (Freenet jar)
:: - res\install_node\seednodes.fref (Freenet seednodes file)
:: - res\install_node\bcprov-jdk15on-147.jar (Bouncycastle crypto library)
::
:: - res\install_node\plugins\JSTUN.jar (Freenet plugin jar)
:: - res\install_node\plugins\KeyUtils.jar (Freenet plugin jar)
:: - res\install_node\plugins\ThawIndexBrowser.jar (Freenet plugin jar)
:: - res\install_node\plugins\UPnP.jar (Freenet plugin jar)
:: - res\install_node\plugins\Library.jar (Freenet plugin jar)
::
:: Remember to update src\freenetinstaller\FreenetInstaller_Include_Info.inc with the latest version information.

:: If running under Wine, you should install the relevant wine-gecko MSI file where wine expects to find it.

::
:: Cleanup and prepare
::
echo +++++
echo + Preparing bin folder...

if exist bin rmdir /S /Q bin

echo + (Ignore any "not found" errors above this line (WINE bug at time of writing))

mkdir bin
cd bin

::
:: Copy various files to our bin folder
::
echo + Copying files into bin folder...

copy ..\res\tool_ahk\Ahk2Exe.exe Ahk2Exe.exe
copy "..\res\tool_ahk\Unicode 32-bit.bin" "Unicode 32-bit.bin"

::
:: Compile non-elevated executables
::
echo + Compiling executables...
echo +++++

Ahk2Exe.exe /in "..\src\freenetlauncher\FreenetLauncher.ahk" /out "..\res\install_node\freenetlauncher.exe" /bin "Unicode 32-bit.bin" /icon "..\res\install_node\freenet.ico"
echo Compiled freenetlauncher.exe
Ahk2Exe.exe /in "..\src\freenettray\FreenetTray.ahk" /out "..\res\install_node\freenet.exe" /bin "Unicode 32-bit.bin" /icon "..\res\install_node\freenet.ico"
echo Compiled freenet.exe
Ahk2Exe.exe /in "..\src\freenetuninstaller\FreenetUninstaller.ahk" /out "..\res\install_node\freenetuninstaller.exe" /bin "Unicode 32-bit.bin" /icon "..\res\install_node\freenet.ico"
echo Compiled freenetuninstaller.exe
Ahk2Exe.exe /in "..\src\freenetinstaller\FreenetInstaller.ahk" /out "FreenetInstaller.exe" /bin "Unicode 32-bit.bin" /icon "..\res\install_node\freenet.ico"
echo Compiled FreenetInstaller.exe

::
:: Cleanup and delete files we copied into the source and move compiled .exe's to the bin folder in case we need them for something else.
::
echo +++++
echo + Cleaning up...
del Ahk2Exe.exe
del "Unicode 32-bit.bin"

echo + Fetching executables into bin folder
move ..\res\install_node\freenetlauncher.exe freenetlauncher.exe
move ..\res\install_node\freenet.exe freenet.exe
move ..\res\install_node\freenetuninstaller.exe freenetuninstaller.exe

echo +++++
echo + All done! Hopefully no errors above...
echo +++++

cd ..
