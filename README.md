## Installation And Example

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
