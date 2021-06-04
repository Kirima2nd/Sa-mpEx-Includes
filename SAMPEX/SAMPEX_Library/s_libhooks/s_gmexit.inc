/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: Library hoosks
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
Sa-mpEx Library Hooks
==============================================================================*/

// OnGameModeExit hook:

stock
	sampex_un
(
)
{
    	print(".");
    	print(".");
    	print(".");
	print("I~--------------------------------------------------------~I");
	print("I");
	print("I	Sa-mpEx");
	print("I");

	print("I	Successfully unloaded the library! ");
	print("I 	By: DentisT 'Unity' Brace ");

	print("I");
	print("I~--------------------------------------------------------~I");
	print(".");
	print(".");
	print(".");
}
#if defined sampex_als_hooking_defined
#define ge OnGameModeExit

#define sampex_OnGameModeExit(){ \
public ge() {\
	sampex_un();

#endif

public OnGameModeExit()
{
	sampex_checkver();
	sampex_antideamx();
	if (funcidx("sampex_libhook_OnGameModeExit") != -1)
	{
		return CallLocalFunction("sampex_libhook_OnGameModeExit", "");
	}	
	return 1;
}

#if defined sampex_OnGameModeExit
    #undef OnGameModeExit
#else
    #define sampex_OnGameModeExit
#endif
#define OnGameModeExit sampex_libhook_OnGameModeExit
forward sampex_libhook_OnGameModeExit();