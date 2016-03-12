#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"


bool Game::leftPressed;
bool Game::rightPressed;
bool Game::upPressed;
bool Game::fPressed;
bool Game::rPressed;

//for drawing background
sf::Texture backgroundTexture;
sf::Sprite background;

void Game::Start(void){

	// initialize key states
	rightPressed = false;
	leftPressed = false;
	upPressed = false;
	fPressed = false;
	rPressed = false;

	if (_gameState != Uninitialized)
		return;

	//screen dimentions: 2560 x 1440
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGHT, 32), "Shotgun Bear");
	
	// frame rate is 60 fps
	_mainWindow.setFramerateLimit(FRAME_RATE);

	//create ponter to instance of Player class, *player1, and set inital position of player1's sprite
	Player *player1 = new Player((float)SCREEN_WIDTH / 2, (float)GROUND);
	player1 -> Load("\../Pictures/BearWalkRight1.png");

	// add visual game objects to object manager
	_gameObjectManager.Add("ShotgunBear", player1);

	// show splash screen first
	_gameState = Game::ShowingSplash;

	//Load Game Background
	backgroundTexture.loadFromFile("\../Pictures/Background.png");
	background.setTexture(backgroundTexture);

	// while window is not being closed, stay in game loop
	while (!IsExiting()){
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting(){
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::ShowSplashScreen(){
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu(){
	MainMenu _mainMenu;
	MainMenu::MenuResult result = _mainMenu.Show(_mainWindow);
	switch (result){
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
		// note: add case to show statistics/ achievements
	}
}

sf::RenderWindow& Game::GetWindow(){
	return _mainWindow;
}

void Game::GameLoop(){

	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);

	switch (_gameState){

		case Game::ShowingMenu:{
			ShowMenu();
			break;
		}

		case Game::ShowingSplash:{
			ShowSplashScreen();
			break;
		}

		case Game::Playing:{

			// update all sprites
			_mainWindow.clear(sf::Color::Black);
			_mainWindow.draw(background);
			_gameObjectManager.UpdateAll();
			_gameObjectManager.DrawAll(_mainWindow);
			_mainWindow.display();

			// check if window is closed
			if (currentEvent.type == sf::Event::Closed){
				_gameState = Game::Exiting;
			}

			// check which keys are pressed
			if (currentEvent.type == sf::Event::KeyPressed){
				if (currentEvent.key.code == sf::Keyboard::Escape) ShowMenu(); //note: change to pause menu
				if (currentEvent.key.code == sf::Keyboard::Left){
					leftPressed = true;
				}
				if (currentEvent.key.code == sf::Keyboard::Right){
					rightPressed = true;
				}
				if (currentEvent.key.code == sf::Keyboard::Up){
					upPressed = true;
				}
				// note: add if 'f' is pressed set fire vaiable to 1 else 0
				// note: add if 'r' is pressed set reload variable to 1 else 0
			}

			// check if keys are released
			if (currentEvent.type == sf::Event::KeyReleased){
				if (currentEvent.key.code == sf::Keyboard::Left){
					leftPressed = false;
				}

				if (currentEvent.key.code == sf::Keyboard::Right){
					rightPressed = false;
				}

				if (currentEvent.key.code == sf::Keyboard::Up){
					upPressed = false;
				}
			}

			break;
		}
	}
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;