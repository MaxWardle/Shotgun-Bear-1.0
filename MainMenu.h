#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>
#include "time.h"

class MainMenu{

public :
	enum MenuResult {Nothing, Exit, Play};
	MenuResult Show(sf::RenderWindow& window);

private:
	enum MessageShowing { Showing, NotShowing };
	MessageShowing _messageShowing;
};