/*
native ShowLoading(playerid, Times, Info[], Function[], Color = 0x00FFFFFF, FringeColor = 0xFFFFFFFF);
*/

#include <a_samp>

static PlayerText:PlayerLoadingTD[MAX_PLAYERS][7];
static LoadingPlayerBar[MAX_PLAYERS];
static TimerLoading[MAX_PLAYERS];
static FuncTimer[MAX_PLAYERS][128];

stock ShowLoading(playerid, Times, Info[], Function[], Color = 0x00FFFFFF, FringeColor = 0xFFFFFFFF)
{
	LoadingPlayerBar[playerid] = 0;
	new Float:Value = LoadingPlayerBar[playerid]*68/100;
	new Timer = Times*1000/100;
	format(FuncTimer[playerid], 128, "%s", Function);
	PlayerTextDrawTextSize(playerid, PlayerLoadingTD[playerid][4], Value, 16.0);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][4], Color);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][0], FringeColor);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][1], FringeColor);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][2], FringeColor);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][3], FringeColor);
	PlayerTextDrawSetString(playerid, PlayerLoadingTD[playerid][6], Info);
	PlayerTextDrawShow(playerid, PlayerLoadingTD[playerid][0]);
	PlayerTextDrawShow(playerid, PlayerLoadingTD[playerid][1]);
	PlayerTextDrawShow(playerid, PlayerLoadingTD[playerid][2]);
	PlayerTextDrawShow(playerid, PlayerLoadingTD[playerid][3]);
	PlayerTextDrawShow(playerid, PlayerLoadingTD[playerid][4]);
	PlayerTextDrawShow(playerid, PlayerLoadingTD[playerid][6]);
	TimerLoading[playerid] = SetTimerEx("UpdtLoading", Timer, true, "d", playerid);
	return 1;
}

stock UpdateLoading(playerid)
{
	new Value = LoadingPlayerBar[playerid]*68/100;
	PlayerTextDrawTextSize(playerid, PlayerLoadingTD[playerid][4], Value, 16.0);
	PlayerTextDrawShow(playerid, PlayerLoadingTD[playerid][4]);
	return 1;
}

forward UpdtLoading(playerid);
public UpdtLoading(playerid)
{
	new str[24];
	LoadingPlayerBar[playerid] += 1;
	format(str, sizeof(str), "%d%", LoadingPlayerBar[playerid]);
	PlayerTextDrawSetString(playerid, PlayerLoadingTD[playerid][5], str);
	PlayerTextDrawShow(playerid, PlayerLoadingTD[playerid][5]);
	UpdateLoading(playerid);
	if(LoadingPlayerBar[playerid] >= 100)
	{
		KillTimer(TimerLoading[playerid]);
		LoadingPlayerBar[playerid] = 0;
		PlayerTextDrawHide(playerid, PlayerLoadingTD[playerid][0]);
		PlayerTextDrawHide(playerid, PlayerLoadingTD[playerid][1]);
		PlayerTextDrawHide(playerid, PlayerLoadingTD[playerid][2]);
		PlayerTextDrawHide(playerid, PlayerLoadingTD[playerid][3]);
		PlayerTextDrawHide(playerid, PlayerLoadingTD[playerid][4]);
		PlayerTextDrawHide(playerid, PlayerLoadingTD[playerid][5]);
		PlayerTextDrawHide(playerid, PlayerLoadingTD[playerid][6]);
		SetTimerEx(FuncTimer[playerid], 300, false, "d", playerid);
	}
	return 1;
}

public OnPlayerConnect(playerid)
{
	PlayerLoadingTD[playerid][0] = CreatePlayerTextDraw(playerid, 282.500000, 225.000000, "id_dual:white");
	PlayerTextDrawFont(playerid, PlayerLoadingTD[playerid][0], 4);
	PlayerTextDrawLetterSize(playerid, PlayerLoadingTD[playerid][0], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerLoadingTD[playerid][0], 75.000000, 4.500000);
	PlayerTextDrawSetOutline(playerid, PlayerLoadingTD[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, PlayerLoadingTD[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, PlayerLoadingTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, PlayerLoadingTD[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, PlayerLoadingTD[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, PlayerLoadingTD[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, PlayerLoadingTD[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerLoadingTD[playerid][0], 0);

	PlayerLoadingTD[playerid][1] = CreatePlayerTextDraw(playerid, 282.500000, 245.000000, "id_dual:white");
	PlayerTextDrawFont(playerid, PlayerLoadingTD[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, PlayerLoadingTD[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerLoadingTD[playerid][1], 75.000000, 4.500000);
	PlayerTextDrawSetOutline(playerid, PlayerLoadingTD[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, PlayerLoadingTD[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, PlayerLoadingTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, PlayerLoadingTD[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, PlayerLoadingTD[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, PlayerLoadingTD[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, PlayerLoadingTD[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerLoadingTD[playerid][1], 0);

	PlayerLoadingTD[playerid][2] = CreatePlayerTextDraw(playerid, 282.500000, 225.000000, "id_dual:white");
	PlayerTextDrawFont(playerid, PlayerLoadingTD[playerid][2], 4);
	PlayerTextDrawLetterSize(playerid, PlayerLoadingTD[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerLoadingTD[playerid][2], 3.500000, 20.000000);
	PlayerTextDrawSetOutline(playerid, PlayerLoadingTD[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, PlayerLoadingTD[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, PlayerLoadingTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, PlayerLoadingTD[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, PlayerLoadingTD[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, PlayerLoadingTD[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, PlayerLoadingTD[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerLoadingTD[playerid][2], 0);

	PlayerLoadingTD[playerid][3] = CreatePlayerTextDraw(playerid, 354.000000, 225.000000, "id_dual:white");
	PlayerTextDrawFont(playerid, PlayerLoadingTD[playerid][3], 4);
	PlayerTextDrawLetterSize(playerid, PlayerLoadingTD[playerid][3], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerLoadingTD[playerid][3], 3.500000, 20.000000);
	PlayerTextDrawSetOutline(playerid, PlayerLoadingTD[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, PlayerLoadingTD[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, PlayerLoadingTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, PlayerLoadingTD[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, PlayerLoadingTD[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, PlayerLoadingTD[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, PlayerLoadingTD[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerLoadingTD[playerid][3], 0);

	PlayerLoadingTD[playerid][4] = CreatePlayerTextDraw(playerid, 286.000000, 229.500000, "id_dual:white");
	PlayerTextDrawFont(playerid, PlayerLoadingTD[playerid][4], 4);
	PlayerTextDrawLetterSize(playerid, PlayerLoadingTD[playerid][4], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PlayerLoadingTD[playerid][4], 68.000000, 16.000000);
	PlayerTextDrawSetOutline(playerid, PlayerLoadingTD[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, PlayerLoadingTD[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, PlayerLoadingTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][4], 16777215);
	PlayerTextDrawBackgroundColor(playerid, PlayerLoadingTD[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, PlayerLoadingTD[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, PlayerLoadingTD[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, PlayerLoadingTD[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerLoadingTD[playerid][4], 0);

	PlayerLoadingTD[playerid][5] = CreatePlayerTextDraw(playerid, 322.000000, 231.000000, "");
	PlayerTextDrawFont(playerid, PlayerLoadingTD[playerid][5], 1);
	PlayerTextDrawLetterSize(playerid, PlayerLoadingTD[playerid][5], 0.200000, 1.200000);
	PlayerTextDrawTextSize(playerid, PlayerLoadingTD[playerid][5], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, PlayerLoadingTD[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, PlayerLoadingTD[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, PlayerLoadingTD[playerid][5], 2);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][5], -1);
	PlayerTextDrawBackgroundColor(playerid, PlayerLoadingTD[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, PlayerLoadingTD[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, PlayerLoadingTD[playerid][5], 0);
	PlayerTextDrawSetProportional(playerid, PlayerLoadingTD[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerLoadingTD[playerid][5], 0);

	PlayerLoadingTD[playerid][6] = CreatePlayerTextDraw(playerid, 322.000000, 210.000000, "");
	PlayerTextDrawFont(playerid, PlayerLoadingTD[playerid][6], 1);
	PlayerTextDrawLetterSize(playerid, PlayerLoadingTD[playerid][6], 0.250000, 1.500000);
	PlayerTextDrawTextSize(playerid, PlayerLoadingTD[playerid][6], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, PlayerLoadingTD[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, PlayerLoadingTD[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, PlayerLoadingTD[playerid][6], 2);
	PlayerTextDrawColor(playerid, PlayerLoadingTD[playerid][6], -1);
	PlayerTextDrawBackgroundColor(playerid, PlayerLoadingTD[playerid][6], 255);
	PlayerTextDrawBoxColor(playerid, PlayerLoadingTD[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, PlayerLoadingTD[playerid][6], 0);
	PlayerTextDrawSetProportional(playerid, PlayerLoadingTD[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerLoadingTD[playerid][6], 0);

	return 1;
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect LoadingTD_OnPlayerConnect

forward LoadingTD_OnPlayerConnect(playerid);

public OnPlayerDisconnect(playerid, reason)
{
	PlayerTextDrawDestroy(playerid, PlayerLoadingTD[playerid][0]);
	PlayerTextDrawDestroy(playerid, PlayerLoadingTD[playerid][1]);
	PlayerTextDrawDestroy(playerid, PlayerLoadingTD[playerid][2]);
	PlayerTextDrawDestroy(playerid, PlayerLoadingTD[playerid][3]);
	PlayerTextDrawDestroy(playerid, PlayerLoadingTD[playerid][4]);
	PlayerTextDrawDestroy(playerid, PlayerLoadingTD[playerid][5]);
	PlayerTextDrawDestroy(playerid, PlayerLoadingTD[playerid][6]);
	return 1;
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect LoadingTD_OnPlayerDisconnect

forward LoadingTD_OnPlayerDisconnect(playerid, reason);