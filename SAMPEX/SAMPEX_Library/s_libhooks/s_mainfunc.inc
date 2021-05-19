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
Sa-mpEx Library Hooks *PART OF IT*
==============================================================================*/

// version check

new versiondata = 1;

stock
	sampex_getversion()
{
	#if !defined sampex_version
	
	return sampex_unknown;
	    
 	#endif
	if( sampex_version == 0 )
	{
	    return sampex_null;
	}
	if( sampex_version != versiondata )
	{
		return sampex_diff;
	}
	return sampex_ok;
}
