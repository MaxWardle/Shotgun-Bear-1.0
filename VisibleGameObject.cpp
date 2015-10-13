#include "StdAfx.h"
#include "VisibleGameObject.h"


VisibleGameObject::VisibleGameObject(){
	_isLoaded = false;
}


VisibleGameObject::~VisibleGameObject(){

}

void VisibleGameObject::Load(std::string filename){

	if (_texture.loadFromFile(filename) == false){
		_filename = "";
		_isLoaded = false;
		printf("the image was NOT loaded\n");
	}else{
		_filename = filename;
		_sprite.setTexture(_texture);
		_isLoaded = true;
		printf("the image was loaded\n");
	}
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow){
	if (_isLoaded){
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::Update(float elapsedTime){
	
}

void VisibleGameObject::SetPosition(float x, float y){
	if (_isLoaded){
		_sprite.setPosition(x, y);
		printf("the position was set with coordinates: (%d, %d)\n", x, y);
	}
	else{
		printf("the position was NOT set\n");
	}
}

sf::Vector2f VisibleGameObject::GetPosition() const{
	if (_isLoaded){
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::GetSprite(){
	return _sprite;
}

bool VisibleGameObject::IsLoaded()const{
	return _isLoaded;
}