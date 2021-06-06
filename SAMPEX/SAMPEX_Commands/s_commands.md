# s_commands

## Description

**s_commands** makes server commands easy - declaring commands is faster than ever with *s_commands*!

## Usage and features

In order to use *s_commands*, you'll need to do few things before using the library!

## Usage

To make *s_commands* work, you'll need to implement the following code into your project.

```pawn

public OnPlayerCommandText(playerid, cmdtext[])
{
    sampex_onplayercommandtext(playerid, cmdtext);
	return 1;
}
```

**What this code does?**

- Very simple question, *sampex_onplayercommandtext(playerid, cmdtext);* function hooks callbacks which detect commands you declared in your script. If you don't use *sampex_onplayercommandtext* your command obviously won't work!

## Features

- Below, you can see functions and features of this part of the library!

### sampex_cmd

***Info***

*sampex_cmd* is a macro which lets you do declare commands!

***Parameters***

sampex_cmd(cmdname:cmdname,params:[cmd_params]) {}

- Strings: cmdname
- Integners: cmd_params {...}

***Examples***

Below, you can see simple example of function usage:

**Code**

```pawn
sampex_cmd(cmdname:help,params:[playerid])
{
	printf("Hurry! %s needs help...",sampex_pname(playerid));
	r: 1;
}
```

**Output**

- So, when player triggers */help* command on a server, it will print his name.

```
Hurry! DEntisT needs help...
```