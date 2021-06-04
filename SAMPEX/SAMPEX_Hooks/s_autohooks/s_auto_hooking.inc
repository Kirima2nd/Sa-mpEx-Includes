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

#define sampex_max_hooks 999
#define sampex_max_hook_strlen 300

//=======|~ HOOK ~|============:[ OnGameModeInit ]:==========//

public OnGameModeInit()
{
	sampex_info("OnGameModeInit - Hooks module loading...");
	for( 
		new sampex_hookid = 0; 
		sampex_hookid <= sampex_max_hooks; 
		sampex_hookid++ 
	) {
		new sampex_hookname[sampex_max_hook_strlen];
		format(sampex_hookname,sampex_max_hook_strlen,"sampex@OnGameModeInit_%i",sampex_hookid);
		CallLocalFunction(sampex_hookname,"");

		#if defined sampex_hookinfo_display && sampex_hookinfo_display == 1
		sampex_printf("[sampex] - Info: OnGameModeInit hook id %i loaded.",sampex_hookid);
		#endif
	}
	CallLocalFunction("sampex_ahook_OnGameModeInit", "");
	sampex_info("OnGameModeInit - Hooks module loaded successfully!");
	return 1;
}

#if defined sampex_OnGameModeInit

    #undef OnGameModeInit

#else

    #define sampex_OnGameModeInit

#endif

#define OnGameModeInit \
	sampex_ahook_OnGameModeInit

forward sampex_ahook_OnGameModeInit();

//=======|~ HOOK ~|============:[ OnGameModeExit ]:==========//

public OnGameModeExit()
{
	sampex_info("OnGameModeExit - Hooks module loading...");
	for( 
		new sampex_hookid = 0; 
		sampex_hookid <= sampex_max_hooks; 
		sampex_hookid++ 
	) {
		new sampex_hookname[sampex_max_hook_strlen];
		format(sampex_hookname,sampex_max_hook_strlen,"sampex@OnGameModeExit_%i",sampex_hookid);
		CallLocalFunction(sampex_hookname,"");

		#if defined sampex_hookinfo_display && sampex_hookinfo_display == 1
		sampex_printf("[sampex] - Info: OnGameModeExit hook id %i loaded.",sampex_hookid);
		#endif
	}
	CallLocalFunction("sampex_ahook_OnGameModeExit", "");
	sampex_info("OnGameModeExit - Hooks module loaded successfully!");
	return 1;
}

#if defined sampex_OnGameModeExit

    #undef OnGameModeExit

#else

    #define sampex_OnGameModeExit

#endif

#define OnGameModeExit \
	sampex_ahook_OnGameModeExit

forward sampex_ahook_OnGameModeExit();