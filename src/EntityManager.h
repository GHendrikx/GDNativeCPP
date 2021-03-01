#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <Godot.hpp>
#include <Node.hpp>
#include <GameManager.h>
#include <Spatial.hpp>
#include <string>
#include <PackedScene.hpp>
#include <Resource.hpp>
#include <ResourceLoader.hpp>

// Default vs libs
#include <iostream>
#include <vector>
#include <cstdlib>

namespace godot
{
    class EntityManager : public Spatial
    {
        GODOT_CLASS(EntityManager, Spatial);

    public:
        EntityManager();
        ~EntityManager();
        void _init();
        void _ready();
        void _progress();
        static void _register_methods();
        void _add_entity();
        void _remove_entity();
        void _search_spawn_positions();
        void _on_Timer_timeout();

    private:
        Ref<PackedScene> entityScene;
        std::vector<Spatial *> spawnPositions;
    };
} // namespace godot

#endif /*ENTITYMANAGER_H*/