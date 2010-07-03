;
; Freenet Windows Installer - Include file - File installs
;
; This file contains the raw installation commands for the node files, and will be included directly
; into the installer at compile time.
;
; The FileInstall command handles both the packing (path as argument 1) and unpacking (path as
; argument 2) of the file.
;
; Remember to create any directories with FileCreateDir before doing FileInstalls to them.
;

FileCreateDir,								%_InstallDir%
FileInstall, ..\..\res\install_node\freenet.ico,			%_InstallDir%\freenet.ico
FileInstall, ..\..\res\install_node\freenet.jar,			%_InstallDir%\freenet.jar
FileInstall, ..\..\res\install_node\freenet-ext.jar,			%_InstallDir%\freenet-ext.jar
FileInstall, ..\..\res\install_node\freenet.exe,			%_InstallDir%\freenet.exe
FileInstall, ..\..\res\install_node\freenetlauncher.exe,		%_InstallDir%\freenetlauncher.exe
FileInstall, ..\..\res\install_node\freenetuninstaller.exe,		%_InstallDir%\freenetuninstaller.exe
FileInstall, ..\..\res\install_node\freenetwrapper.conf,		%_InstallDir%\freenetwrapper.conf
FileInstall, ..\..\res\install_node\freenetwrapper.dll,			%_InstallDir%\freenetwrapper.dll
FileInstall, ..\..\res\install_node\freenetwrapper.exe,			%_InstallDir%\freenetwrapper.exe
FileInstall, ..\..\res\install_node\seednodes.fref,			%_InstallDir%\seednodes.fref

FileCreateDir,								%_InstallDir%\licenses
FileInstall, ..\..\res\install_node\licenses\LICENSE.Freenet,		%_InstallDir%\licenses\LICENSE.Freenet
FileInstall, ..\..\res\install_node\licenses\LICENSE.Mantissa,		%_InstallDir%\licenses\LICENSE.Mantissa

FileCreateDir,								%_InstallDir%\plugins
FileInstall, ..\..\res\install_node\plugins\JSTUN.jar,			%_InstallDir%\plugins\JSTUN.jar
FileInstall, ..\..\res\install_node\plugins\KeyUtils.jar,		%_InstallDir%\plugins\KeyUtils.jar
FileInstall, ..\..\res\install_node\plugins\ThawIndexBrowser.jar,	%_InstallDir%\plugins\ThawIndexBrowser.jar
FileInstall, ..\..\res\install_node\plugins\UPnP.jar,			%_InstallDir%\plugins\UPnP.jar
FileInstall, ..\..\res\install_node\plugins\Library.jar,		%_InstallDir%\plugins\Library.jar
