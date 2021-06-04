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

// OnGameModeInit hook:

stock
	sampex_okay
(
)
{
	new verstring[10];
	format(verstring,10,"%i.0",sampex_version);
    	print(".");
    	print(".");
    	print(".");
	print("I~--------------------------------------------------------~I");
	print("I");
	
	printf("I	Sa-mpEx > version: %s",verstring);
	
	print("I");
	
	print("I	Successfully loaded the library! ");
	print("I 	By: DentisT 'Unity' & Brace ");
	
	print("I");
	print("I~--------------------------------------------------------~I");
	print(".");
	print(".");
	print(".");
	//return 1;
}
stock
	sampex_different
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
	
	print("I	Library is not installed successfully! ");
	print("I 	By: DentisT 'Unity' & Brace ");
	
	print("I");
	print("I~--------------------------------------------------------~I");
	print(".");
	print(".");
	print(".");
	//return 1;
}
stock
	sampex_nulled
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

	print("I	Version variable is equal to sampex_null - reinstall! ");
	print("I 	By: DentisT 'Unity' & Brace ");

	print("I");
	print("I~--------------------------------------------------------~I");
	print(".");
	print(".");
	print(".");
	//return 1;
}
stock
	sampex_unk
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

	print("I	System version is not defined! ");
	print("I 	By: DentisT 'Unity' & Brace ");

	print("I");
	print("I~--------------------------------------------------------~I");
	print(".");
	print(".");
	print(".");
	//return 1;
}
///////////////////////////////////////////////
stock
	sampex_checkver
()
{
	if( sampex_getversion() == sampex_ok )
	{
		sampex_okay();
	}
	if( sampex_getversion() == sampex_unknown )
	{
		sampex_unk();
	}
	if( sampex_getversion() == sampex_diff )
	{
		sampex_different();
	}
	if( sampex_getversion() == sampex_null )
	{
		sampex_nulled();
	}
	return -1;
}
#if defined sampex_als_hooking_defined
#define gm OnGameModeInit

#define sampex_OnGameModeInit(){ \
public gm() \ 
{ \
	sampex_checkver();

#endif

public OnGameModeInit()
{
	sampex_checkver();
	sampex_antideamx();
	if (funcidx("sampex_libhook_OnGameModeInit") != -1)
	{
		return CallLocalFunction("sampex_libhook_OnGameModeInit", "");
	}	
	return 1;
}

#if defined sampex_OnGameModeInit
    #undef OnGameModeInit
#else
    #define sampex_OnGameModeInit
#endif
#define OnGameModeInit sampex_libhook_OnGameModeInit
forward sampex_libhook_OnGameModeInit();
