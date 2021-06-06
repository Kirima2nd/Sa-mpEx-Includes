# s_gametexts

## Description

Extended functions for game text-related functions!

## Usage and features

Before using *s_clientmsg* you do not need to do anything to *activate* it.

## Usage

Simply, just trigger the function.

## Features

- Below, you can see functions and features of this part of the library!

### sampex_gametextforplayer

***Info***

- This function will let you format the string in it. So, four lines of formatting and creating variables are now only one line with s_gametexts.

***Parameters***

sampex_gametextforplayer(playerid,const message[],duration,style,arguments);

- Strings: message, arguments<>
- Integners: playerid, duration, style, arguments<>

***Examples***

Below, you can see simple example of function usage:

**Code**

```pawn
p: OnPlayerSpawn(playerid)
{
	sampex_gametextforplayer(playerid,"Welcome %s",1000,1,sampex_pname(playerid));
	r: 1;
}
```
**Output**

- So, when player spawns - he will receive gametext saying:

```
Welcome DEntisT
```

***Notes***

- Nothing to note here.

### sampex_gametextforall

***Info***

- This function will let you format the string in it. So, four lines of formatting and creating variables are now only one line with s_gametexts.

***Parameters***

sampex_gametextforall(const message[],duration,style,arguments);

- Strings: message, arguments<>
- Integners: duration, style, arguments<>

***Examples***

Below, you can see simple example of function usage:

**Code**

```pawn
p: OnPlayerConnect(playerid)
{
	sampex_gametextforall(playerid,"%s joined the game",1000,1,sampex_pname(playerid));
	r: 1;
}
```

**Output**

- So, when player connects - everyone online will receive gametext saying:

```
DEntisT joined the game
```

***Notes***

- Nothing to note here.