#include <EntityManager.h>

using namespace godot;

EntityManager::EntityManager() {
    ResourceLoader* rl = ResourceLoader::get_singleton();
    EntityManager::entityScene = rl->load("res://Scenes/Entity.tscn");
}
EntityManager::~EntityManager() {}

void EntityManager::_init()
{
    GameManager::entitymanager = this;
}

void EntityManager::_ready()
{
    Godot::print("Ready");
}

void EntityManager::_progress() {}

void EntityManager::_register_methods()
{
    register_method((char*)"_on_Timer_timeout", &EntityManager::_on_Timer_timeout);

}

void EntityManager::_add_entity() {
    Node *node = (Node *) EntityManager::entityScene->instance();
    node->set_name("Enemy");
    Spatial* s = static_cast<Spatial*>(node);

    s->set_rotation_degrees(Vector3(0,0,0));
    int i = rand() % 4;
    int angle = 0;
    s->set_translation(EntityManager::spawnPositions[i]->get_translation());
    add_child(s);
    s->set_rotation(Vector3(EntityManager::spawnPositions[i]->get_rotation().x,EntityManager::spawnPositions[i]->get_rotation().y,EntityManager::spawnPositions[i]->get_rotation().z));
}
void EntityManager::_on_Timer_timeout() {
    _add_entity();
}

void EntityManager::_search_spawn_positions()
{
    for (int i = 0; i < 4; i++)
    {

        godot::String spawn = "spawn";
        godot::String nodeString = spawn + godot::String(std::to_string(i).c_str());
        Spatial *spatial = static_cast<Spatial *>(get_node(NodePath(nodeString)));
        Godot::print(nodeString);

        if (spatial != NULL)
        {
            EntityManager::spawnPositions.push_back(spatial);
        }
    }
}