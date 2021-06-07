// We include Sa-mpEx configuration file:
#include <SAMPEX.cfg>

// Setup mysql and other statistics:
sampex_setmysqlstats(s_mysql:["localhost"],["root"],[""],["database"]);

sampex_sql_login(strings:["Login"],["Welcome, pls input your pw to login"]);

sampex_sql_loginfail(strings:["u put wrong pw"]);

sampex_sql_register(strings:["Register"],["Pls input ur pw to register"]);

// We include Sa-mpEx entry file:
#include <SAMPEX>

main()
{
	sampex_print("TEST");
}

p: OnGameModeInit()
{
	// We create mysql connection using stats we set up:
    sampex_createmysqlconnection();
    // MySQL called:
	sampex_mysql();
	// If connection fails:
	if(sampex_mysqlfail)
	{
	    // ... it will print that mysql connection failed and shutdown the gamemode.
	    sampex_sql_failed();
		r: 0;
	}
	// Else if gamemode successfully connected the MYSQL
	// database it will print that connection suceeded.
	sampex_sql_success();
	r: 1;
}

p: OnPlayerConnect(playerid)
{
	// When player connects to server...
    sampex_foreach(stditer:<s_player>)
    {
        // It will send all players that we connected.
        sampex_sendclientmessage(s_tagid,-1,"%s connected to server",sampex_pname(playerid));
	}
	// Sa-mpEx calls MySQL to load player data from database!
	sampex_callmysql(playerid);
	r: 1;
}

p: OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	// We switch dialog id.
	switch (dialogid)
	{
		// When player responds to registration dialog...
		sampex_bcrypt_register:
		{
		    // if inputtext/password is too small ( strlen lower than 5 )
		    // we call Sa-mpEx again to show player register dialog.
			if(sampex_pw_toosmall) r: sampex_showregister(playerid,strings:["register"],["Pls input ur pw again\n\nthe pw u typed is invalid"]);
			// If password is larger than 5 characters,
			// Sa-mpEx calls BCrypt plugin to hash the password, security - you know! ;)
			sampex_bcrypt_hash(params:[playerid],[inputtext]);
			r: 1;
		}
		// When player responds to registration dialog...
		sampex_bcrypt_login:
		{
		    // If player inputs wrong password, Sa-mpEx opens login dialog again.
			if (sampex_loginpw_invalid) r: sampex_showlogin(playerid,strings:["login"],["invalid pw\npls try again"]);
			// Else if password is okay, Sa-mpEx calls mysql query.
			sampex_query_mysql();
			// If database exist...
			if(sampex_db_exists)
			{
			    // Sa-mpEx gets hashed password from MySQL database.
				sampex_cache_getpw();
				// Sa-mpEx calls BCrypt to verify did player input
				// same password from MySQL database.
				sampex_verify_hash(playerid,strings:[inputtext]);
			}
			// Again, we call MySQL to cache the password.
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
	// When gamemode shuts down, Sa-mpEx closes connection with MySQL database.
	sampex_mysqlclose();
	r: 1;
}

// Minor tests:

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
