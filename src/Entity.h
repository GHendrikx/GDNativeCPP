#ifndef ENTITY_H
#define ENTITY_H

#include <Godot.hpp>
#include <RigidBody.hpp>
#include <CSGMesh.hpp>
#include "GameManager.h"
#include "EntityManager.h"
#include<MeshInstance.hpp>
#include <Position3D.hpp>
#include <CSGMesh.hpp>
#include <PhysicsBody.hpp>
#include <KinematicBody.hpp>
#include "Player.h"

namespace godot
{

    class Entity : public RigidBody
    {
        GODOT_CLASS(Entity,RigidBody);

        public:
            Entity();
            ~Entity();
            static void _register_methods();
            void _init();
            void _ready();
            void _process(float delta);
            void _set_entity_type(int i);
           void _on_RigidBody_body_entered(PhysicsBody* node);

        private:
            float moveSpeed;
            bool hit = false;

    };

}

#endif