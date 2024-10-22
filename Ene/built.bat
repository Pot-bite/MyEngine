REM//build script for engine
@ECHO OFF
Setlocal EnableDelayedExpansion

REM//get a list of C.Files
SET cFilenames=
FOR /R %%f in (* .c) do (
    SEt cFilenames=!cFilenames! %%f
)

REM 
SET assembley=engine
SET compilerFlags=-g -shared -Wvarargs -Wall -Werror
REM
SET incluseFlags=-Isrc -I%VULKAN_SDK%/Include
SET linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
SET defines=-D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS

ECHO "Building %ssembley%%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembley%.dll %defines% %incluseFlags% %linkerFlags%