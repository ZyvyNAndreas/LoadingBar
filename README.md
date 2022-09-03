## Installation

You must add include **LoadTD** to your server's Gamemode Example below

```pawn

#include <LoadTD>

forward FunctionLoadingTest(playerid);

public FunctionLoadingTest(playerid)

{

	SendClientMessage(playerid, -1, "Loading Succes");	return 1;

}

public OnPlayerCommandText(playerid, cmdtext[])

{

	if(!strcmp(cmdtext, "/loadingtest", true))

	{

		ShowLoading(playerid, 50, "Loading Trash", "FunctionLoadingTest");

		return 1;

	}

	return 0;

}

```
