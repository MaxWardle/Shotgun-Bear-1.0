#include "StdAfx.h"
#include "Player.h"
#include "Game.h"
#include <cassert>

sf::Texture walkLeftTexture1;
sf::Texture walkLeftTexture2;
sf::Texture walkRightTexture1;
sf::Texture walkRightTexture2;
sf::Texture jumpLeftTexture;
sf::Texture jumpRightTexture;

// constructor, load image, set origin, initalize inAir to false
Player::Player() :  _xVelocity(0), _maxXVelocity(1500.0f), _yVelocity(0.0f), _xAccel(0), _yAccel(0), _xDisplacement(0), _yDisplacement(0){
	Load("\../Pictures/BearWalkRight1.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height);
	inAir = false;

	//load textures
	walkLeftTexture1.loadFromFile("\../Pictures/BearWalkLeft1.png");
	walkLeftTexture2.loadFromFile("\../Pictures/BearWalkLeft2.png");
	walkRightTexture1.loadFromFile("\../Pictures/BearWalkRight1.png");
	walkRightTexture2.loadFromFile("\../Pictures/BearWalkRight2.png");
	jumpLeftTexture.loadFromFile("\../Pictures/BearJumpLeft.png");
	jumpRightTexture.loadFromFile("\../Pictures/BearJumpRight.png");

	//initalize counter
	counter = 0;
}

// constructor, load image, set origin, set position, initalize inAir to false
Player::Player(float x, float y) : _xVelocity(0), _maxXVelocity(1500.0f), _yVelocity(0), _xAccel(0), _yAccel(0), _xDisplacement(0), _yDisplacement(0){
	Load("\../Pictures/BearWalkRight1.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height);
	GetSprite().setPosition(x, y);
	inAir = false;

	walkLeftTexture1.loadFromFile("\../Pictures/BearWalkLeft1.png");
	walkLeftTexture2.loadFromFile("\../Pictures/BearWalkLeft2.png");
	walkRightTexture1.loadFromFile("\../Pictures/BearWalkRight1.png");
	walkRightTexture2.loadFromFile("\../Pictures/BearWalkRight2.png");
	jumpLeftTexture.loadFromFile("\../Pictures/BearJumpLeft.png");
	jumpRightTexture.loadFromFile("\../Pictures/BearJumpRight.png");

	counter = 0;
}

Player::~Player(){
}

// sets position of player
void Player::SetPosition(float x, float y){
	GetSprite().setPosition(x, y);
}

// draws player
void Player::Draw(sf::RenderWindow & rw){
	VisibleGameObject::Draw(rw);
}

// gets x velocity
float Player::GetXVelocity() const{
	return _xVelocity;
}

// updates player positon based on key input and game perameters
void Player::Update(float elapsedTime){



	sf::Vector2f pos = this->GetPosition();

	// update logic
	
	if (Game::upPressed){
		if (pos.y == Game::GROUND){ //this only validates if we determine that it's okay to jump
			_yAccel = -2000;
			inAir = true;

			//inital jump texture
			if (movingRight){
				GetSprite().setTexture(jumpRightTexture);
			}else{
				GetSprite().setTexture(jumpLeftTexture);
			}

		}
	}	
	
	if (Game::leftPressed && !Game::rightPressed){
		movingRight = false;

		// accelerate left
		_xAccel = -5000.0f * elapsedTime;
		
		//handle moving left textures
		if (inAir){
			GetSprite().setTexture(jumpLeftTexture);
		}
		else{
			counter++;
			if (counter < 10){
				GetSprite().setTexture(walkLeftTexture1);
			}
			if (counter > 10){
				GetSprite().setTexture(walkLeftTexture2);
			}
			if (counter > 20){
				counter = 0;
			}
		}
	} else if (Game::rightPressed && !Game::leftPressed){
		movingRight = true;
		
		// accelerate right
		_xAccel = 5000.0f  * elapsedTime;

		//handle moving right textures
		if (inAir){
			GetSprite().setTexture(jumpRightTexture);
		}
		else{
			counter++;
			if (counter < 10){
				GetSprite().setTexture(walkRightTexture1);
			}
			if (counter > 10){
				GetSprite().setTexture(walkRightTexture2);
			}
			if (counter > 20){
				counter = 0;
			}
		}
	} else {
		// no acceleration
		_xAccel = 0.0f;

		// walking texture 1 looks better
		if (!inAir){
			if (movingRight){
				GetSprite().setTexture(walkRightTexture1);
			}
			else{
				GetSprite().setTexture(walkLeftTexture1);
			}
		}
	}

	// update velocity
	_xVelocity += _xAccel;
	_yVelocity += _yAccel;

	// reset x and y acceleration
	_xAccel = 0;
	_yAccel = 0;

	// deaccelerate
	if (!Game::rightPressed && !Game::leftPressed){
		if (_xVelocity > 200){
			_xVelocity -= 4000 * elapsedTime;
		}else if (_xVelocity < -200){
			_xVelocity += 4000 * elapsedTime;
		}else{
			_xVelocity = 0;
		}
	}
	
	// accelerate down due to gravity if in the air
	if (inAir){
		_yVelocity += 4000 * elapsedTime;
	}

	// update positions velocity/acceleration dependency 

	// set speed limit
	if (_xVelocity > _maxXVelocity){
		_xVelocity = _maxXVelocity;
	}
	if (_xVelocity < -_maxXVelocity){
		_xVelocity = -_maxXVelocity;
	}


	_yDisplacement = _yVelocity*elapsedTime;
	
	// if beneath the ground, set y pos to ground, y displacement to 0, y velocity to 0, and state that player is no longer jumping
	if (pos.y > Game::GROUND){
		SetPosition(pos.x, Game::GROUND);
		_yDisplacement = 0;
		_yVelocity = 0;
		inAir = false;

		//initial ground texture
		if (movingRight){
			GetSprite().setTexture(walkRightTexture1);
		}
		else{
			GetSprite().setTexture(walkLeftTexture1);
		}
	}

	// if touching either edge of the screen bounce in oposite direction
	if ((pos.x <= GetSprite().getLocalBounds().width / 2 && _xVelocity < 0) || (pos.x >= (Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2) && _xVelocity > 0)){
		_xVelocity = -_xVelocity;
	}

	_xDisplacement = _xVelocity * elapsedTime;

	// move player
	GetSprite().move(_xDisplacement, _yDisplacement);
}