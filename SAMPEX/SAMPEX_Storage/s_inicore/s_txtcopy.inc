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


// Text file copy:

stock sampex_textfilecopy(oldname[],newname[]) {

	new File:ohnd,File:nhnd;

	if (!fexist(oldname)) return false;

	ohnd=fopen(oldname,io_read);

	if (!ohnd) return false;

	nhnd=fopen(newname,io_write);

	if 
	(!nhnd) {
		fclose(ohnd);
		return false;
	}
	new 
		tmpres[sampex_MAX_STRING];
	while 
	(fread(ohnd,tmpres)) {

		sampex_linestrip(tmpres);

		format(tmpres,sizeof(tmpres),"%s\r\n",tmpres);

		fwrite(nhnd,tmpres);
	}
	fclose(ohnd);

	fclose(nhnd);

	return true;
}