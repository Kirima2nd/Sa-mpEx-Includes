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


// INI Core for saving integners

stock sampex_set(filename[],key[],value[]) {

	new key_length = strlen(key);
	new value_length = strlen(value);
	if (key_length==0 || key_length+value_length+2>sampex_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;
	new tmpres[sampex_MAX_STRING];
	new bool:wasset=false;
	
	format(tmpres,sizeof(tmpres),"%s.part",filename);
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
			!wasset
			&& tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
				format(tmpres,sizeof(tmpres),"%s=%s",key,value);
				wasset=true;
		} else {
			sampex_linestrip(tmpres);
		}
		fwrite(fwhnd,tmpres);
		fwrite(fwhnd,"\r\n");
	}

	if (!wasset) {
		format(tmpres,sizeof(tmpres),"%s=%s",key,value);
		fwrite(fwhnd,tmpres);
		fwrite(fwhnd,"\r\n");
	}

	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,sizeof(tmpres),"%s.part",filename);
	if (sampex_textfilecopy(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}


stock sampex_setint(filename[],key[],value) {
   new valuestring[sampex_MAX_STRING];
   format(valuestring,sampex_MAX_STRING,"%d",value);
   return sampex_set(filename,key,valuestring);
}

stock sampex_integner(filename[],key[]) {
   return strval(sampex_getint(filename,key));
}