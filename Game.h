#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "GameObjectManager.h"

class Game{

public:
	static void Start();
	static sf::RenderWindow& GetWindow();
	
	const static int SCREEN_WIDTH = 2560;
	const static int SCREEN_HIGHT = 1440;
	const static int GROUND = 1100;
	const static int FRAME_RATE = 60;

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