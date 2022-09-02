#include <a_samp>
#include <LoadTD>

forward LoadTest(playerid);
public LoadTest(playerid)	//Callbacks kalau Loadingnya udah 100% Makan script akan memanggil Callbacks yang kalian buat
{
	SendClientMessage(playerid, -1, "Loading Succes");
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if(!strcmp(cmdtext, "/loadingtest", true))
	{
		ShowLoading(playerid, 50, "Loading", "LoadTest");
		return 1;
	}
	return 0;
}
