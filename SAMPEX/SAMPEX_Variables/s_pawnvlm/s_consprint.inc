/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: Pawn Val Manager
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
sampex_error - prints sampex error message
==============================================================================*/
stock
	sampex_error ( const str[])
{
	new str1 [ 300 ];
	format ( str1, sizeof ( str1 ), "[sampex] - Error: %s", str );
	return print ( str1 );
}
/*==============================================================================
sampex_info - prints sampex info message
==============================================================================*/
stock
	sampex_info ( const str [] )
{
	new str1 [ 300 ];
	format ( str1, sizeof ( str1 ), "[sampex] - Info: %s", str );
	return print ( str1 );
}
