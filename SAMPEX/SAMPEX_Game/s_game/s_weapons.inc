/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: weapon funcs
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

#include "s_sampdefines"

/*=============================================
Sa-mpEx Module include file
=============================================*/

stock sampex_getweaponslot( weaponid ) {
	new slot = -1;
	switch( weaponid ) {
    		case 0,1: slot = 0;
        	case 2 .. 9: slot = 1;
        	case 10 .. 15: slot = 10;
        	case 16 .. 18, 39: slot = 8;
        	case 22 .. 24: slot =2;
        	case 25 .. 27: slot = 3;
        	case 28, 29, 32: slot = 4;
        	case 30, 31: slot = 5;
        	case 33, 34: slot = 6;
        	case 35 .. 38: slot = 7;
        	case 40: slot = 12;
	    	case 41 .. 43: slot = 9;
		case 44 .. 46: slot = 11;
	}
	return slot;
}