/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: Playerdata
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

/*
#define sampex_setmysqlstats(s_mysql:[%0],[%1],[%2],[%3]); \
	new sampex_sql_host[][] = {%0},sampex_sql_user[][] = {%1},sampex_sql_pw[][] = {%2},sampex_sql_db[][] = {%3};
*/
new MySQL:gSQLHandle;

static g_MysqlRaceCheck[MAX_PLAYERS];

#define E_DIALOG_REGISTER 500
#define E_DIALOG_LOGIN 501
/*
enum 
{
	E_DIALOG_REGISTER = 16683,
	E_DIALOG_LOGIN
};*/

forward OnPlayerCheck(playerid);
public OnPlayerCheck(playerid)
{
	// Needed to increase it by one so it does not collide with each other.
	g_MysqlRaceCheck[playerid]++;

	// And then run the query
	new queryCheck[103];
	mysql_format(gSQLHandle, queryCheck, sizeof(queryCheck), "SELECT * FROM accounts WHERE name = '%e' LIMIT 1", sampex_pname(playerid));
	mysql_tquery(gSQLHandle, queryCheck, #OnMySQLResponse, "ii", playerid, g_MysqlRaceCheck[playerid]);
	return 1;
}
/*
#define sampex_sql_login(strings:[%0],[%1]); \
	new sampex_login_title[][] = {%0}, sampex_login_string[][] = {%1};

#define sampex_sql_register(strings:[%0],[%1]); \
	new sampex_register_title[][] = {%0}, sampex_register_string[][] = {%1};

#define sampex_sql_loginfail(strings:[%0]); \
	new sampex_loginfail[][] = {%0};

#define sampex_sql_registerfail(strings:[%0]); \
	new sampex_registerfail[][] = {%0};*/

forward OnMySQLResponse(playerid, race_check);
public OnMySQLResponse(playerid, race_check)
{
	if (race_check != g_MysqlRaceCheck[playerid]) return Kick(playerid);

	if (cache_num_rows() > 0)
	{
		sampex_array(var:[s],array:[sampex_login_title]);
		sampex_array(var:[s1],array:[sampex_login_string]);
		ShowPlayerDialog(playerid, E_DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, sampex_login_title[s], 
			sampex_login_string[s1],
			"Login", "Quit"
		);
	}
	else
	{
		sampex_array(var:[d],array:[sampex_register_title]);
		sampex_array(var:[d1],array:[sampex_register_string]);
		ShowPlayerDialog(playerid, E_DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, sampex_register_title[d],
			sampex_register_string[d1],
			"Register", "Quit"
		);	
	}
	return 1;
}

forward OnPlayerPasswordHashed(playerid);
public OnPlayerPasswordHashed(playerid)
{
	new 
		insertQuery[320],
		hash[BCRYPT_HASH_LENGTH];

	bcrypt_get_hash(hash, sizeof(hash));

	mysql_format(gSQLHandle, insertQuery, sizeof(insertQuery), "INSERT INTO accounts (name, password) VALUES ('%e', '%e')", sampex_pname(playerid), hash);
	mysql_query(gSQLHandle, insertQuery, false);

	sampex_array(var:[s],array:[sampex_login_title]);
	sampex_array(var:[s1],array:[sampex_login_string]);
	ShowPlayerDialog(playerid, E_DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, sampex_login_title[s], 
			sampex_login_string[s1],
			"Login", "Quit"
		);
	return 1;
}

forward OnPlayerPasswordChecked(playerid, bool:success);
public OnPlayerPasswordChecked(playerid, bool:success)
{
	new sampex_lf_string[300];
	format(sampex_lf_string,sizeof(sampex_lf_string),"%s\n\n%s",sampex_loginfail,sampex_login_string);
	sampex_array(var:[s],array:[sampex_login_title]);
	if (!success)
		return ShowPlayerDialog(playerid, E_DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, sampex_login_title[s], 
			sampex_lf_string,
			"Login", "Quit"
		);
	OnAccountLoad(playerid);
	return 1;
}

forward OnAccountLoad(playerid);
public OnAccountLoad(playerid)
{
	SetSpawnInfo(playerid, 0, 1, 1958.3783, 1343.1572, 15.3746, 270.1425, 0, 0, 0, 0, 0, 0);

	TogglePlayerSpectating(playerid, false);
	return 1;
}

#if defined sampex_dentist_entry_failed

#define sampex_createmysqlconnection(); \
	sampex_array(var:[sampex_host_data],array:[sampex_sql_host]); \
	sampex_array(var:[sampex_user_data],array:[sampex_sql_user]); \
	sampex_array(var:[sampex_pw_data],array:[sampex_sql_pw]); \
	sampex_array(var:[sampex_db_data],array:[sampex_sql_db]);

#define sampex_mysql(); \
	gSQLHandle = mysql_connect(sampex_sql_host[sampex_host_data], sampex_sql_user[sampex_user_data], sampex_sql_pw[sampex_pw_data], sampex_sql_db[sampex_db_data]);

#define sampex_mysqlfail \
	gSQLHandle == MYSQL_INVALID_HANDLE || mysql_errno(gSQLHandle) != 0

#define sampex_sql_failed(); \
	sampex_error("Connection to MySQL database failed!"), SendRconCommand("exit");

#define sampex_sql_success(); \
	sampex_info("Connection to MySQL database succedeed!"); \
	mysql_query(gSQLHandle, "CREATE TABLE IF NOT EXISTS accounts (id INT(16) NOT NULL AUTO_INCREMENT PRIMARY KEY, name VARCHAR(25) NOT NULL, password VARCHAR("#BCRYPT_HASH_LENGTH") NOT NULL)", false);

#define sampex_callmysql(%0); \
	sampex_info("MySQL database called successfully!"); \
	TogglePlayerSpectating(%0, true), SetTimerEx(#OnPlayerCheck, 800, false, "i", %0);

#define sampex_showregularregister(%0); \
	sampex_array(var:[sampex1],array:[sampex_register_title]); \
	sampex_array(var:[sampex12],array:[sampex_register_string]); \
	ShowPlayerDialog(%0, E_DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, sampex_register_title[sampex1], sampex_register_string[sampex12],"Login", "Quit");
	
#define sampex_showregularlogin(%0); \
	sampex_array(var:[sampex7],array:[sampex_login_title]); \
	sampex_array(var:[sampex17],array:[sampex_login_string]); \
	ShowPlayerDialog(%0, E_DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, sampex_login_title[sampex7], sampex_login_string[sampex17],"Login", "Quit");

#define sampex_showfailedregister(%0); \
	sampex_array(var:[sampex8],array:[sampex_register_title]); \
	sampex_array(var:[sampex18],array:[sampex_registerfail]); \
	ShowPlayerDialog(%0, E_DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, sampex_register_title[sampex8], sampex_registerfail[sampex18],"Login", "Quit");

#define sampex_showfailedlogin(%0); \
	sampex_array(var:[sampex9],array:[sampex_login_title]); \
	sampex_array(var:[sampex19],array:[sampex_loginfail]); \
	ShowPlayerDialog(%0, E_DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, sampex_login_title[sampex9], sampex_loginfail[sampex19],"Login", "Quit");

#define sampex_mysqlclose(); \
	mysql_close(gSQLHandle);
	
#define sampex_query_mysql(); \
    new queryCheck[256]; \
	mysql_format(gSQLHandle, queryCheck, sizeof(queryCheck), "SELECT password FROM accounts WHERE name = '%e' LIMIT 1", sampex_pname(playerid)); \
	mysql_query(gSQLHandle, queryCheck);
	
#define sampex_db_exists \
    cache_num_rows() > 0
    
#define sampex_cache(); \
    cache_unset_active();

#define sampex_cache_getpw(); \
    new hash[BCRYPT_HASH_LENGTH],\
	cache_get_value_name(0, "password", hash, sizeof(hash));
	
#endif
