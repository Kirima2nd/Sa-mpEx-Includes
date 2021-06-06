# s_textdraws

## Description

Creating and setting up textdraws has never been easier, simpler and more interesting than now!

## Usage and features

Before using s_textdraws you do not need to do anything in order to " activate " it.

## Usage

Simply, just trigger the function.

## Features

- Below, you can see functions and features of this part of the library!

### sampex_globaltdcreate

***Info***

- Set up a global textdraw easily without formatting the string which is displayed in-game!

***Parameters***

sampex_globaltdcreate(Float:x,Float:y,const message[],arguments);

- Floats: x, y
- Strings: message, arguments<>
- Integners: arguments<>

***Examples***

Below, you can see simple example of function usage:

**Code**

```pawn

new Text:mytd;
#define servername "Server"

p: OnGameModeInit()
{
	mytd = sampex_globaltdcreate(43.95,123.876,"Welcome to %s roleplay",servername);
	r: 1;
}

```

**Output**

- So, when callback *OnGameModeInit* - textdraw with following string will be created:

```
Welcome to Server roleplay
```

***Notes***

There is also an additional function which can re-set the string of global textdraw.

It is *sampex_globaltdsetstring*:

```pawn
sampex_globaltdsetstring(1.1,2.2,"Your name: %s",servername);

```

### sampex_playertdcreate

***Info***

- Set up a player textdraw easily without formatting the string which is displayed in-game!

***Parameters***

sampex_playertdcreate(playerid,Float:x,Float:y,const message[],arguments);

- Floats: x, y
- Strings: message, arguments<>
- Integners: playerid, arguments<>

***Examples***

Below, you can see simple example of function usage:

**Code**

```pawn

new PlayerText:name[s_player];

stock createplayernametd(playerid)
{	
	name[playerid] = sampex_playertdcreate(playerid,43.7,2.7652,"Your nick: %s",sampex_pname(playerid));
	r: 1;
}

```

**Output**

- So, when *createplayernametd* is triggered somewhere - player textdraw with following string will be created:

```
Your nick: DEntisT
```

***Notes***

There is also an additional function which can re-set the string of player textdraw.

It is *sampex_playertdsetstring*:

```pawn
sampex_playertdsetstring(playerid,1.1,2.2,"Your name: %s",sampex_pname(playerid));

```