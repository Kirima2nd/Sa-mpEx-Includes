/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: user hooks
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

/*==============================================================================
User hooks module
==============================================================================*/

#include "s_hookfix"

#define sampexhooks_return 1

#define sampex_manualuserhook("%1",params:(%2),contains:[%3]); \
forward %1(%2); public %1(%2)\
{\
	%3 \
	return sampexhooks_return; \
}
