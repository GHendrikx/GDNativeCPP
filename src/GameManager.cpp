/*
This GameManager is going to serve as a base class for everything.
Creating the highscore for the highscore manager.

*/

#include "GameManager.h"

using namespace godot;

EntityManager *GameManager::entitymanager;
GameManager *GameManager::instance;
Player *GameManager::player;
Lives *GameManager::lives;

void GameManager::_init()
{
    GameManager::instance = this;
}

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
}
void GameManager::_process()
{
}
void GameManager::_register_methods()
{
    register_method("_process", &GameManager::_process);
}
