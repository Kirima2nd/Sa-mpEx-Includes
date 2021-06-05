# San Andreas Multiplayer Coding Extended ( aka: Sa-mpEx )

[Go back...](https://github.com/Sa-mpEx/Sa-mpEx-Includes)

## Introduction

### Meeting for first time

- Hello, this is Sa-mpEx.

### Further information

**Sa-mpEx** is open-source moduled library for SA:MP ( *San Andreas Multiplayer* ) servers/scripts. The library was written in PAWN scripting language, and originally created by DEntisT.

### What is the point?

**Sa-mpEx** brings you lot of functions and stuff to use in your gamemode script. All functions are moduled, but not separated. At first look, this library might look like something useless - but, at least someone will find it useful since it is making coding easy and interesting.

## Modules

### What are modules?

Modules are technically ordinary folders, but - they contain different files that are arranged by modules depending on their use.

Well, the *Storage* module contains functions related to storing data in files. For example, these functions are needed to create a registry and login system!

Remember that you as a user of this library do not need to include modules and libraries because they are all included together in the **SAMPEX.inc** file. Which means, in order to use the Sa-mpEx functions - all you need to do is include **SAMPEX.inc** and the configuration file:

```pawn
#include <SAMPEX.cfg>
#include <SAMPEX>
```

### List of modules

Below, you can see a list of all the modules included in the Sa-mpEx library.
- To learn more about a particular module, click on the blue text (internet link)!

Modules are:

- *Commands:* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Commands/s_commands_module.md)
- *Extendeds:* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Extendeds/s_extendeds_module.md)
- *Extra:* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Extra/s_extra_module.md)
- *Game:* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Game/s_game_module.md)
- *Hooks:* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Hooks/s_hooks_module.md)
- *Library:* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Library/s_library_module.md)
- *Playerdata (aka - Players):* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Playerdata/s_playerdata_module.md)
- *Storage:* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Storage/s_storage_module.md)
- *Streamer:* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Streamer/s_streamer_module.md)
- *Variables (aka - Vars):* To view more info about this module, click here: [show more](SAMPEX/SAMPEX_Variables/s_variables_module.md)

## Installation

### sampctl

NOTE: Only for *sampctl* users.
- If you're using *sampctl*, you can simply install Sa-mpEx to your project with:

```pawn
sampctl package install Sa-mpEx/Sa-mpEx-Includes
```

### Without - sampctl

- If you aren't using *sampctl*, you still can install Sa-mpEx - don't worry! In order to install Sa-mpEx without sampctl, download it from here and simply move following files to ***pawno\includes***:

```pawn
SAMPEX.cfg (file)
SAMPEX.inc (file)
SAMPEX (directory)
```

- Now, include it and start using the library:

```pawn
#include <SAMPEX.cfg>
#include <SAMPEX>
```