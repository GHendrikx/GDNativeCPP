#include "Lives.h"

using namespace godot;

Lives::Lives() {}

Lives::~Lives() {}

void Lives::_init()
{
    GameManager::lives = this;

    lives = 3;
    std::string str = std::to_string(lives);
    godot::String godotString = godot::String(str.c_str());
    set_text("X " + godotString);
}

void Lives::_ready() {}

void Lives::_register_methods() {}

void Lives::_update_Lives(int updatedLives)
{
    lives -= updatedLives;
    std::string playerLives = std::to_string(lives);
    godot::String godotString = godot::String(playerLives.c_str());
    set_text("X " + godotString);

    if(lives == 0) {
        Godot::print("Game Over");
        //Save Score
        ScoreIndicator score;
        Highscore::_set_highscore(score.CurrentScore);
        SceneTree* sceneTree = get_tree();
        sceneTree->change_scene("res://Scenes/Menu.tscn");
    }
}

