#pragma once
#include "VisibleGameObject.h"
#include "time.h"

class Player : public VisibleGameObject{
public:
	Player();
	Player(float x, float y);
	~Player();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	void SetPosition(float x, float y);

	float GetXVelocity() const;

private:
	int counter; // used to toggle walking textures

	bool inAir; // if jumping, true, if on ground, false
	bool movingRight; //if moving right, true, if moving left, false

	float _xAccel; //-- left, ++ right
	float _yAccel; // -- up, ++ down

	float _xVelocity; //-- left, ++ right
	float _yVelocity; // -- up, ++ down

	float _maxXVelocity;

	float _xDisplacement; // -- left, ++ right
	float _yDisplacement; //-- up, ++ down
};