#include <Attack.h>

using namespace godot;

Attack::Attack() {}
Attack::~Attack() {}

void Attack::_register_methods()
{
    register_method((char*)"_on_RigidBody_body_entered", &Attack::_on_RigidBody_body_entered);
    register_method("_process", &Attack::_process);
    register_method((char*)"_on_CollisionShape_visibility_changed", &Attack::_on_CollisionShape_visibility_changed);
}

void Attack::_init() {
    GameManager::player->attack = this;
    Attack::visible = true;
}

void Attack::_on_CollisionShape_visibility_changed(Variant) {
    Attack::visible = !Attack::visible;
    if(Attack::visible)
        Godot::print("true");
    if(!Attack::visible)
        Godot::print("false");
}
void Attack::_ready()
{
}

void Attack::_process()
{

}

void Attack::_on_RigidBody_body_entered(PhysicsBody *body){

    if(!Attack::visible) return;

    if(body->is_visible())
    {
        body->set_physics_process(false);
        body->hide();
        body->queue_free();
        Godot::print("Attack");
    }
}