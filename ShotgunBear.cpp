// ShotgunBear.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Game.h"
#include <Windows.h>
#include "Wincon.h"
#include "WinUser.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//hide console window
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	Game::Start();

	return 0;
}

