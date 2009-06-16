;
; Windows Freenet Installer - Include file - File installs
;
; This file contains the raw installation commands for the node files, and will be included directly
; into the installer at compile time.
;
; The FileInstall command handles both the packing (path as argument 1) and unpacking (path as
; argument 2) of the file.
;
; Remember to create any directories with FileCreateDir before doing FileInstalls to them.
;

FileCreateDir,							%_InstallDir%
FileInstall, files_install\freenet.ico,				%_InstallDir%\freenet.ico
FileInstall, files_install\freenet.jar,				%_InstallDir%\freenet.jar
FileInstall, files_install\freenet-ext.jar,			%_InstallDir%\freenet-ext.jar
FileInstall, files_install\freenetlauncher.exe,			%_InstallDir%\freenetlauncher.exe
FileInstall, files_install\freenetoffline.ico,			%_InstallDir%\freenetoffline.ico
FileInstall, files_install\LICENSE.Freenet,			%_InstallDir%\LICENSE.Freenet
FileInstall, files_install\LICENSE.Mantissa,			%_InstallDir%\LICENSE.Mantissa
FileInstall, files_install\seednodes.fref,			%_InstallDir%\seednodes.fref
FileInstall, files_install\startssl.pem,			%_InstallDir%\startssl.pem
FileInstall, files_install\wrapper.conf,			%_InstallDir%\wrapper.conf
FileInstall, files_install\update.cmd,				%_InstallDir%\update.cmd

FileCreateDir,							%_InstallDir%\bin
FileInstall, files_install\bin\freenettray.exe,			%_InstallDir%\bin\freenettray.exe
FileInstall, files_install\bin\freenetuninstaller.exe,		%_InstallDir%\bin\freenetuninstaller.exe
FileInstall, files_install\bin\start.exe,			%_InstallDir%\bin\start.exe
FileInstall, files_install\bin\stop.exe,			%_InstallDir%\bin\stop.exe
FileInstall, files_install\bin\wget.exe,			%_InstallDir%\bin\wget.exe
FileInstall, files_install\bin\wrapper-windows-x86-32.exe,	%_InstallDir%\bin\wrapper-windows-x86-32.exe


FileCreateDir,							%_InstallDir%\lib
FileInstall, files_install\lib\sha1test.jar,			%_InstallDir%\lib\sha1test.jar
FileInstall, files_install\lib\wrapper-windows-x86-32.dll,	%_InstallDir%\lib\wrapper-windows-x86-32.dll

FileCreateDir,							%_InstallDir%\plugins
FileInstall, files_install\plugins\JSTUN.jar,			%_InstallDir%\plugins\JSTUN.jar
FileInstall, files_install\plugins\KeyExplorer.jar,		%_InstallDir%\plugins\KeyExplorer.jar
FileInstall, files_install\plugins\ThawIndexBrowser.jar,	%_InstallDir%\plugins\ThawIndexBrowser.jar
FileInstall, files_install\plugins\UPnP.jar,			%_InstallDir%\plugins\UPnP.jar
FileInstall, files_install\plugins\XMLLibrarian.jar,		%_InstallDir%\plugins\XMLLibrarian.jar
