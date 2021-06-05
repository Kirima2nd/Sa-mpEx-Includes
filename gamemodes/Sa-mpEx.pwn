#include <SAMPEX.cfg>

#include <SAMPEX\s_scriptentry>

sampex_setmysqlstats(s_mysql:["localhost"],["root"],[""],["database"]);

sampex_sql_login(strings:["Login"],["Welcome, pls input your pw to login"]);

sampex_sql_loginfail(strings:["u put wrong pw"]);

sampex_sql_register(strings:["Register"],["Pls input ur pw to register"]);

#include <SAMPEX>

main() 
{
	sampex_print("TEST");
}

sampex_iteradd(name:[test],iterid:[1],params:<>,return_val:<6>);

sampex_iteradd(name:[test],iterid:[2],params:<>,return_val:<5>);

sampex_iteradd(name:[test],iterid:[3],params:<>,return_val:<4>);

p: OnGameModeInit()
{
    sampex_each(iterid_c:<i>)
    {
        sampex_printf("Iterator id %i successfully called and returned %i",i,sampex_iterexzp("test",i));
	}
    sampex_createmysqlconnection();
	sampex_mysql();
	if(sampex_mysqlfail)
	{
	    sampex_sql_failed();
		r: 1;
	}
	sampex_sql_success();
	r: 1;
}

p: OnPlayerConnect(playerid)
{
    sampex_foreach(stditer:<s_player>)
    {
        sampex_sendclientmessage(playerid,-1,"%s connected to server",sampex_pname(playerid));
	}
	sampex_callmysql(playerid);
	r: 1;
}

p: OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch (dialogid)
	{
		sampex_bcrypt_register:
		{
			if(sampex_pw_toosmall) r: sampex_showregister(playerid,strings:["register"],["Pls input ur pw again\n\nthe pw u typed is invalid"]);
			sampex_bcrypt_hash(params:[playerid],[inputtext]);
			r: 1;
		}
		sampex_bcrypt_login:
		{
			if (sampex_loginpw_invalid) r: sampex_showlogin(playerid,strings:["login"],["invalid pw\npls try again"]);

			sampex_query_mysql();

			if(sampex_db_exists)
			{
				sampex_cache_getpw();
				sampex_verify_hash(playerid,strings:[inputtext]);
			}
			sampex_cache();
			r: 1;
		}
	}
	r: 0;
}

p: OnPlayerDisconnect(playerid, reason)
{
	r: 1;
}

p: OnGameModeExit()
{
	sampex_mysqlclose();
	r: 1;
}

sampex_cmd(cmdname:testing,params:[playerid])
{
	sampex_sendclientmessage(playerid,-1,"One little test with: %s",sampex_pname(playerid));
	r: 1;
}

sampex_cmd(cmdname:testing2,params:[playerid])
{
	sampex_sendclientmessage(playerid,-1,"One little test with this interesting guy: %s",sampex_pname(playerid));
	r: 1;
}

sampex_hook(pub:[OnGameModeInit],params:[],hookid:[1])
{
	sampex_print("actually worked for the first time");
	r: 1;
}

sampex_hook(pub:[OnGameModeInit],params:[],hookid:[2])
{
	sampex_print("actually worked for the even second time wow");
	r: 1;
}

sampex_hook(pub:[OnGameModeExit],params:[],hookid:[1])
{
	sampex_print("actually worked for the first time even on gamemodeexit");
	r: 1;
}

sampex_task(timerid:[1])
{
    sampex_taskset(dur:<1000>,timerid:[1]);
	print("Timer 1 successfully called :)");
	r: 1;
}
