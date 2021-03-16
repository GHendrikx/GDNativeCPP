#include <Highscore.h>

using namespace godot;

Highscore::Highscore(){
}
Highscore::~Highscore(){}

void Highscore::_register_methods(){
    register_method("_ready", &Highscore::_ready);
    //register_method((char*)"_get_highscore",&Highscore::_get_highscore);

    register_method((char*)"_on_ReturnButton_pressed", &Highscore::_on_ReturnButton_pressed);

}

void Highscore::_init() {}

//GetNode cant be called in the Init function you need to call it in the ready funciton.
void Highscore::_ready(){
    _get_highscore();
}

void Highscore::_set_highscore(int score){
	std::ofstream highscoreFile;
    highscoreFile.open("highscore.txt",std::ios_base::app);

    highscoreFile << std::to_string(score) + "\n";
    highscoreFile.close();
}
void Highscore::_get_highscore() {

    std::ifstream myfile("highscore.txt");
    std::vector<int> scores;
    std::string line;

    for(int i = 0; i<3;i++){
        //the highscore has everytime 3 places. if you didn't do any game the highscore is 0.
        scores.push_back(0);
    }

    while (std::getline(myfile, line)) {
        // object from the class stringstream
        std::stringstream geek(line);

        // The object has the value 12345 and stream
        // it to the integer x
        int x = 0;
        geek >> x;
        scores.push_back(x);
    }



    std::sort(scores.begin(), scores.end(), std::greater<int>());

    for (int i = 1; i < 4; i++) {
        godot::String nodeString = "./Place" + godot::String(std::to_string(i).c_str());
        Label *node = static_cast<Label *>(get_node(NodePath(nodeString)));
        if (node != nullptr) {
            godot::String number = godot::String(std::to_string(i).c_str());
            godot::String Score = godot::String(std::to_string(scores.at(i - 1)).c_str());
            node->set_text("#" + number + " = " + Score);
        }
    }
}
void Highscore::_on_ReturnButton_pressed() {
    Godot::print("Return");
    SceneTree* sceneTree = get_tree();
    sceneTree->change_scene("res://Scenes/Menu.tscn");
    }

