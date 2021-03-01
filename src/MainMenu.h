#ifndef MAINMENU_H
#define MAINMENU_H

#include <Godot.hpp>
#include <Control.hpp>
#include <Tree.hpp>
#include <SceneTree.hpp>

namespace godot{
    class MainMenu : public Control{
        GODOT_CLASS(MainMenu,Control);

        public:
            MainMenu();
            ~MainMenu();
            void _init();
            
            void _on_StartButton_pressed();
            void _on_HighscoreButton_pressed();
            void _on_Quit_pressed();

            static void _register_methods();

    };
}
#endif // MAINMENU_H