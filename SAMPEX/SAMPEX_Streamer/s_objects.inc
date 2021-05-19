/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: Objects
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

big_map_objects( id ) {
	switch( id ) {
		case 7584, 8395, 9901, 6863: return true;
	}
	return false;
}

middlesized_map_objects( id ) {
	switch( id ) {
		case 18981, 19377, 18766: return true;
	}
	return false;
}

stock sampex_createdynamicobject( objid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 300.0, Float:drawdistance = 300.0, areaid = -1, priority = 0 )
{
	if( big_map_objects( objid ) ) {
		streamdistance = 800.0;
		drawdistance = 800.0;
		priority = 8;
	}
	else if( middlesized_map_objects( objid ) ) {
		streamdistance = 500.0;
		drawdistance = 500.0;
		priority = 6;
	}
	return CreateDynamicObject( objid, x, y, z, rx, ry, rz, worldid, interiorid, playerid, streamdistance, drawdistance, areaid, priority );
}