#pragma once
#include "stdafx.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "GameObjectManager.h"

class Game{

public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	
	const static int SCREEN_WIDTH = 1280;
	const static int SCREEN_HIGHT = 720;
	const static int GROUND = 720;
	const static int FRAME_RATE = 60;

	const static int directoryBuff = 200;
	static std::string currentDirectory;

	// key states
    static bool rightPressed;
	static bool leftPressed;
	static bool upPressed;
	static bool fPressed;
	static bool rPressed;

private:	
	static bool IsExiting();
	static void ShowSplashScreen();
	static void ShowMenu();
	static void GameLoop();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	
	static GameObjectManager _gameObjectManager;
};