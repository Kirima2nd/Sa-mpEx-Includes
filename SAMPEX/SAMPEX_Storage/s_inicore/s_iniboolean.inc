/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: INI CORE
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

// INI Core for saving boolean values

stock sampex_boolean(filename[],key[]) {
   return strval(sampex_getint(filename,key));
}

stock sampex_setboolean(filename[],key[],value) {
	if (value) {
		return sampex_set(filename,key,"1");
	}
	return sampex_set(filename,key,"0");
}