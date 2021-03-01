#include "Lives.h"
#include "ScoreIndicator.h"
#include "Highscore.h"
#include "MainMenu.h"
#include "EntityManager.h"
#include "Entity.h"
#include "Attack.h"
#include "Shield.h"
#include "Player.h"
#include "InputManager.h"
#include "GameManager.h"
#include <Godot.hpp>
#include "gdtest.hpp"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) 
{
	godot::Godot::nativescript_init(handle);
		godot::register_class<godot::Lives>();
    godot::register_class<godot::ScoreIndicator>();
    godot::register_class<godot::Highscore>();
    godot::register_class<godot::MainMenu>();
    godot::register_class<godot::EntityManager>();
    godot::register_class<godot::Entity>();
    godot::register_class<godot::Attack>();
    godot::register_class<godot::Shield>();
    godot::register_class<godot::Player>();
	godot::register_class<godot::InputManager>();
	godot::register_class<godot::GameManager>();
	godot::register_class<godot::GDTest>();
}