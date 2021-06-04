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

#define sampex_autohooks_calls_included

#if defined sampex_autohooks_debug
#if defined sampex_hooked_OnGameModeInit
    #undef OnGameModeInit
#else
    #define sampex_hooked_OnGameModeInit
#endif
#define OnFilterScriptInit @sampex_hooked_OnGameModeInit
forward @sampex_hooked_OnGameModeInit();
#endif

#if defined sampex_hooked_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define sampex_hooked_OnPlayerSpawn
#endif
#define OnFilterScriptInit @sampex_hooked_OnPlayerSpawn
forward @sampex_hooked_OnPlayerSpawn();
