/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: game timers
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

#define sampex_max_timers 999
#define sampex_max_tstrlen 300

/*
#define sampex_timerstart(timerid:[%0],bool:%1); \
SetTimer("sampex@task_%0", sampex_taskdur_%0, %1);*/

public OnGameModeInit()
{
	new sampex_timerid;
	for(
		sampex_timerid = 0;
		sampex_timerid < sampex_max_timers;
		sampex_timerid++
	){
	    	new sampex_taskname[sampex_max_tstrlen];
	    
	    	format(sampex_taskname,sampex_max_tstrlen,"sampex@task_%i",sampex_timerid);

		if (funcidx(sampex_taskname) != -1)
	    	{
			CallLocalFunction(sampex_taskname, "");
		}
	}	
	CallLocalFunction("sampex_timers_OnGameModeInit", "");
	return 1;
}

#if defined sampex_OnGameModeInit

    #undef OnGameModeInit

#else

    #define sampex_OnGameModeInit

#endif

#define OnGameModeInit \
	sampex_timers_OnGameModeInit

forward sampex_timers_OnGameModeInit();