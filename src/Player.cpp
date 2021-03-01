#include "Player.h"

using namespace godot;

Player::Player() {}
Player::~Player() {}

void Player::_register_methods()
{
    register_method("_process", &Player::_process);
    register_property<Player, float>("Speed", &Player::speed, 0.5f);
}

void Player::_process(float delta)
{
}

void Player::_rotate(float degrees)
{
    //making the rotation vector.
    Vector3 rotation = Vector3(get_rotation_degrees().x, get_rotation_degrees().y - degrees * speed,
                               get_rotation_degrees().z);

    set_rotation_degrees(rotation);
}

void Player::_ready()
{
}

void Player::_init()
{
    GameManager::player = this;
    Player::damage = 1;
}

void Player::_attack(bool active)
{
    Spatial *spatial = static_cast<Spatial *>(get_node("Attack"));
    if (!Player::initializeSpawnPositions)
    {
        GameManager::entitymanager->_search_spawn_positions();
        Player::initializeSpawnPositions = true;
    }

    if (active)
    {
        if (!Player::shieldActive)
        {
            Player::swordActive = active;
            spatial->show();
        }
    }
    else
    {
        Player::swordActive = false;
        spatial->hide();
    }
}
void Player::_defend(bool active)
{
    Spatial *spatial = static_cast<Spatial *>(get_node("Shield"));

    if (spatial == NULL)
        return;

    if (active)
    {
        if (!Player::swordActive)
        {
            Player::shieldActive = active;
            spatial->show();
        }
    }
    else
    {
        Player::shieldActive = false;
        spatial->hide();
    }
}

void Player::hit(){
    GameManager::lives->_update_Lives(Player::damage);
}
