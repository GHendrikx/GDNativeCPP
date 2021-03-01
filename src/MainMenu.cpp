#include <MainMenu.h>

using namespace godot;

MainMenu::MainMenu(){
}
MainMenu::~MainMenu(){}
void MainMenu::_register_methods(){
    register_method((char*)"_on_StartButton_pressed", &MainMenu::_on_StartButton_pressed);
    register_method((char*)"_on_HighscoreButton_pressed", &MainMenu::_on_HighscoreButton_pressed);
    register_method((char*)"_on_Quit_pressed", &MainMenu::_on_Quit_pressed);
}

void MainMenu::_init(){}

void MainMenu::_on_StartButton_pressed(){
    Godot::print("Start");
    SceneTree* sceneTree = get_tree();
	sceneTree->change_scene("res://Scenes/MainGame.tscn");
}
void MainMenu::_on_HighscoreButton_pressed(){
    Godot::print("Highscore");
    SceneTree* sceneTree = get_tree();
    sceneTree->change_scene("res://Scenes/HighScore.tscn");
}

void MainMenu::_on_Quit_pressed(){
    
    Godot::print("Quit");
    SceneTree* sceneTree = get_tree();
	sceneTree->quit();
}