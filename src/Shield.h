#ifndef SHIELD_H
#define SHIELD_H

#include <Godot.hpp>
#include <Spatial.hpp>
#include <GameManager.h>


namespace godot {

    class Shield : public Spatial{
        GODOT_CLASS(Shield,Spatial);

    public:
        static void _register_methods();
        void _ready();
        Shield();
        ~Shield();
        void _init();
        bool defend;
    };
}
#endif