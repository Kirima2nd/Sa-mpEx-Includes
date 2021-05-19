/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: Commands
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

#define sampex_commandreturn 1

// static bool:sampex_scmd_query = true;
static bool:sampex_scmd_s = false;

static bool:sampex_scmd_e = false;

forward scmd_gminit(); public scmd_gminit()
{
	sampex_scmd_s = funcidx("sampex_commandreceived") != -1;
	
	sampex_scmd_e = funcidx("sampex_commandperformed") != -1;
	
	// sampex_scmd_query = funcidx("datacheck") ! = 1;
	
	if (funcidx("scmd_gminit") != -1)
	{
		return sampex_callfunc("scmd_gminit", "");
	}
	return 1;
}
#define sampex_commands_updated 1

public sampex_commandreceived( playerid, cmdtext[])
{
	// format(f,sizeof(f),"DATA",...);
	// SendClientMessage(playerid,-1,"UNKNOWN COMMAND");
	if(!IsPlayerConnected( playerid )) return 0;
	return 1;
}

public sampex_commandperformed( playerid, cmdtext[], success) {

	if( !success ) return SendClientMessage( playerid, -1, \
	"[sampex] - SERVER: Unknown command.");
	return true;
}

public sampex_onplayercommandtext(playerid, cmdtext[])
{
    if(isnull(cmdtext))
    {
        return 0;
    }
    if (sampex_scmd_s && !sampex_callfunc("sampex_commandreceived", "is", \
		playerid, cmdtext))
    {
        return 1;
    }
    new pos,funcname[MAX_FUNC_NAME];
    //new sampex_string[sampex_query];
    while (cmdtext[++pos] > ' ')
	{
		funcname[pos-1] = tolower(cmdtext[pos]);
	}
	/*new command[300];

	format(command,sizeof(command),"sampexcmd_%s",cmdtext);

	sampex_callfunc(command, "is", playerid, cmdtext);

	return sampex_commandreturn;*/
	format(funcname, sizeof(funcname), "sampexcmd_%s", funcname);
	
    while (cmdtext[pos] == ' ') pos++;
    
	if (!cmdtext[pos])
	{
		if (sampex_scmd_e)
		{
			return sampex_callfunc("sampex_commandperformed", "isi", playerid, \
			cmdtext, sampex_callfunc(funcname, "is", playerid, "\1"));
		}
		return sampex_callfunc(funcname, "is", playerid, "\1");
	}
	/*new command[300];
	format(command,sizeof(command),"sampexcmd_%s",cmdtext);
	sampex_callfunc(command, "is", playerid, cmdtext);

	return sampex_commandreturn;*/
	if (sampex_scmd_e)
	{
		return sampex_callfunc("sampex_commandperformed", "isi", playerid, \
		cmdtext, sampex_callfunc(funcname, "is", playerid, cmdtext[pos]));
	}
	return sampex_callfunc(funcname, "is", playerid, cmdtext[pos]);
	
	/*new command[300];
	
	format(command,sizeof(command),"sampexcmd_%s",cmdtext);

	sampex_callfunc(command, "is", playerid, cmdtext);
	
	return sampex_commandreturn;*/
}
forward sampex_onplayercommandtext(playerid, cmdtext[]);
