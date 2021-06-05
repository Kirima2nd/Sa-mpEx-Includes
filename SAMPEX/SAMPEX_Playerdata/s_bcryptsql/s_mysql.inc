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

new MySQL:gSQLHandle;

static g_MysqlRaceCheck[MAX_PLAYERS];

#define E_DIALOG_REGISTER 500
#define E_DIALOG_LOGIN 501

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