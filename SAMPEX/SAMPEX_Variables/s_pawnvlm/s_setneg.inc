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
sampex_negative - returns the negative value of specified float
==============================================================================*/

stock
	Float:sampex_setnegative ( Float: num )
{
	if ( Float: num < 0 || Float: num == 0 )
	{
		sampex_error ( "Invalid float (num) specified." );
		new Float: invint = sampex_invalid_value;
		return Float: invint;
	}
	new Float: mt = 2 * num;
	new Float: neg 	= num - mt;
 	new info_string [ 128 ];
	format ( info_string, sizeof ( info_string ), \
	"Successfully converted positive float - (%f) to negive float - (%f).", Float:num, Float:neg );
	sampex_info( info_string );
 	return neg;
}
