/*==============================================================================

							====================
							  Sa-mpEx Includes
							====================

DESCRIPTION:

	- Sa-mpEx library entry include.

LEGAL:

- Library name: Sa-mpEx

- Author: DEntisT 'Unity' & Brace (my scripter name)

- Version of code: 1.4

- Copyrights: (c) 2021. - DentisT

- Ideas > open-mp staff team and contributors!

- Credits: me, FLY.INC, DracoBlue, streamer, Y_Less, bcrypt, Zeex, Agus

- Thanks to:
* ITB CompuPhase ( compiler, includes )
* SA-MP Team ( includes, actual GTA SA MOD, server )
* ZeeX ( compiler )
* Y_Less ( lot of ideas )
* Aezakmi, my cousin ( support and ideas )
* spookie ( pawno )
* open.mp ( support )

* ... and everyone who helped!

==============================================================================*/

// test:

#if defined sampex_configuration@test34

// SAMPEX CONFIGURATION

#define sampex_config_included

// MODULES:

// If you want to use functions from specific module, set to 1 - or if not to 0:

#define sampex_playerdata_included            0
#define sampex_hooks_included                 0
#define sampex_extendeds_included             0
#define sampex_storage_included               0
#define sampex_game_included                  0
#define sampex_streamer_included              0
#define sampex_commands_included              0


// OTHER:

// If you want to get info about hooks, set it to 1:
#define sampex_hookinfo_display 0

#endif

/*==========================--------[ Code ]--------==========================*/

#if !defined sampex_config_included
	#error sampex - [Error]: Configuration file not found.
#endif

#if sampex_hooks_included == 0
#pragma warning disable 217
#endif

#if sampex_streamer_included == 1 && sampex_game_included == 0
#pragma unused big_map_objects
#pragma unused middlesized_map_objects
#endif

// Testing/coding mode:

#define sampex_testing 1

// Symbol-already-defined error fix:

#if defined _sampex_included
	#endinput
#endif

#pragma library Sa-mpEx

//#pragma warning disable 217
#define _sampex_included 1

// playerdata macros:

#if sampex_include_scriptentry == 1
#include "SAMPEX\SAMPEX_Extra\s_scriptentry.inc"
#endif

/*==========================------[ Defines ]------==========================*/

// Version:

#define sampex_print print
#define sampex_printf printf
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

// Library hooks:

#include "SAMPEX\SAMPEX_Library\s_libhooks.inc"

// Hooks:

#if sampex_hooks_included == 0
	#warning sampex - [Info]: SAMPEX_Hooks not included.
#endif
#if sampex_hooks_included == 1

#include "SAMPEX\SAMPEX_Hooks\s_userhooks.inc"

#endif

// Extended functions:

#if sampex_extendeds_included == 0
	#warning sampex - [Info]: SAMPEX_Extendeds not included.
#endif
#if sampex_extendeds_included == 1

#include "SAMPEX\SAMPEX_Extendeds\s_clientmsg.inc"
#include "SAMPEX\SAMPEX_Extendeds\s_textdraws.inc"
#include "SAMPEX\SAMPEX_Extendeds\s_gametexts.inc"

#endif

// INI Core:

#if sampex_storage_included == 0
	#warning sampex - [Info]: SAMPEX_Storage not included.
#endif
#if sampex_storage_included == 1

#include "SAMPEX\SAMPEX_Storage\s_inicore.inc"

#endif

// Operations:

#include "SAMPEX\SAMPEX_Variables\s_pawnvlm.inc"

// SA-MP functions:

#if sampex_game_included == 0
	#warning sampex - [Info]: SAMPEX_Game not included.
#endif
#if sampex_game_included == 1

#include "SAMPEX\SAMPEX_Game\s_game.inc"
#include "SAMPEX\SAMPEX_Game\s_foreach.inc"
#include "SAMPEX\SAMPEX_Game\s_timers.inc"

#endif

// Streamer functions:

#if sampex_streamer_included == 0
	#warning sampex - [Info]: SAMPEX_Streamer not included.
#endif
#if sampex_streamer_included == 1

#include "SAMPEX\SAMPEX_Streamer\s_objects"

#endif

// Player data module:

#include "SAMPEX\SAMPEX_Playerdata\s_pdatamodule"

// Extra module:

#include "SAMPEX\SAMPEX_Extra\s_amx"

// Commands module:

#if sampex_commands_included == 0
	#warning sampex - [Info]: SAMPEX_Commands not included.
#endif
#if sampex_commands_included == 1

#include "SAMPEX\SAMPEX_Commands\s_commands_entry"

#endif