@echo off
cls
title CAPRICORN FLASH UTILITY
:s0
color 1f
echo                         ==============================
echo                             CAPRICORN FLASH UTILITY
echo                         ==============================
echo.
echo                           0.Exit		1.BootHeader
echo.
echo                           2.App		3.Graphics
echo.
echo                           4.Erase All	 5. Mode
echo.
set /p cmd=Please input selection...:

if "%cmd%"=="0" goto exit
if "%cmd%"=="1" goto sBH
if "%cmd%"=="2" goto sApp 
if "%cmd%"=="3" goto sGC
if "%cmd%"=="4" goto sErase
if "%cmd%"=="5" goto sMode
echo Error! Please check the input.
:sa
goto s0

:sBH
set cfg=bl.cfg
##copy bootheader.s rom.bin
goto sjlink

:sApp 
set cfg=rom2ram.cfg
goto sjlink

:sGC
set cfg=graphics.cfg
goto sjlink

:sErase
set cfg=erase.cfg
goto sjlink

:sMode
set cfg=mode.cfg
goto sjlink

:sjlink
flashutility.exe %cfg% com3
goto s0

@echo off

:exit
exit
