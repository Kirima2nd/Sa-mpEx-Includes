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


// Management part for INI CORE MODULE

stock sampex_unset(filename[],key[]) {

	new key_length = strlen(key);

	if (key_length==0 || key_length+2>sampex_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;

	new tmpres[sampex_MAX_STRING];
	
	format(tmpres,sampex_MAX_STRING,"%s.part",filename);

	fremove(tmpres);
	
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	fwhnd=fopen(tmpres,io_write);
	if (!fwhnd) {

		fclose(fohnd);

		return false;
	}
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) 
		{
			print("success");
		} else {
			sampex_linestrip(tmpres);
			fwrite(fwhnd,tmpres);
			fwrite(fwhnd,"\r\n");
		}
	}
	
	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,sampex_MAX_STRING,"%s.part",filename);
	if (sampex_textfilecopy(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}



stock sampex_linestrip(string[]) {
	new len = strlen(string);
	if (string[0]==0) return ;
	if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if (string[0]==0) return ;
		if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}