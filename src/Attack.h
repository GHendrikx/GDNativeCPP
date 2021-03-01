#ifndef ATTACK_H
#define ATTACK_H

#include <Godot.hpp>
#include <CSGMesh.hpp>
#include <CollisionShape.hpp>
#include <CollisionObject.hpp>
#include <Kinematicbody.hpp>
#include <SceneTree.hpp>
#include "GameManager.h"
#include "Node.hpp"
#include <Ref.hpp>
#include <RayCast.hpp>
#include <Godot.hpp>
#include <RigidBody.hpp>
#include <KinematicCollision.hpp>

namespace godot
{
    class Attack : public RigidBody
    {
        GODOT_CLASS(Attack, KinematicBody);

    public:
        static void _register_methods();
        Attack();
        ~Attack();
        void _init();
        void _ready();
        bool attack;
        bool visible;
        //void _shootRay();
        void _process();
        void _on_CollisionShape_visibility_changed(Variant);
        void _on_RigidBody_body_entered(PhysicsBody *body);
    };

} // namespace godot

#endif