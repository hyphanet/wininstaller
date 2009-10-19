@echo off
::
:: Non-committed requirements:
::
:: - bin\Ahk2Exe.exe (AutoHotkey compiler - http://www.autohotkey.com/)
:: - bin\upx.exe (UPX packer, comes with AutoHotkey compiler)
:: - bin\AutoHotkeySC.bin (AHK library, comes with AutoHotkey compiler)
::
:: - bin\freenet.jar (Freenet jar)
:: - bin\freenet-ext.jar (Freenet jar)
::
:: - bin\JSTUN.jar (Freenet plugin jar)
:: - bin\KeyExplorer.jar (Freenet plugin jar)
:: - bin\ThawIndexBrowser.jar (Freenet plugin jar)
:: - bin\UPnP.jar (Freenet plugin jar)
:: - bin\Library.jar (Freenet plugin jar)
::
:: - src_freenetinstaller\files_install\seednodes.fref (seednodes file)
::

::
:: Cleanup and prepare
::
if exist bin\FreenetInstaller.exe del bin\FreenetInstaller.exe
if not exist src_freenetinstaller\files_install\plugins mkdir src_freenetinstaller\files_install\plugins
copy bin\freenet.jar src_freenetinstaller\files_install\freenet.jar
copy bin\freenet-ext.jar src_freenetinstaller\files_install\freenet-ext.jar
copy bin\Ahk2Exe.exe compiler\Ahk2Exe.exe
copy bin\upx.exe compiler\upx.exe
copy bin\ResHacker.exe compiler\ResHacker.exe
copy bin\JSTUN.jar src_freenetinstaller\files_install\plugins\JSTUN.jar
copy bin\KeyExplorer.jar src_freenetinstaller\files_install\plugins\KeyExplorer.jar
copy bin\ThawIndexBrowser.jar src_freenetinstaller\files_install\plugins\ThawIndexBrowser.jar
copy bin\UPnP.jar src_freenetinstaller\files_install\plugins\UPnP.jar
copy bin\Library.jar src_freenetinstaller\files_install\plugins\Library.jar

::
:: Patch AHK library
::
copy bin\AutoHotkeySC.bin compiler\AutoHotkeySC.bin
cd compiler

ResHacker.exe -script ResHack_Script_Normal.txt
ResHacker.exe -script ResHack_Script_VistaElevated.txt

cd ..
del compiler\AutoHotkeySC.bin

::
:: Compile non-Vista-elevated executables
::
move /Y compiler\AutoHotkeySC_Normal.bin compiler\AutoHotkeySC.bin

compiler\Ahk2Exe.exe /in "src_freenethelpers\FreenetLauncher.ahk" /out "src_freenetinstaller\files_install\freenetlauncher.exe"

del compiler\AutoHotkeySC.bin

::
:: Compile Vista-elevated executables
::
move /Y compiler\AutoHotkeySC_VistaElevated.bin compiler\AutoHotkeySC.bin

compiler\Ahk2Exe.exe /in "src_freenetinstaller\FreenetInstaller_Uninstaller.ahk" /out "src_freenetinstaller\files_install\bin\freenetuninstaller.exe"
compiler\Ahk2Exe.exe /in "src_freenethelpers\FreenetStart.ahk" /out "src_freenetinstaller\files_install\bin\start.exe"
compiler\Ahk2Exe.exe /in "src_freenethelpers\FreenetStop.ahk" /out "src_freenetinstaller\files_install\bin\stop.exe"

compiler\Ahk2Exe.exe /in "src_freenetinstaller\FreenetInstaller.ahk" /out "bin\FreenetInstaller.exe"

del compiler\AutoHotkeySC.bin

::
:: Cleanup
::
del compiler\Ahk2Exe.exe
del compiler\upx.exe
del compiler\ResHacker.exe
del compiler\ResHacker.ini
del compiler\ResHack_Log_Normal.txt
del compiler\ResHack_Log_VistaElevated.txt
del src_freenetinstaller\files_install\freenet.jar
del src_freenetinstaller\files_install\freenet-ext.jar
copy src_freenetinstaller\files_install\freenetlauncher.exe bin\
del src_freenetinstaller\files_install\freenetlauncher.exe
copy src_freenetinstaller\files_install\bin\start.exe bin\
del src_freenetinstaller\files_install\bin\start.exe
copy src_freenetinstaller\files_install\bin\stop.exe bin\
del src_freenetinstaller\files_install\bin\stop.exe
copy src_freenetinstaller\files_install\bin\freenetuninstaller.exe bin\
del src_freenetinstaller\files_install\bin\freenetuninstaller.exe
del src_freenetinstaller\files_install\plugins\JSTUN.jar
del src_freenetinstaller\files_install\plugins\KeyExplorer.jar
del src_freenetinstaller\files_install\plugins\ThawIndexBrowser.jar
del src_freenetinstaller\files_install\plugins\UPnP.jar
del src_freenetinstaller\files_install\plugins\Library.jar
