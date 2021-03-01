#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Player.h>
#include <PackedScene.hpp>
#include "GameManager.h"
#include <Input.hpp>

namespace godot {
    class InputManager : public Node{
        GODOT_CLASS(InputManager,Node);

    public:
        InputManager();
        ~InputManager();
        void _init();
        void _process(float delta);
        static void _register_methods();
        String path;
    private:
        Ref<PackedScene> playerScene;
    };
}
#endif /*!INPUTMANAGER_H*/