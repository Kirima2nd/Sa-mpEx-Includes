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

#if !defined BCRYPT_HASH_LENGTH
	#define BCRYPT_HASH_LENGTH 60
#endif 

#if !defined BCRYPT_COST
	#define BCRYPT_COST 12
#endif

#define sampex_bcrypt_register: \
	case E_DIALOG_REGISTER:

#define sampex_bcrypt_login: \
	case E_DIALOG_LOGIN:

#define sampex_bcrypt_hash(params:[%0],[%1]); \
	bcrypt_hash(%0,#OnPlayerPasswordHashed, %1, BCRYPT_COST, "i", %0);

#define sampex_pw_toosmall \
	strlen(inputtext) < 5

#define sampex_loginpw_invalid \
	!strlen(inputtext) || strlen(inputtext) > 127

//sampex_cache_getpw(); needs to be called before sampex_verify_hash(...);
#define sampex_verify_hash(%0,strings:[%1]); \
	sampex_info("Calling BCrypt to verify password!"),\
	bcrypt_verify(%0, #OnPlayerPasswordChecked, %1, hash);
