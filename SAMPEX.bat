@echo off
title Sa-mpEx Configuration
color a
goto main
:exit
exit
:main
cls
echo.
echo ============================
echo I  Sa-mpEx Configuration   I
echo ============================
echo.
echo Welcome to Sa-mpEx configuration.
echo ================================
echo.
echo To start, simply - select what you want to modify.
echo To exit, input 'exit'.
echo.
echo Settings:
echo ---------
echo.
echo 1.) Modules
echo 2.) Other settings
echo.
set /p mainchoice="Input a number of choice:"
if %mainchoice% == 1 goto moduleconfig
if %mainchoice% == 2 goto otherconfig
if %mainchoice% == exit goto exit
goto error

:error
echo sampex - Error: Invalid configuration id.
pause
goto main

:otherconfig
cls
echo.
echo ============================
echo I  Sa-mpEx Configuration   I
echo ============================
echo.
echo Select the setting you want to modify!
echo ======================================
echo.
echo 1.) Hook information display
echo 2.) Standard samplib import
echo.
echo Type 'exit' to go back!
echo.
set /p otherconfigchoice="Insert a number of your choice:"
if %otherconfigchoice% == 1 goto hookinfo
if %otherconfigchoice% == 2 goto stdlib
if %otherconfigchoice% == exit goto main
goto otherconfigchoiceerror

:otherconfigchoiceerror
echo.
echo sampex - Error: Wrong otherconfig setting id.
pause
goto otherconfig

rem :HOOKINFO otherconfig:
:hookinfo
set /p other1="hookinfo: Insert value - just number, 0 or 1:"
if %other1% == 1 goto other11
if %other1% == 0 goto other10
goto other1error
:other1error
echo sampex - Error: Wrong hookinfo choice id.
echo sampex - Info: 1 error found
pause
goto hookinfo
:other11
echo #define sampex_hookinfo_display 1 > SAMPEX_Config\s_configdata\sampex_hookinfo_display.inc
echo sampex - Info: hookinfo: Operation completed successfully.
echo sampex - Info: hookinfo: Setting enabled! 0 errors and 0 warnings
pause
goto otherconfig
:other10
echo #define sampex_hookinfo_display 0 > SAMPEX_Config\s_configdata\sampex_hookinfo_display.inc
echo sampex - Info: hookinfo: Operation completed successfully.
echo sampex - Info: hookinfo: Setting disabled! 0 errors and 0 warnings
pause
goto otherconfig

rem :STDLIB otherconfig:
:stdlib
set /p other2="stdlib: Insert value - just number, 0 or 1:"
if %other2% == 1 goto other21
if %other2% == 0 goto other20
goto other2error
:other2error
echo sampex - Error: Wrong stdlib choice id.
echo sampex - Info: 1 error found
pause
goto stdlib
:other21
echo #define sampex_include_stdlib 1 > SAMPEX_Config\s_configdata\sampex_include_stdlib.inc
echo sampex - Info: stdlib: Operation completed successfully.
echo sampex - Info: stdlib: Setting enabled! 0 errors and 0 warnings
pause
goto otherconfig
:other20
echo #define sampex_include_stdlib 0 > SAMPEX_Config\s_configdata\sampex_include_stdlib.inc
echo sampex - Info: stdlib: Operation completed successfully.
echo sampex - Info: stdlib: Setting disabled! 0 errors and 0 warnings
pause
goto otherconfig

:moduleconfig
cls
echo.
echo ============================
echo I  Sa-mpEx Configuration   I
echo ============================
echo.
echo Select the module you want to enable/disable:
echo =============================================
echo.
echo 1.) Script entry (playerdata submodule)
echo 2.) Playerdata
echo 3.) Hooks
echo 4.) Extendeds
echo 5.) Storage
echo 6.) Game
echo 7.) Streamer
echo 8.) Commands
echo.
echo Type 'exit' to go back!
echo.
set /p moduleconfigchoice="Insert a number of your choice:"
if %moduleconfigchoice% == 1 goto scriptentry
if %moduleconfigchoice% == 2 goto playerdata
if %moduleconfigchoice% == 3 goto hooks
if %moduleconfigchoice% == 4 goto extendeds
if %moduleconfigchoice% == 5 goto storage
if %moduleconfigchoice% == 6 goto game
if %moduleconfigchoice% == 7 goto streamer
if %moduleconfigchoice% == 8 goto commands
if %moduleconfigchoice% == exit goto main
goto moduleconfigchoiceerror

:moduleconfigchoiceerror
echo sampex - Error: Wrong moduleconfig choice id.
echo sampex - Info: 1 error found
pause
goto moduleconfig

rem :SCRIPT ENTRY submodule:
:scriptentry
set /p module1="Script entry: Insert value - just number, 0 or 1:"
if %module1% == 1 goto module11
if %module1% == 0 goto module10
goto module1error
:module1error
echo sampex - Error: Wrong scriptentry choice id.
echo sampex - Info: 1 error found
pause
goto scriptentry
:module11
echo #define sampex_include_scriptentry 1 > SAMPEX_Config\s_configdata\s_scriptentry_config.inc
echo sampex - Info: Script entry: Operation completed successfully.
echo sampex - Info: Script entry: Module enabled! 0 errors and 0 warnings
pause
goto moduleconfig
:module10
echo #define sampex_include_scriptentry 0 > SAMPEX_Config\s_configdata\s_scriptentry_config.inc
echo sampex - Info: Script entry: Operation completed successfully.
echo sampex - Info: Script entry: Module disabled! 0 errors and 0 warnings
pause
goto moduleconfig

rem :PLAYERDATA module:
:playerdata
set /p module2="Playerdata: Insert value - just number, 0 or 1:"
if %module2% == 1 goto module21
if %module2% == 0 goto module20
goto module2error
:module2error
echo sampex - Error: Wrong Playerdata choice id.
echo sampex - Info: 1 error found
pause
goto playerdata
:module21
echo #define sampex_playerdata_included 1 > SAMPEX_Config\s_configdata\s_playerdata_config.inc
echo sampex - Info: Playerdata: Operation completed successfully.
echo sampex - Info: Playerdata: Module enabled! 0 errors and 0 warnings
pause
goto moduleconfig
:module20
echo #define sampex_playerdata_included 0 > SAMPEX_Config\s_configdata\s_playerdata_config.inc
echo sampex - Info: Playerdata: Operation completed successfully.
echo sampex - Info: Playerdata: Module disabled! 0 errors and 0 warnings
pause
goto moduleconfig

rem :HOOKS module:
:hooks
set /p module3="Hooks: Insert value - just number, 0 or 1:"
if %module3% == 1 goto module31
if %module3% == 0 goto module30
goto module3error
:module3error
echo sampex - Error: Wrong Hooks choice id.
echo sampex - Info: 1 error found
pause
goto hooks
:module31
echo #define sampex_hooks_included 1 > SAMPEX_Config\s_configdata\s_hooks_config.inc
echo sampex - Info: Hooks: Operation completed successfully.
echo sampex - Info: Hooks: Module enabled! 0 errors and 0 warnings
pause
goto moduleconfig
:module30
echo #define sampex_hooks_included 0 > SAMPEX_Config\s_configdata\s_hooks_config.inc
echo sampex - Info: Hooks: Operation completed successfully.
echo sampex - Info: Hooks: Module disabled! 0 errors and 0 warnings
pause
goto moduleconfig

rem :EXTENDEDS module:
:extendeds
set /p module4="Extendeds: Insert value - just number, 0 or 1:"
if %module4% == 1 goto module41
if %module4% == 0 goto module40
goto module4error
:module4error
echo sampex - Error: Wrong Extendeds choice id.
echo sampex - Info: 1 error found
pause
goto extendeds
:module41
echo #define sampex_extendeds_included 1 > SAMPEX_Config\s_configdata\s_extendeds_config.inc
echo sampex - Info: Extendeds: Operation completed successfully.
echo sampex - Info: Extendeds: Module enabled! 0 errors and 0 warnings
pause
goto moduleconfig
:module40
echo #define sampex_extendeds_included 0 > SAMPEX_Config\s_configdata\s_extendeds_config.inc
echo sampex - Info: Extendeds: Operation completed successfully.
echo sampex - Info: Extendeds: Module disabled! 0 errors and 0 warnings
pause
goto moduleconfig

rem :STORAGE module:
:storage
set /p module5="Storage: Insert value - just number, 0 or 1:"
if %module5% == 1 goto module51
if %module5% == 0 goto module50
goto module5error
:module5error
echo sampex - Error: Wrong Storage choice id.
echo sampex - Info: 1 error found
pause
goto storage
:module51
echo #define sampex_storage_included 1 > SAMPEX_Config\s_configdata\s_storage_config.inc
echo sampex - Info: Storage: Operation completed successfully.
echo sampex - Info: Storage: Module enabled! 0 errors and 0 warnings
pause
goto moduleconfig
:module50
echo #define sampex_storage_included 0 > SAMPEX_Config\s_configdata\s_storage_config.inc
echo sampex - Info: Storage: Operation completed successfully.
echo sampex - Info: Storage: Module disabled! 0 errors and 0 warnings
pause
goto moduleconfig

rem :GAME module:
:game
set /p module6="Game: Insert value - just number, 0 or 1:"
if %module6% == 1 goto module61
if %module6% == 0 goto module60
goto module6error
:module6error
echo sampex - Error: Wrong Game choice id.
echo sampex - Info: 1 error found
pause
goto game
:module61
echo #define sampex_game_included 1 > SAMPEX_Config\s_configdata\s_game_config.inc
echo sampex - Info: Game: Operation completed successfully.
echo sampex - Info: Game: Module enabled! 0 errors and 0 warnings
pause
goto moduleconfig
:module60
echo #define sampex_game_included 0 > SAMPEX_Config\s_configdata\s_game_config.inc
echo sampex - Info: Game: Operation completed successfully.
echo sampex - Info: Game: Module disabled! 0 errors and 0 warnings
pause
goto moduleconfig

rem :STREAMER module:
:streamer
set /p module7="Streamer: Insert value - just number, 0 or 1:"
if %module7% == 1 goto module71
if %module7% == 0 goto module70
goto module7error
:module7error
echo sampex - Error: Wrong Streamer choice id.
echo sampex - Info: 1 error found
pause
goto streamer
:module71
echo #define sampex_streamer_included 1 > SAMPEX_Config\s_configdata\s_streamer_config.inc
echo sampex - Info: Streamer: Operation completed successfully.
echo sampex - Info: Streamer: Module enabled! 0 errors and 0 warnings
pause
goto moduleconfig
:module70
echo #define sampex_streamer_included 0 > SAMPEX_Config\s_configdata\s_streamer_config.inc
echo sampex - Info: Streamer: Operation completed successfully.
echo sampex - Info: Streamer: Module disabled! 0 errors and 0 warnings
pause
goto moduleconfig

rem :COMMANDS module:
:commands
set /p module8="Commands: Insert value - just number, 0 or 1:"
if %module8% == 1 goto module81
if %module8% == 0 goto module80
goto module8error
:module8error
echo sampex - Error: Wrong Commands choice id.
echo sampex - Info: 1 error found
pause
goto commands
:module81
echo #define sampex_commands_included 1 > SAMPEX_Config\s_configdata\s_commands_config.inc
echo sampex - Info: Commands: Operation completed successfully.
echo sampex - Info: Commands: Module enabled! 0 errors and 0 warnings
pause
goto moduleconfig
:module80
echo #define sampex_commands_included 0 > SAMPEX_Config\s_configdata\s_commands_config.inc
echo sampex - Info: Commands: Operation completed successfully.
echo sampex - Info: Commands: Module disabled! 0 errors and 0 warnings
pause
goto moduleconfig