#include "stdafx.h"
#include "GameObjectManager.h"
#include "Game.h"

GameObjectManager::GameObjectManager(){

}

GameObjectManager::~GameObjectManager(){
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

// add visible game object to object manager map
void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject){
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

// remove visible game object from object manager map
void GameObjectManager::Remove(std::string name){
    std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end()){
		delete results->second;
		_gameObjects.erase(results);
	}
}

// get visibe game object from object manager map, if it isn't found, return null
VisibleGameObject* GameObjectManager::Get(std::string name) const{
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end())
		return NULL;
	return results->second;

}

// get number of game objects in map
int GameObjectManager::GetObjectCount() const{
	return _gameObjects.size();
}

// draws all of the game objects in the map
void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow){
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end()){
		itr->second->Draw(renderWindow);
		itr++;
	}
}

// updates all of the game objects in the map based on the time elapsed between frames
void GameObjectManager::UpdateAll(){
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	
	double timeDelta = 1.0/Game::FRAME_RATE; // time between frames in sec

	while (itr != _gameObjects.end()){
		itr->second->Update(timeDelta);
		itr++;
	}

}