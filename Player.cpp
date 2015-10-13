#include "StdAfx.h"
#include "Player.h"
#include "Game.h"
#include <cassert>

// constructor, load image, set origin, initalize inAir to false
Player::Player() :  _xVelocity(0), _maxXVelocity(1500.0f), _yVelocity(0.0f), _xAccel(0), _yAccel(0), _xDisplacement(0), _yDisplacement(0){
	Load("C:/Users/Max/Documents/Visual Studio 2013/Projects/ShotgunBear/Pictures/Bear.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height);
	inAir = false;
}

// constructor, load image, set origin, set position, initalize inAir to false
Player::Player(float x, float y) : _xVelocity(0), _maxXVelocity(1500.0f), _yVelocity(0), _xAccel(0), _yAccel(0), _xDisplacement(0), _yDisplacement(0){
	Load("C:/Users/Max/Documents/Visual Studio 2013/Projects/ShotgunBear/Pictures/Bear.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height);
	GetSprite().setPosition(x, y);
	inAir = false;
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

	/* UPDATE LOGIC */
	if (Game::leftPressed && !Game::rightPressed){
		_xAccel = -5000.0f * elapsedTime;
	} else if (Game::rightPressed && !Game::leftPressed){
		_xAccel = 5000.0f  * elapsedTime;
	} else {
		_xAccel = 0.0f;
	}

	if (Game::upPressed){
		if (pos.y == Game::GROUND){ //this only validates if we determine that it's okay to jump
			_yAccel = -2000;
			inAir = true;
		}
	}


	// UPDATE VELOCITY 
	_xVelocity += _xAccel;
	_yVelocity += _yAccel;

	// reset x and y acceleration
	_xAccel = 0;
	_yAccel = 0;

	//deaccelerate
	if (!Game::rightPressed && !Game::leftPressed){
		if (_xVelocity > 200){
			_xVelocity -= 2500 * elapsedTime;
		}else if (_xVelocity < -200){
			_xVelocity += 2500 * elapsedTime;
		}else{
			_xVelocity = 0;
		}
	}
	
	//accelerate down due to gravity if in the air
	if (inAir){
		_yVelocity += 2500 * elapsedTime;
	}

	// UPDATE POSITIONS velocity/acceleration dependency 

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
	}

	// if touching either edge of the screen bounce in oposite direction
	if ((pos.x <= GetSprite().getLocalBounds().width / 2 && _xVelocity < 0) || (pos.x >= (Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2) && _xVelocity > 0)){
		_xVelocity = -_xVelocity;
	}

	_xDisplacement = _xVelocity * elapsedTime;

	// move player
	GetSprite().move(_xDisplacement, _yDisplacement);
}