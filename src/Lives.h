#ifndef LIVES_H
#define LIVES_H

#include "GameManager.h"
#include <Godot.hpp>
#include <Label.hpp>
#include <string>
#include "ScoreIndicator.h"
#include "Highscore.h"

namespace godot {
    class Lives : public Label {
        GODOT_CLASS(Lives, Label);

    public:
        Lives();
        ~Lives();
        void _init();
        static void _register_methods();
        void _ready();
        void _update_Lives(int lives);
    private:
        int lives;
    };
}
#endif // LIVES_H