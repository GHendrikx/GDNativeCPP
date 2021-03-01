//
// Created by geoffrey on 10/02/2021.
//

#include "ScoreIndicator.h"

using namespace godot;
int ScoreIndicator::CurrentScore;
ScoreIndicator::ScoreIndicator() {}
ScoreIndicator::~ScoreIndicator() {}

void ScoreIndicator::_register_methods() {
    register_method((char*)"_on_ScoreTimer_timeout", &ScoreIndicator::_on_ScoreTimer_timeout);
}

void ScoreIndicator::_init() {
    set_text("ready");
    ScoreIndicator::CurrentScore = 0;
}

void ScoreIndicator::_ready() {

}

void ScoreIndicator::_on_ScoreTimer_timeout() {
    ScoreIndicator::CurrentScore++;
    std::string score = std::to_string(ScoreIndicator::CurrentScore);
    godot::String godotString = godot::String(score.c_str());
    set_text("score " + godotString);
}