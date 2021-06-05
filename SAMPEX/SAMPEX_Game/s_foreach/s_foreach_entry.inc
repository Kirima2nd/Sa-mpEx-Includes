/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: foreach loop
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

#define sampex_callfunc_iter \
	CallLocalFunction
#define s_player MAX_PLAYERS
#define s_vehicle MAX_VEHICLES
#define s_actor MAX_ACTORS
#define s_object MAX_OBJECTS
#define s_menu MAX_MENUS
#define s_pickup MAX_PICKUPS
#define s_textdraw MAX_TEXT_DRAWS
#define s_playertextdraw MAX_PLAYER_TEXT_DRAWS
#define s_gangzone MAX_GANG_ZONES
#define s_glabel MAX_3DTEXT_GLOBAL
#define s_plabel MAX_3DTEXT_PLAYER

// In stditer:<_> we put iterators defined above, or integner values.

#define sampex_foreach(stditer:<%0>) \
	for( new s_tagid = -1; s_tagid <= %0; s_tagid++ )

#define sampex_until(data:[%0])%8\10;%9 while(!(%0))%8

////////////////////////// Extra: //////////////////////////

#define sampex_max_iterators 999

#define sampex_iteradd(name:[%0],iterid:[%1],params:<%3>,return_val:<%2>); \
	forward sampex_iterator@%0_%1(%3); public sampex_iterator@%0_%1(%3){ return %2 ; }

#define sampex_iter(n:[%0],id:[%1],p:[%2]) \
	sampex_iterator@%0_%1(%2)

#if defined sampex@data_check@query

#define sampex_iterex(n:[%0],varid:[%1],p:<%2>); \
	new s_itername[300]; \
	format(s_itername,sizeof(s_itername),"sampex_iterator@%0_%i",%1); \
	return sampex_callfunc_iter(s_itername,%2);

#endif

stock sampex_iterex(const itername[], iterid, const indexes[], params )
{
	new s_itername[300];
	format(s_itername,sizeof(s_itername),"sampex_iterator@%s_%i",itername,iterid);
	if(funcidx(itername) != 1) return sampex_callfunc_iter(s_itername,indexes,params);
	return 0;
}

stock sampex_iterexzp(const itername[], iterid )
{
	new s_itername[300];
	format(s_itername,sizeof(s_itername),"sampex_iterator@%s_%i",itername,iterid);
	if(funcidx(itername) != 1) return sampex_callfunc_iter(s_itername,"");
	return 0;
}

#define sampex_each(iterid_c:<%1>) \
	for( new %1 = 0; %1 <= sampex_max_iterators; %1 ++ )
