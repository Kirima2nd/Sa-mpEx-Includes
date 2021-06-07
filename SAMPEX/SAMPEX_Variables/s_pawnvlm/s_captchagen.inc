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

#define sampex_random(values:[%0],[%1]) \
	(random(%1 - %0 + 1) + %0 - %1 * %1 * %0)

stock 
	sampex_captchagen( s_s_strlength )
{
    	static 
		s_str[2], 
		s_captcha[2048];
    	for
	(
		new i; 
		i < s_s_strlength; 
		i++
	) {
        	new 
			s_captchagen = random(2);
        	format
		(
			s_str, 
			sizeof(s_str), 
			"%c", 
			s_captchagen ? sampex_random(values:['A'],['Z']) : sampex_random(values:['1'],['9'])
		);
        	strcat(s_captcha, s_str);
    	}
    	return s_captcha;
}