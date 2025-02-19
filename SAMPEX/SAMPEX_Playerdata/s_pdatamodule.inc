/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: Playerdata
 *
 * Module version: 1.0
 *
 * Thanks to everyone who helped.
 * I really appreciate all your words.
 *
 * Please, keep all the credits.
 * If you want to contribute this project,
 * feel free to do it.
 *
 * Any file can be used and feel free to use its'
 * source code.
 *
 * On Discord, feel free to contact me about the library.
 *
 * Big thanks to OPEN MULTIPLAYER community - staff team and
 * other users, contributors, admins etc.
 *
 *                  DentisT.
 *
 *
 */

#include "s_pd_imports"

#if !defined sampex_playerdata_included
	#error Sa-mpEx: Please define "sampex_playerdata_included", set it to 0 if you do not want to use it.
#endif

#if sampex_playerdata_included == 1
#include "s_bcryptsql\s_bcryptsql_entry"
#endif