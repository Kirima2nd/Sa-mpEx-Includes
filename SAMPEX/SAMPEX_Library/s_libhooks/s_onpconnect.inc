/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: Library hooks
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

stock sampex_reglogload()
{
	new verstring[10];
	format(verstring,10,"%i.0",sampex_version);
    	print(".");
    	print(".");
    	print(".");
	print("I~--------------------------------------------------------~I");
	print("I");
	
	printf("I	Sa-mpEx reg-log system > version: %s",verstring);
	
	print("I");
	
	print("I 	By: DentisT 'Unity' & Brace ");
	
	print("I");
	print("I~--------------------------------------------------------~I");
	print(".");
	print(".");
	print(".");
}

sampex_createuserhook("onpc",params:(),contains:[sampex_reglogload();]);