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


// Check if file exists - etc.

stock sampex_dofileexist(filename[])
{
	return fexist(filename);
}
stock sampex_getint(filename[],key[]) 
{
	new tmpres[sampex_MAX_STRING];
	
	new key_length = strlen(key);

	if (key_length==0 || key_length+2>sampex_MAX_STRING) return tmpres;
	
	new File:fohnd;

	fohnd=fopen(filename,io_read);

	if (!fohnd) return tmpres;
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {

			sampex_linestrip(tmpres);

			strmid(tmpres, tmpres, key_length + 1, strlen(tmpres), sampex_MAX_STRING);

			fclose(fohnd);

			return tmpres;
		}
	}
	fclose(fohnd);

	return tmpres;
}

stock sampex_isintset(filename[],key[]) {
	new key_length = strlen(key);

	if (key_length==0 || key_length+2>sampex_MAX_STRING) return false;
	
	new File:fohnd;

	fohnd=fopen(filename,io_read);

	if (!fohnd) return false;
	
	new tmpres[sampex_MAX_STRING];
	while (fread(fohnd,tmpres)) {
		if (
				tmpres[key_length]=='='

			&&  !strcmp(tmpres, key, true, key_length)	
		) {
			fclose(fohnd);

			return true;
		}
	}
	fclose(fohnd);
	return false;
}