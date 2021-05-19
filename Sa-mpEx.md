LIST OF Sa-mpEx FUNCTIONS
=====
This readme file contains all the functions of `Sa-mpEx`.

**Libhooks**

Gamemode init functions:

- sampex_OnGameModeInit(){ ... }
- sampex_OnGameModeExit(){ ... }

**Extendeds**

Client message functions:

- sampex_sendclientmessage
- sampex_sendclientmessagetoall

Gametext functions:

- sampex_gametextforplayer
- sampex_gametextforall

Textdraw functions:

- sampex_globaltdcreate
- sampex_playertdcreate
- sampex_globaltdsetstring
- sampex_playertdsetstring

**Game**

In game chat functions:

- sampex_clearplayerchat

Player nickname functions:

- sampex_pname

Defines:

- sampex_sinfox
- sampex_sinfoy
- sampex_sinfoz

Weapon functions:

- sampex_getweaponslot

**INI Core**

Crfile functions:

- sampex_remove
- sampex_create

Iniboolean functions:

- sampex_boolean
- sampex_setboolean

Inicheck functions:

- sampex_dofileexist
- sampex_getint
- sampex_isintset

Inifilemng functions:

- sampex_unset
- sampex_linestrip

Inifloat functions:

- sampex_setfloat
- sampex_float

Intcore functions:

- sampex_set
- sampex_setint
- sampex_integner

Txtcopy functions:

- sampex_textfilecopy

**PawnVLM**

Operation functions:

- sampex_setnegative
- sampex_setpositive

**Streamer**

Object functions:

- sampex_createdynamicobject

**Userhooks**

Main functions (s_userhooks):

- sampex_createuserhook

Extra functions (s_hookfix):

- sampex_hookattach

**Extra**

AMX functions:

- sampex_antideamx
- sampex_isnull

**Commands**

Commands entry functions:

- sampex_cmd

Commands main functions:

- sampex_commandperformed
- sampex_commandreceived
