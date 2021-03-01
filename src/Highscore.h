#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <Godot.hpp>
#include <Node.hpp>
#include <Control.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <Label.hpp>
#include <Spatial.hpp>
#include <Tree.hpp>
#include <SceneTree.hpp>

namespace godot{
class Highscore : public Control{
    GODOT_CLASS(Highscore, Control)

        public:
            Highscore();
            ~Highscore();
            static void _register_methods();
            void _init();
            void _ready();
            static void _set_highscore(int score);
            void _get_highscore();
            void _on_ReturnButton_pressed();
    };
}
#endif