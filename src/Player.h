#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <MeshInstance.hpp>
#include <Position3D.hpp>
#include "Shield.h"
#include "Attack.h"
#include "GameManager.h"
#include <Node.hpp>
#include <Spatial.hpp>
#include <Input.hpp>
#include <Position3D.hpp>

namespace godot
{

class Shield;
class Attack;
    class Player : public MeshInstance
    {
    GODOT_CLASS(Player,MeshInstance);

    public:
        Player();
        ~Player();
        void _init();
        void _ready();
        void _process(float delta);
        static void _register_methods();
        void hit();

        //rotate the mesh
        void _rotate(float degrees);
        void _attack(bool active);
        void _defend(bool active);
        Attack* attack;
        Shield* shield;

        private:
            int damage;
            float speed;
            bool shieldActive;
            bool swordActive;
            bool initializeSpawnPositions = false;
    };
}
#endif /*PLAYER_H*/