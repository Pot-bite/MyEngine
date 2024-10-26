REM//build script for testbed
@ECHO OFF
Setlocal EnableDelayedExpansion

REM//get a list of C.Files
SET cFilenames=
FOR /R %%f in (* .c) do (
    SEt cFilenames=!cFilenames! %%f
)

REM 
SET assembley=testbed
SET compilerFlags=-g -shared -Wvarargs -Wall -Werror
REM
SET incluseFlags=-Isrc ../Ene/Source/
SET linkerFlags=-L..bin/ -lengine.lib
SET defines=-D_DEBUG -DKIMPORT

ECHO "Building %ssembley%%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembley%.dll %defines% %incluseFlags% %linkerFlags%