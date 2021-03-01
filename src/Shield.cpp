#include <Shield.h>

using namespace godot;

void Shield::_register_methods() {
}

Shield::Shield(){

}
Shield::~Shield(){

}
void Shield::_init()
{
}

void Shield::_ready(){
    GameManager::player->shield = this;
}


