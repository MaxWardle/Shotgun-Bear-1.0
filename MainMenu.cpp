#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window){

	//Load textures from files
	sf::Texture mainMenu;
	sf::Texture anyKey;
	mainMenu.loadFromFile("C:/Users/Max/Documents/Visual Studio 2013/Projects/ShotgunBear/Pictures/MainMenu.png");
	anyKey.loadFromFile("C:/Users/Max/Documents/Visual Studio 2013/Projects/ShotgunBear/Pictures/Play.png");

	//create sprites and set textures
	sf::Sprite menu;
	sf::Sprite play;
	menu.setTexture(mainMenu);
	play.setTexture(anyKey);

	// set position of play sprite
	int playPosX = 1500; int playPosY = 1000;
	play.setPosition(playPosX, playPosY);

	//display sprites
	window.draw(menu);
	window.draw(play);
	window.display();

	//states that "press any key to play" is showing
	_messageShowing = MainMenu::Showing;

	sf::Event menuEvent;

	//starting timer
	clock_t startTime = clock();

	while (true){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return Play;
			}
			if (menuEvent.type == sf::Event::Closed){
				return Exit;
			}
			// note: add buttons for play and stats window instead of pressing any button
		}

		//if time elaped is greater than 1.3 secconds toggle "press any key to play" visability
		if ((clock() - startTime) > 1300){
			if (_messageShowing == MainMenu::Showing){
				window.clear();
				window.draw(menu);
				window.display();
				_messageShowing = MainMenu::NotShowing;
				startTime = clock();
			}else{
				play.setPosition(playPosX, playPosY);
				window.draw(play);
				window.display();
				_messageShowing = MainMenu::Showing;
				startTime = clock();
			}
		}
	}
}

/*
MainMenu::MenuResult MainMenu::HandleClick(int x, int y){
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++){
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.top - menuItemRect.height > y && menuItemRect.top < y && menuItemRect.left < x && menuItemRect.left - menuItemRect.width > x){
			return (*it).action;
		}
	}
} */
