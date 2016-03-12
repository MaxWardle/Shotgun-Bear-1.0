#include "stdAfx.h"
#include "SplashScreen.h"
#include "Game.h"


void SplashScreen::Show(sf::RenderWindow& window){

	//make window black while loading files
	window.clear(sf::Color::Black);
	window.display();

	//load textures from files
	sf::Texture intro1;
	sf::Texture intro2;
	sf::Texture intro3;
	sf::Texture intro4;
	sf::Texture intro5;
	sf::Texture intro6;
	sf::Texture intro7;
	sf::Texture intro8;
	sf::Texture intro9;
	sf::Texture intro10;
	sf::Texture intro11;
	sf::Texture black;
	intro1.loadFromFile("\../Pictures/intro1.png");
	intro2.loadFromFile("\../Pictures/intro2.png");
	intro3.loadFromFile("\../Pictures/intro3.png");
	intro4.loadFromFile("\../Pictures/intro4.png");
	intro5.loadFromFile("\../Pictures/intro5.png");
	intro6.loadFromFile("\../Pictures/intro6.png");
	intro7.loadFromFile("\../Pictures/intro7.png");
	intro8.loadFromFile("\../Pictures/intro8.png");
	intro9.loadFromFile("\../Pictures/intro9.png");
	intro10.loadFromFile("\../Pictures/intro10.png");
	intro11.loadFromFile("\../Pictures/intro11.png");
	black.loadFromFile("\../Pictures/Black.png");

	//creating sprites and settign textures
	sf::Sprite frame1;
	sf::Sprite frame2;
	sf::Sprite frame3;
	sf::Sprite frame4;
	sf::Sprite frame5;
	sf::Sprite frame6;
	sf::Sprite frame7;
	sf::Sprite frame8; 
	sf::Sprite frame9;
	sf::Sprite frame10;
	sf::Sprite frame11;
	sf::Sprite frame12;
	frame1.setTexture(intro1);
	frame2.setTexture(intro2);
	frame3.setTexture(intro3);
	frame4.setTexture(intro4);
	frame5.setTexture(intro5);
	frame6.setTexture(intro6);
	frame7.setTexture(intro7);
	frame8.setTexture(intro8);
	frame9.setTexture(intro9);
	frame10.setTexture(intro10);
	frame11.setTexture(intro11);
	frame12.setTexture(black);

	sf::Font font;
	if (!font.loadFromFile("\../Fonts/Disposeable Droid/DisposableDroidBB.otf")){
		return;
	}

	sf::Text text;
	sf::Text text1;
	sf::Text text2;
	text.setFont(font);
	text1.setFont(font);
	text2.setFont(font);

	text.setString("AND ON THAT DAY");
	text1.setString("A LEGEND WAS BORN");
	text2.setString("THE LEGEND OF");

	text.setCharacterSize(100);
	text1.setCharacterSize(100);
	text2.setCharacterSize(100);

	//center the text
	text.setPosition(Game::SCREEN_WIDTH / 2 - (text.getLocalBounds().width / 2), 130);
	text1.setPosition(Game::SCREEN_WIDTH / 2 - (text1.getLocalBounds().width / 2), 310);
	text2.setPosition(Game::SCREEN_WIDTH / 2 - (text2.getLocalBounds().width / 2), 490);

	//displaying frame 1
	window.draw(frame1);
	window.display();

	sf::Event menuEvent;

	//starting timer
	clock_t startTime = clock();

	//displaying rest of frames at set intervals (1000 clock cyces = 1 sec)

	while ((clock() - startTime) < 1000){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.draw(frame2);
	window.display();

	while ((clock() - startTime) < 1400){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.draw(frame3);
	window.display();

	while ((clock() - startTime) < 3400){
		if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
			return;
		}
	}
	window.draw(frame4);
	window.display();

	while ((clock() - startTime) < 3800){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.draw(frame5);
	window.display();

	while ((clock() - startTime) < 5800){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.draw(frame6);
	window.display();

	while ((clock() - startTime) < 5900){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.draw(frame7);
	window.display();

	while ((clock() - startTime) < 6000){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.draw(frame8);
	window.display();

	while ((clock() - startTime) < 6100){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.draw(frame9);
	window.display();

	while ((clock() - startTime) < 6200){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.draw(frame10);
	window.display();

	while ((clock() - startTime) < 6300){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.draw(frame11);
	window.display();

	while ((clock() - startTime) < 6400){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.clear(sf::Color::Black);
	window.display();

	while ((clock() - startTime) < 8000){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.clear(sf::Color::Black);
	window.draw(text);
	window.display();

	while ((clock() - startTime) < 10000){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.clear(sf::Color::Black);
	window.draw(text);
	window.draw(text1);
	window.display();

	while ((clock() - startTime) < 12000){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	window.clear(sf::Color::Black);
	window.draw(text);
	window.draw(text1);
	window.draw(text2);
	window.display();

	while ((clock() - startTime) < 16000){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed || menuEvent.type == sf::Event::EventType::KeyPressed){
				return;
			}
		}
	}
	return;

	
}