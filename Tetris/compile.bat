@echo off

@REM if not exist Tetris.exe (
@REM     echo "File does not exists"
@REM ) else (
@REM     del Tetris.exe
@REM )

if exist Tetris.exe (
    del Tetris.exe
)

clang Tetris.c -l raylibdll -Xlinker /subsystem:console

if exist a.exe (
    ren a.exe Tetris.exe
)