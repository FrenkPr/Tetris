@echo off

set BAT_BASE_PATH=%~dp0
set PRJ_PATH=%BAT_BASE_PATH%

set BIN_PATH=%PRJ_PATH%\..\bin\Tetris
set LIBRARIES_PATH=%PRJ_PATH%\..\libraries
set ASSETS_PATH=%PRJ_PATH%\..\assets

REM icon .res file creation
windres "%ASSETS_PATH%\imgs\exeIcon.rc" -O coff -o "%ASSETS_PATH%\imgs\exeIcon.res"

RMDIR /s /q "%BIN_PATH%"
MD "%BIN_PATH%"
MD "%BIN_PATH%\assets"

REM building executable command
clang.exe -o "%BIN_PATH%\Tetris.exe" ^
    -Xlinker /subsystem:windows ^
    "%PRJ_PATH%\*.c" ^
	"%ASSETS_PATH%\imgs\exeIcon.res" ^
	-L"%LIBRARIES_PATH%" ^
    -l"%LIBRARIES_PATH%\raylibdll.lib"

REM if compilation succeded
IF %ERRORLEVEL% EQU 0 (
    XCOPY /y /s /e "%LIBRARIES_PATH%" "%BIN_PATH%"
    XCOPY /y /s /e "%ASSETS_PATH%" "%BIN_PATH%\assets"
)

pause