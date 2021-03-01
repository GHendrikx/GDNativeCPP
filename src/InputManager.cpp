#include <InputManager.h>

using namespace godot;
//get_base_script ( )
void InputManager::_init()
{
}

//Getting al the inputs and assign it to the actions
void InputManager::_process(float delta)
{
   Input *input = Input::get_singleton();
   if (input->is_action_pressed("ui_right"))
      GameManager::player->_rotate(1);
   if (input->is_action_pressed("ui_left"))
      GameManager::player->_rotate(-1);

   if (input->is_action_pressed("attack"))
      GameManager::player->_attack(true);
   if (!input->is_action_pressed("attack"))
      GameManager::player->_attack(false);

   if (input->is_action_pressed("defend"))
      GameManager::player->_defend(true);
   if (!input->is_action_pressed("defend"))
      GameManager::player->_defend(false);
}

void InputManager::_register_methods()
{
   register_method("_process", &InputManager::_process);
   register_property<InputManager, String>("Path", &InputManager::path, "");
}

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}