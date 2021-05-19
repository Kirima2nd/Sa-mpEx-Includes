/*
 * Sa-mpEx
 * =======
 * Include file for Sa-mpEx library module.
 *
 * Module name: Extended funcs
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

/*=======================================
MODULE FOR Sa-mpEx
=======================================*/

stock
	sampex_globaltdcreate
(
	Float:x,
	Float:y,
	const sampex_message_string[],
	{Float,_}:...
)
{
	static
	    args,
	    start,
	    end,
	    sampex_unspecified_string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args
 
	if (
		args > 12
	)
	{
		#emit ADDR.pri sampex_message_string
		#emit STOR.pri start
 
	    for
		(
			end = start + (args - 12);
			end > start;
			end -= 4
		)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S sampex_message_string
		#emit PUSH.C 144
		#emit PUSH.C sampex_unspecified_string
		#emit PUSH.C args
		#emit SYSREQ.C format
 
		TextDrawCreate
		(
			x,
			y,
			sampex_unspecified_string
		)
		;
 
		#emit LCTRL 5
		#emit SCTRL 4
		#emit RETN
	}
	return
		TextDrawCreate
		(
			x,
			y,
			sampex_message_string
		)
	;
}
/////////////////////////////////////////
stock
	sampex_playertdcreate
(
	i,
	Float:x,
	Float:y,
	const sampex_message_string[],
	{Float,_}:...
)
{
	static
	    args,
	    start,
	    end,
	    sampex_unspecified_string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args
 
	if (
		args > 12
	)
	{
		#emit ADDR.pri sampex_message_string
		#emit STOR.pri start
 
	    for
		(
			end = start + (args - 12);
			end > start;
			end -= 4
		)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S sampex_message_string
		#emit PUSH.C 144
		#emit PUSH.C sampex_unspecified_string
		#emit PUSH.C args
		#emit SYSREQ.C format
 
		CreatePlayerTextDraw
		(
			i,
			x,
			y,
			sampex_unspecified_string
		)
		;
 
		#emit LCTRL 5
		#emit SCTRL 4
		#emit RETN
	}
	return
		TextDrawCreate
		(
			i,
			x,
			y,
			sampex_message_string
		)
	;
}
/////////////////////////////////////////
stock
	sampex_globaltdsetstring
(
	Text:id,
	const sampex_message_string[],
	{Float,_}:...
)
{
	static
	    args,
	    start,
	    end,
	    sampex_unspecified_string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (
		args > 12
	)
	{
		#emit ADDR.pri sampex_message_string
		#emit STOR.pri start

	    for
		(
			end = start + (args - 12);
			end > start;
			end -= 4
		)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S sampex_message_string
		#emit PUSH.C 144
		#emit PUSH.C sampex_unspecified_string
		#emit PUSH.C args
		#emit SYSREQ.C format

		TextDrawSetString
		(
			id,
			sampex_unspecified_string
		)
		;

		#emit LCTRL 5
		#emit SCTRL 4
		#emit RETN
	}
	return
		TextDrawSetString
		(
			id,
			sampex_message_string
		)
	;
}/////////////////////////////////////////
stock
	sampex_playertdsetstring
(
	i,
	Text:id,
	const sampex_message_string[],
	{Float,_}:...
)
{
	static
	    args,
	    start,
	    end,
	    sampex_unspecified_string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (
		args > 12
	)
	{
		#emit ADDR.pri sampex_message_string
		#emit STOR.pri start

	    for
		(
			end = start + (args - 12);
			end > start;
			end -= 4
		)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S sampex_message_string
		#emit PUSH.C 144
		#emit PUSH.C sampex_unspecified_string
		#emit PUSH.C args
		#emit SYSREQ.C format

		PlayerTextDrawSetString
		(
			i,id,
			sampex_unspecified_string
		)
		;

		#emit LCTRL 5
		#emit SCTRL 4
		#emit RETN
	}
	return
		PlayerTextDrawSetString
		(
			i,id,
			sampex_message_string
		)
	;
}
