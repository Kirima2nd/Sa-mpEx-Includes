![logo](Sa-mpEx_logo.PNG)

INTRODUCTION
================

- Welcome to Sa-mpEx, San Andreas MultiPlayer Extended.

FUNCTION LIST
================

- Get list of Sa-mpEx functions here: 
[Functions](https://github.com/DentisT-SAMP/Sa-mpEx/blob/main/Sa-mpEx.md)

EXAMPLES
============

- See Sa-mpEx gamemode script example here:
[Examples](gamemdoes\Sa-mpEx.pwn)

HASHING SYSTEM
=================

- The library is using SAMP BCrypt hashing algorithm as default
hashing system in Sa-mpEx playerdata module.

GENERAL INFO
================
- Library name: Sa-mpEx

- Author: DentisT 'Unity '& Brace (my scripter name)

- Version of code: 1.0

- Copyrights: (c) 2021. - DentisT

- Ideas > open-mp staff team and contributors!

- Credits: me, FLY.INC, DracoBlue, streamer, Y_Less, bcrypt, Zeex

- Thanks to:
 ITB CompuPhase ( pawno, compiler, includes )
 SA-MP Team ( includes, actual GTA SA MOD, server )
 ZeeX ( compiler )
 Y_Less ( lot of ideas )
 Aezakmi, my cousin ( support and ideas )

 ... and everyone who helped!

WHAT'S THIS?
===============

- Info:
* This is Sa-mpEx, open-source library for pawn SA-MP scripting!
* This library is just extended library of SA-MP servers' actual
"starting" library which includes a_samp.inc, float.inc - etc.
* Sa-mpEx brings you a lot of new functions with different syntax.

- What does it contain?
* A lot of stuff... read version log for information!

INSTALLATION
================

- sampctl:

		sampctl package install DentisT-SAMP/Sa-mpEx

- Without sampctl:
* Place SAMPEX.inc and SAMPEX folder into /pawno/includes/ and
then include it in your code typing:

		#include < SAMPEX >

TESTING
===========

- To test this, simply run the package:

		sampctl package run

WARNING
===========

- Never try to use Sa-mpEx modules separately, because all files in 
the library are linked by different functions!

USAGE
=========

- To configure Sa-mpEx, there are various config files in SAMPEX folder.

VERSION LOG
===============

- Version: 1.4.0: beta
- Published: 17. may - 2021.

Changes:
* Fixed the bug where compiler displays WARNING 217 when using OnGameModeInit hook.
* TextDrawSetString extended function!
* PlayerTextDrawSetString extended function!
* fixed where sampex_cmd:testing was destroying compiler

Contains:
- SA-MP extended functions!
- Library hooks - use them to load or unload library!
- User hooks, create hook and attach hook to a public function!
- INI Core - needed to use scriptfiles!
- Math operation functions...
- New SA-MP functions!
- Fly mode!
- sampctl support
- streamer funcs
- Player data module
- Bcrypt funcs for Playerdata module (BETA feauture - contact for contribution )
- Command processor ( sampex_cmd )
- Extra functions, used by the library - not user
