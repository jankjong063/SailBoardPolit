@echo off
setlocal

:: Set the source path for the .elf file
set "SOURCE_PATH=C:\Users\88691\AppData\Local\Temp\arduino\sketches\8E7CF89F5B75759CBBA305648D0421AF\SailBoardPolit.ino.elf"

:: Set the destination folder (where the .ino file is located)
set "DEST_FOLDER=F:\PHD\Arduino_Projects\SailBoardPolit\SailBoardPolit"

:: Path to avr-objcopy tool
set "AVR_OBJCOPY=C:\Users\88691\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7\bin\avr-objcopy.exe"

:: Copy the .elf file to the destination folder
if exist "%SOURCE_PATH%" (
    copy "%SOURCE_PATH%" "%DEST_FOLDER%\SailBoardPolit.ino.elf"
    echo .elf file copied to %DEST_FOLDER%
    
    :: Convert .elf to .bin using the full path to avr-objcopy
    "%AVR_OBJCOPY%" -O binary "%DEST_FOLDER%\SailBoardPolit.ino.elf" "%DEST_FOLDER%\SailBoardPolit.ino.bin"
    echo .bin file generated at %DEST_FOLDER%
    
    :: Convert .elf to .hex
    "%AVR_OBJCOPY%" -O ihex "%DEST_FOLDER%\SailBoardPolit.ino.elf" "%DEST_FOLDER%\SailBoardPolit.ino.hex"
    echo .hex file generated at %DEST_FOLDER%
) else (
    echo File not found: %SOURCE_PATH%
)

endlocal
