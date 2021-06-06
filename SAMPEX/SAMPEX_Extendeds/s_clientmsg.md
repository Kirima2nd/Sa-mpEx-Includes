# s_clientmsg

## Description

Extended functions for client message-related functions!

## Usage and features

Before using *s_clientmsg* you do not need to do anything to *activate* it.

## Usage

Simply, just trigger the function.

## Features

- Below, you can see functions and features of this part of the library!

### sampex_sendclientmessage

***Info***

- This function will let you format the string in it. So, four lines of formatting and creating variables are now only one line with *s_clientmsg*.

***Parameters***

sampex_sendclientmessage(playerid,color,const message[],arguments);

- Strings: message, arguments<>
- Integners: playerid, arguments<>, color<>
- Other: color

***Examples***

Below, you can see simple example of function usage:

**Code**

```pawn
p: OnPlayerSpawn(playerid)
{
	sampex_sendclientmessage(playerid,-1,"Hello %s",sampex_pname(playerid));
	r: 1;
}
```

**Output**

- So, when player spawns, he will receive the following message:

```
Hello DEntisT
```

***Notes***

- Nothing to note here.

### sampex_sendclientmessagetoall

***Info***

- This function will let you format the string in it. So, four lines of formatting and creating variables are now only one line with *s_clientmsg*.

***Parameters***

sampex_sendclientmessagetoall(color,const message[],arguments);

- Strings: message, arguments<>
- Integners: arguments<>, color<>
- Other: color

***Examples***

Below, you can see simple example of function usage:

**Code**

```pawn
p: OnPlayerConnect(playerid)
{
	sampex_sendclientmessagetoall(-1,"Player %s successfully connected",sampex_pname(playerid));
	r: 1;
}
```

**Output**

- So, when player spawns, everyone online will receive the following message:
```
Player DEntisT successfully connected
```

***Notes***

- Nothing to note here.