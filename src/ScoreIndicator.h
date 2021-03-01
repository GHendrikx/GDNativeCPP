#ifndef SCOREINDICATOR_H
#define SCOREINDICATOR_H

#include <Godot.hpp>
#include <Label.hpp>
#include <fstream>
#include <string>
namespace godot {
    class ScoreIndicator : public Label{
        GODOT_CLASS(ScoreIndicator,Label)

    public:
        ScoreIndicator();
        ~ScoreIndicator();
        static void _register_methods();
        void _init();
        void _ready();
        void _on_ScoreTimer_timeout();
        static void _save_score();
        static int CurrentScore;
    };
}

#endif //SCOREINDICATOR_H
