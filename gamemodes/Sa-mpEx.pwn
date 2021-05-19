#include <a_samp>

#include <SAMPEX\s_scriptentry>

sampex_setmysqlstats(s_mysql:["localhost"],["root"],[""],["database"]);

sampex_sql_login(strings:["Login"],["Welcome, pls input your pw to login"]);

sampex_sql_loginfail(strings:["u put wrong pw"]);

sampex_sql_register(strings:["Register"],["Pls input ur pw to register"]);

#include <SAMPEX>

main() 
{
	print("TEST");
}

sampex_OnGameModeInit(){
    sampex_createmysqlconnection();
	sampex_mysql();
	if(sampex_mysqlfail)
	{
	    sampex_sql_failed();
		return 1;
	}
	sampex_sql_success();
	return 1;
}

public OnPlayerConnect(playerid)
{
	sampex_callmysql(playerid);
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch (dialogid)
	{
		sampex_bcrypt_register:
		{
			if(sampex_pw_toosmall) return sampex_showregister(playerid,strings:["register"],["Pls input ur pw again\n\nthe pw u typed is invalid"]);
			sampex_bcrypt_hash(params:[playerid],[inputtext]);
			return 1;
		}
		sampex_bcrypt_login:
		{
			if (sampex_loginpw_invalid) return sampex_showlogin(playerid,strings:["login"],["invalid pw\npls try again"]);

			sampex_query_mysql();

			if(sampex_db_exists)
			{
				sampex_cache_getpw();
				sampex_verify_hash(playerid,strings:[inputtext]);
			}
			sampex_cache();
			return 1;
		}
	}
	return 0;
}

public OnPlayerDisconnect(playerid, reason)
{
	return 1;
}

public OnGameModeExit()
{
	sampex_mysqlclose();
	return 1;
}
