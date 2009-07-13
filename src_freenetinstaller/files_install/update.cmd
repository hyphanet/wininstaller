@echo off
::This script is designed for the Windows command line shell, so please don't put it into anything else! :)
::This script may need to be run with administrator privileges.

::If you want to debug this script by adding pauses and stuff, please do it from another batch file, because
::if you modify this script in any way it will be detected as outdated and will be overwritten on the next run.
::To force a re-download of the latest Freenet.jar, simply delete freenet-%RELEASE%-latest.jar.url before running this script.

::The default behavior is to fetch the latest stable release.  Run this script with the testing parameter for the latest SVN build.
::  e.g. C:\Freenet\update.cmd testing

Title Freenet Update Over HTTP Script
echo -----
echo - Freenet Windows update script 1.6 by Zero3Cool (zero3cool@zerosplayground.dk)
echo - Further contributions by Juiceman (juiceman69@gmail.com)
echo - Thanks to search4answers, Michael Schierl and toad for help and feedback.
echo -----
echo - This script will automatically update your Freenet installation
echo - from our web server freenetproject.org and/or mirrors.
echo - In case of an unrecoverable error, this script will pause.
echo -----
echo -----------------------------------------------------------
echo - Please try to use the update over Freenet feature of your
echo - node to reduce traffic on our servers, thanks!!!
echo - FYI, updating over Freenet is easy, more secure and
echo - is better for your anonymity.
echo -----------------------------------------------------------
echo -----

:: TODO:
:: Update all the Windows binaries using this script.
:: Fixme: what to do with changing away from custom freenet user account?

:: CHANGELOG:
:: 3.3 - Refactored script to be more organized and prepare for updating Windows binaries
:: 3.2 - Use the .sha1 url to check for updates to freenet-ext.jar.  Saves ~4mb per run.
:: 3.1 - Fix permissions by fixing invalid cacls arguments
:: 3.0 - Handle binary start/stop.exe exit conditions and use it to set restart flag.
:: 2.9 - Check for file permissions
:: 2.8 - Add detecting of Vista\Seven, use the appropriate version of cacls.
:: 2.7 - Better error handling
:: 2.6 - Prepare for new binary start and stop.exe's
:: ---   Many various changes
:: 2.4 - Test downloaded jar after making sure it is not empty.  Copy over freenet.jar after testing for integrity.
:: 2.3 - Reduce retries to 5.  Turn on file resuming.  Clarify text.
:: 2.2 - Reduce retry delay and time between retries.
:: 2.1 - Title, comments, hide "Please ignore, it is a side effect of a work-around" echo unless its needed.
:: 2.0 - Warn user not to abort script.
:: 1.9 - Cosmetic fixes (Spacing, typos)
:: 1.8 - Loop stop script until Node is stopped.
:: 1.7 - Retry downloads on timeout.

::Initialize some stuff
set MAGICSTRING=INDO
set CAFILE=startssl.pem
set RESTART=0
set MAINJARUPDATED=0
set EXTJARUPDATED=0
set PATH=%SYSTEMROOT%\System32\;%PATH%
set RELEASE=stable
if "%1"=="testing" set RELEASE=testing
if "%1"=="-testing" set RELEASE=testing
if "%1"=="/testing" set RELEASE=testing

echo - Release selected is: %RELEASE%
echo -----

::Check if we are on Vista/Seven if so we need to use icacls instead of cacls
set VISTA=0
::Treat server 2k3/XP64 as vista as they need icacls
VER | findstr /l "5.2." > nul
IF %ERRORLEVEL% EQU 0 set VISTA=1
::Vista?
VER | findstr /l "6.0." > nul
IF %ERRORLEVEL% EQU 0 set VISTA=1
::Seven?
VER | findstr /l "6.1." > nul
IF %ERRORLEVEL% EQU 0 set VISTA=1

::Go to our location
for %%I in (%0) do set LOCATION=%%~dpI
cd /D "%LOCATION%"

::Check if its valid, or at least looks like it
if not exist freenet.ini goto error2
if not exist bin\wget.exe goto error2

::Simple test to see if we have enough privileges to modify files.
echo - Checking file permissions
if exist writetest del writetest > NUL
if exist writetest goto writefail
echo test > writetest
if not exist writetest goto writefail
del writetest > NUL
if exist writetest goto writefail

:: Maybe fix bug #2556
echo - Changing file permissions
if %VISTA%==0 echo Y| cacls . /E /T /C /G freenet:f > NUL
if %VISTA%==1 echo y| icacls . /grant freenet:(OI)(CI)F /T /C > NUL

::Get the filename and skip straight to the Freenet update if this is a new updater
for %%I in (%0) do set FILENAME=%%~nxI
if %FILENAME%==update.new.cmd goto updaterok

::Download latest updater and verify it
if exist update.new.cmd del update.new.cmd
echo - Checking for newer version of this update script...
bin\wget.exe -o NUL -c --timeout=5 --tries=5 --waitretry=10 http://downloads.freenetproject.org/alpha/update/update-new.cmd -O update.new.cmd
Title Freenet Update Over HTTP Script

if not exist update.new.cmd goto error1
find "FREENET W%MAGICSTRING%WS UPDATE SCRIPT" update.new.cmd > NUL
if errorlevel 1 goto error1

::Check if updater has been updated
fc update.cmd update.new.cmd > NUL
if not errorlevel 1 goto updaterok

::It has! Run new version and end self
echo - New update script found, restarting update script...
echo -----
start update.new.cmd
goto veryend

::Updater is up to date, check Freenet
:updaterok
echo    - Update script is current.
echo -----

find "freenet.jar" wrapper.conf > NUL
if errorlevel 1 goto error5

find "freenet.jar.new" wrapper.conf > NUL
if not errorlevel 1 goto error5

:: fix #1527
find "freenet-ext.jar.new" wrapper.conf > NUL
if errorlevel 1 goto skipit
if not exist freenet-ext.jar.new goto skipit
if exist freenet-ext.jar del /F freenet-ext.jar > NUL
copy freenet-ext.jar.new freenet-ext.jar > NUL
:: Try to delete the file.  If the node is running, it will likely fail.
if exist freenet-ext.jar.new del /F freenet-ext.jar.new > NUL
:: Fix the wrapper.conf
goto error5
:skipit


echo - Freenet installation found at %LOCATION%
echo -----
echo - Checking for Freenet JAR updates...
echo -----

::Check for sha1test and download if needed.
if not exist lib mkdir lib
if not exist lib\sha1test.jar bin\wget.exe -o NUL -c --timeout=5 --tries=5 --waitretry=10  http://downloads.freenetproject.org/alpha/installer/sha1test.jar -O lib\sha1test.jar
if not errorlevel 0 goto error3

if not exist update_temp mkdir update_temp

::Check for a new main jar
echo - Checking main jar
if exist freenet-%RELEASE%-latest.jar.new.url.bak del freenet-%RELEASE%-latest.jar.new.url.bak
if exist freenet-%RELEASE%-latest.jar.new.url ren freenet-%RELEASE%-latest.jar.new.url freenet-%RELEASE%-latest.jar.new.url.bak
bin\wget.exe -o NUL -c --timeout=5 --tries=5 --waitretry=10 http://downloads.freenetproject.org/alpha/freenet-%RELEASE%-latest.jar.url -O freenet-%RELEASE%-latest.jar.new.url
Title Freenet Update Over HTTP Script

if not exist freenet-%RELEASE%-latest.jar.new.url goto error3
FOR %%I IN ("%LOCATION%freenet-%RELEASE%-latest.jar.url") DO if %%~zI==0 goto error3

::Do we have something old to compare with? If not, update right away
if not exist freenet-%RELEASE%-latest.jar.url goto mainyes

::Compare with current copy
fc freenet-%RELEASE%-latest.jar.url freenet-%RELEASE%-latest.jar.new.url > NUL
if errorlevel 1 goto mainyes
echo    - Main jar is current.
goto maincheckend

:mainyes
:: Handle loop if there is no old URL to compare to.
if not exist freenet-%RELEASE%-latest.jar.url copy freenet-%RELEASE%-latest.jar.new.url freenet-%RELEASE%-latest.jar.url > NUL
echo    - New main jar found!
set MAINJARUPDATED=1
:maincheckend

:checkext
::Check for a new freenet-ext.jar.
echo - Checking ext jar

if exist update_temp\freenet-ext.jar.sha1.new.bak del update_temp\freenet-ext.jar.sha1.new.bak
if exist update_temp\freenet-ext.jar.sha1.new ren update_temp\freenet-ext.jar.sha1.new freenet-ext.jar.sha1.new.bak
bin\wget.exe -o NUL -c --timeout=5 --tries=5 --waitretry=10 http://downloads.freenetproject.org/alpha/freenet-ext.jar.sha1 -O update_temp\freenet-ext.jar.sha1.new
Title Freenet Update Over HTTP Script

if not exist update_temp\freenet-ext.jar.sha1.new goto error3
FOR %%I IN ("update_temp\freenet-ext.jar.sha1.new") DO if %%~zI==0 goto error3

::Do we have something old to compare with? If not, update right away
if not exist update_temp\freenet-ext.jar.sha1 goto extyes

fc update_temp\freenet-ext.jar.sha1 update_temp\freenet-ext.jar.sha1.new > NUL
if errorlevel 1 goto extyes
echo    - ext jar is current.
goto extcheckend

:extyes
echo    - New ext jar found!
set EXTJARUPDATED=1
:extcheckend

::Check if we have flagged any of the files as updated
if %MAINJARUPDATED%==1 goto updatebegin
if %EXTJARUPDATED%==1 goto updatebegin
goto noupdate

::New version found, check if the node is currently running
:updatebegin
echo -----
echo - New Freenet version found!  Installing now...
echo -----

::See if we are using the new binary stop.exe
if not exist bin\stop.exe goto oldstopper
:newstoppper
call bin\stop.exe /silent
if errorlevel 0 set RESTART=1
if errorlevel 1 goto unknownerror
goto begindownloads

:oldstopper
net start | find "Freenet 0.7 darknet" > NUL
if errorlevel 1 goto begindownloads > NUL
set RESTART=1
::Tell the user not to abort script, it gets very messy.
echo - Shutting down Freenet...   (This may take a moment, please don't abort)
call bin\stop.cmd > NUL
net start | find "Freenet 0.7 darknet" > NUL
if errorlevel 1 goto begindownloads
:: Uh oh, this may take a few tries.  Better tell the user not to panic.
echo -
echo - If you see an error message about:
echo - "The service could not be controlled in its present state."
echo - Please ignore, it is a side effect of a work-around
echo - to make sure the node is stopped before we copy files.
echo -
::Keep trying until service is stopped for sure.
:safetycheck
net start | find "Freenet 0.7 darknet" > NUL
if errorlevel 1 goto begindownloads
call bin\stop.cmd > NUL
goto safetycheck

::Ok Freenet is stopped, it is safe to copy files.
:begindownloads
echo - Backing up files...
::Backup last version of Freenet-%RELEASE%-latest.jar file, we will need it if update fails.
if exist freenet-%RELEASE%-latest.jar.bak del freenet-%RELEASE%-latest.jar.bak
if exist freenet-%RELEASE%-latest.jar ren freenet-%RELEASE%-latest.jar freenet-%RELEASE%-latest.jar.bak
::Backup last version of Freenet-ext.jar file, we will need it if update fails.
if exist update_temp\freenet-ext.jar.bak del update_temp\freenet-ext.jar.bak
if exist freenet-ext.jar copy freenet-ext.jar update_temp\freenet-ext.jar.bak > NUL


echo - Downloading new files and updating local installation...
echo -----

::Download new main jar file
if %MAINJARUPDATED%==0 goto mainjardownloadend
bin\wget.exe -o NUL -c --timeout=5 --tries=5 --waitretry=10 -i freenet-%RELEASE%-latest.jar.new.url -O freenet-%RELEASE%-latest.jar
Title Freenet Update Over HTTP Script
:: Make sure it got downloaded successfully
if not exist freenet-%RELEASE%-latest.jar goto error4
FOR %%I IN ("%LOCATION%freenet-%RELEASE%-latest.jar") DO if %%~zI==0 goto error4
::Test the new file for integrity.
java -cp lib\sha1test.jar Sha1Test freenet-%RELEASE%-latest.jar . %CAFILE%
if not errorlevel 0 goto error4
echo - Freenet-%RELEASE%-snapshot.jar downloaded and verified
:mainjardownloadend

::Download new ext jar file
if %EXTJARUPDATED%==0 goto extjardownloadend
if exist update_temp\freenet-ext.jar del update_temp\freenet-ext.jar
bin\wget.exe -o NUL -c --timeout=5 --tries=5 --waitretry=10 https://checksums.freenetproject.org/cc/freenet-ext.jar -O update_temp\freenet-ext.jar
Title Freenet Update Over HTTP Script
if not exist update_temp\freenet-ext.jar goto error4
FOR %%I IN ("%LOCATION%update_temp\freenet-ext.jar") DO if %%~zI==0 goto error4
::Test the new file for integrity.
cd update_temp\
java -cp ..\lib\sha1test.jar Sha1Test freenet-ext.jar . ..\%CAFILE% > NUL
if not errorlevel 0 goto error4
cd..
echo - Freenet-ext.jar downloaded and verified
:extjardownloadend

Title Freenet Update Over HTTP Script

::Everything looks good, lets install it
echo -----
if %MAINJARUPDATED%==0 goto maincopyend
copy freenet-%RELEASE%-latest.jar freenet.jar > NUL
::Prepare shortcut file for next run.
if exist freenet-%RELEASE%-latest.jar.url del freenet-%RELEASE%-latest.jar.url
ren freenet-%RELEASE%-latest.jar.new.url freenet-%RELEASE%-latest.jar.url
echo - Freenet-%RELEASE%-snapshot.jar copied to freenet.jar
:maincopyend

if %EXTJARUPDATED%==0 goto extcopyend
copy update_temp\freenet-ext.jar freenet-ext.jar > NUL
echo - Copied updated freenet-ext.jar
:extcopyend


goto end

::No update needed
:noupdate
echo -----
echo - Freenet is already up to date.
goto end

::Server gave us a damaged version of the update script, tell user to try again later.
:error1
echo - Error! Downloaded update script is invalid. Try again later.
goto end

::Can't find Freenet installation
:error2
echo - Error! Please run this script from a working Freenet installation.
echo -----
pause
goto veryend

::Server may be down.
:error3
echo - Error! Could not download latest Freenet update information. Try again later.
goto end

::Corrupt file was downloaded, restore from backup.
:error4
echo - Error! Freenet update failed, trying to restore backups...
::Main jar
if exist freenet-%RELEASE%-latest.jar del freenet-%RELEASE%-latest.jar
if exist freenet-%RELEASE%-latest.jar.bak ren freenet-%RELEASE%-latest.jar.bak freenet-%RELEASE%-latest.jar
if exist freenet-%RELEASE%-latest.jar.new.url del freenet-%RELEASE%-latest.jar.new.url
if exist freenet-%RELEASE%-latest.jar.new.url.bak ren freenet-%RELEASE%-latest.jar.new.url.bak freenet-%RELEASE%-latest.jar.new.url

::Ext jar
if exist freenet-ext.jar del freenet-ext.jar
if exist update_temp\freenet-ext.jar.bak copy update_temp\freenet-ext.jar.bak freenet-ext.jar
if exist update_temp\freenet-ext.jar.sha1.new del update_temp\freenet-ext.jar.sha1.new
if exist update_temp\freenet-ext.jar.sha1.new.bak ren update_temp\freenet-ext.jar.sha1.new.bak freenet-ext.jar.sha1.new

goto end

::Wrapper.conf is old, downloading new version and restarting update script
:error5
echo - Your wrapper.conf needs to be updated .... updating it ; please restart the script when done.
:: Let's try falling back to the old version of the wrapper so we can keep our memory settings.  If it doesn't work we'll get a new one next time around.
if not exist wrapper.conf.bak goto newwrapper
if exist wrapper.conf del wrapper.conf
ren wrapper.conf.bak wrapper.conf
start update.new.cmd
goto veryend

:newwrapper
if exist wrapper.conf ren wrapper.conf wrapper.conf.bak
:: This will set the memory settings back to default, but it can't be helped.
bin\wget.exe -o NUL -c --timeout=5 --tries=5 --waitretry=10 http://downloads.freenetproject.org/alpha/update/wrapper.conf -O wrapper.conf
if not exist wrapper.conf goto wrappererror
if exist wrapper.password type wrapper.password >> wrapper.conf
start update.new.cmd
goto veryend

:wrappererror
if exist wrapper.conf.bak ren wrapper.conf.bak wrapper.conf
goto error3

::Cleanup and restart if needed.
:end
echo -----
echo - Cleaning up...
if exist freenet-%RELEASE%-latest.jar.new.url del freenet-%RELEASE%-latest.jar.new.url
if exist freenet-%RELEASE%-latest.jar.bak del freenet-%RELEASE%-latest.jar.bak
if exist freenet-ext.jar.sha1.new del freenet-ext.jar.sha1.new
if exist freenet-ext.jar.bak del freenet-ext.jar.bak


:: Maybe fix bug #2556
echo - Changing file permissions
if %VISTA%==0 echo Y| cacls . /E /T /C /G freenet:f > NUL
if %VISTA%==1 echo y| icacls . /grant freenet:(OI)(CI)F /T /C > NUL

if %RESTART%==0 goto cleanup2
echo - Restarting Freenet...
::See if we are using the new binary start.exe
if not exist bin\start.exe goto oldstarter
call bin\start.exe /silent
if errorlevel 1 goto unknownerror
goto cleanup2

:oldstarter
call bin\start.cmd > NUL

:cleanup2
if %FILENAME%==update.new.cmd goto newend
if exist update.new.cmd del update.new.cmd
echo -----
goto veryend

::If this session was launched by an old updater, replace it now (and force exit, or we will leave a command prompt open)
:newend
copy /Y update.new.cmd update.cmd > NUL
echo -----
exit

 ::We don't have enough privileges!
:writefail
echo - File permissions error!  Please launch this script with administrator privileges.
pause
goto veryend

:unknownerror
echo - An unknown error has occurred.
echo - Please scroll up and look for clues and contact support@freenetproject.org
if exist freenet-%RELEASE%-latest.jar.new.url del freenet-%RELEASE%-latest.jar.new.url
if exist freenet-%RELEASE%-latest.jar.bak del freenet-%RELEASE%-latest.jar.bak
pause

:veryend
::FREENET WINDOWS UPDATE SCRIPT
