/*==============================================================================

Let's start introducing ourselves?

I am:

-----------------------[ San Andreas MultiPlayer Extended ]---------------------

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
[Examples](https://github.com/DentisT-SAMP/Sa-mpEx/blob/master/gamemodes/example.md)

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
* ITB CompuPhase ( pawno, compiler, includes )
* SA-MP Team ( includes, actual GTA SA MOD, server )
* ZeeX ( compiler )
* Y_Less ( lot of ideas )
* Aezakmi, my cousin ( support and ideas )

* ... and everyone who helped!

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
	#include <SAMPEX>

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

- Contains:
SA-MP extended functions!
Library hooks - use them to load or unload library!
User hooks, create hook and attach hook to a public function!
INI Core - needed to use scriptfiles!
Math operation functions...
New SA-MP functions!
Fly mode!
sampctl support
streamer funcs
Player data module
Bcrypt funcs for Playerdata module (BETA feauture - contact for contribution )
Command processor ( sampex_cmd )
Extra functions, used by the library - not user

==============================================================================*/

/*==========================--------[ Code ]--------==========================*/

// Testing/coding mode:

#define sampex_testing 1

// Symbol-already-defined error fix:

#if defined _sampex_included
	#endinput
#endif

#pragma library Sa-mpEx

//#pragma warning disable 217
#define _sampex_included 1

/*==========================------[ Defines ]------==========================*/

// Version:

new sampex_version = 1;

// Script:

#define sampex_max_stringsize 100

// Defines for version info variables!

#define sampex_ok 0
#define sampex_diff 1
#define sampex_unknown 2
#define sampex_null 3

// INI Core max string size:

#if defined MAX_STRING
#define sampex_MAX_STRING MAX_STRING
#else
#define sampex_MAX_STRING 255
#endif

// Needed for operations module:

#define sampex_invalid_value 0x999

// Player data module:

#define DIALOG_REGISTER 1
#define DIALOG_LOGIN 2

#define COL_WHITE "{FFFFFF}"
#define COL_RED "{FF0000}"
#define COL_BLUE "{0000FF}"
#define COL_GREEN "{00FF00}"

/*==========================------[ Includes ]------==========================*/

// Main includes:

#if sampex_testing == 1
#include <a_samp>
#endif

// Hooks:

#include "SAMPEX\SAMPEX_Userhooks\s_userhooks"

// Library hooks:

#include "SAMPEX\SAMPEX_Library\s_libhooks.inc"

// Extended functions:

#include "SAMPEX\SAMPEX_Extendeds\s_clientmsg.inc"
#include "SAMPEX\SAMPEX_Extendeds\s_textdraws.inc"
#include "SAMPEX\SAMPEX_Extendeds\s_gametexts.inc"

// INI Core:

#include "SAMPEX\SAMPEX_Storage\s_inicore.inc"

// Operations:

#include "SAMPEX\SAMPEX_Variables\s_pawnvlm.inc"

// SA-MP functions:

#include "SAMPEX\SAMPEX_Game\s_weapons"
#include "SAMPEX\SAMPEX_Game\s_igchat"
#include "SAMPEX\SAMPEX_Game\s_flymode"

#include "SAMPEX\SAMPEX_Game\s_pragmasamp"

#include "SAMPEX\SAMPEX_Game\s_playername"

// Streamer functions:

#include "SAMPEX\SAMPEX_Streamer\s_objects"

// Player data module:

#include "SAMPEX\SAMPEX_Playerdata\s_pdatamodule"

// Extra module:

#include "SAMPEX\SAMPEX_Extra\s_amx"

// Commands module:

#include "SAMPEX\SAMPEX_Commands\s_commands_entry"