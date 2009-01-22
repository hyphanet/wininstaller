@echo off
::
:: Not-committed requirements:
:: - bin\freenet.jar
:: - bin\freenet-ext.jar
:: - bin\Ahk2Exe.exe (AutoHotKey compiler)
:: - bin\upx.exe (UPX packer, comes with AutoHotKey compiler)
:: - bin\JSTUN.jar
:: - bin\KeyExplorer.jar
:: - bin\ThawIndexBrowser.jar
:: - bin\UPnP.jar
:: - bin\XMLLibrarian.jar
::

::
:: Cleanup and prepare
::
if exist bin\FreenetInstaller.exe del bin\FreenetInstaller.exe /Q
copy bin\freenet.jar src_freenetinstaller\files_install\freenet.jar
copy bin\freenet-ext.jar src_freenetinstaller\files_install\freenet-ext.jar
copy bin\Ahk2Exe.exe compiler\Ahk2Exe.exe
copy bin\upx.exe compiler\upx.exe
copy bin\JSTUN.jar src_freenetinstaller\files_install\plugins\JSTUN.jar
copy bin\KeyExplorer.jar src_freenetinstaller\files_install\plugins\KeyExplorer.jar
copy bin\ThawIndexBrowser.jar src_freenetinstaller\files_install\plugins\ThawIndexBrowser.jar
copy bin\UPnP.jar src_freenetinstaller\files_install\plugins\UPnP.jar
copy bin\XMLLibrarian.jar src_freenetinstaller\files_install\plugins\XMLLibrarian.jar

::
:: Compile non-Vista-elevated executables
::
copy compiler\AutoHotkeySC_Normal.bin compiler\AutoHotkeySC.bin

compiler\Ahk2Exe.exe /in "src_freenethelpers\FreenetLauncher.ahk" /out "src_freenetinstaller\files_install\freenetlauncher.exe"

del compiler\AutoHotkeySC.bin

::
:: Compile Vista-elevated executables
::
copy compiler\AutoHotkeySC_VistaElevated.bin compiler\AutoHotkeySC.bin

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
del src_freenetinstaller\files_install\freenet.jar
del src_freenetinstaller\files_install\freenet-ext.jar
del src_freenetinstaller\files_install\freenetlauncher.exe
del src_freenetinstaller\files_install\bin\start.exe
del src_freenetinstaller\files_install\bin\stop.exe
del src_freenetinstaller\files_install\bin\freenetuninstaller.exe
del src_freenetinstaller\files_install\plugins\JSTUN.jar
del src_freenetinstaller\files_install\plugins\KeyExplorer.jar
del src_freenetinstaller\files_install\plugins\ThawIndexBrowser.jar
del src_freenetinstaller\files_install\plugins\UPnP.jar
del src_freenetinstaller\files_install\plugins\XMLLibrarian.jar
