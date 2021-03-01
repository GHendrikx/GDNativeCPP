#include <Entity.h>

using namespace godot;

Entity::Entity() {}

Entity::~Entity() {}

void Entity::_register_methods() {
    register_method("_on_RigidBody_body_entered", &Entity::_on_RigidBody_body_entered);
    register_method("_process", &Entity::_process);
    register_property("moveSpeed", &Entity::moveSpeed, 10.0f);
}

void Entity::_init() {
//    Vector3 rotation(90,90,0);
}

void Entity::_set_entity_type(int i) {
}

void Entity::_ready() {
}

void Entity::_process(float delta) {
//    Vector3 direction = Vector3(get_translation().x, get_translation().y, get_translation().z + delta * moveSpeed);
//    move_and_slide(Vector3(get_translation().x, get_translation().y, get_translation().z + delta * moveSpeed));
    set_translation(Vector3(get_translation().x, get_translation().y, get_translation().z + delta * moveSpeed));
}

void Entity::_on_RigidBody_body_entered(PhysicsBody *body) {
    if (Entity::hit)
        return;

    if(body->get_name() == "Sword") return;
    if(body->get_name() == "Player")
    {
        Godot::print("player");
        GameManager::player->hit();
    }

    Entity::hit = true;
    hide();
}