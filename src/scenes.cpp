#include "scenes.hpp"

Scene::Scene(const SceneManager *parent) :__parent(parent), __is_loaded(false) {}

Scene::~Scene() {}

bool Scene::is_loaded() { return this->__is_loaded; }

SceneManager::SceneManager(Scene *first_scene) {
    this->curr_scene = 0;
    this->scenes = std::vector<Scene *>{};
}

SceneManager::~SceneManager() {}

Scene *SceneManager::get_current_scene() {
    return this->scenes[this->curr_scene];
}

size_t SceneManager::add_scene(Scene *scene) {
    this->scenes.push_back(scene);
    return this->scenes.size() - 1;
}

void SceneManager::load_scene(size_t index) {
    this->next_scene = index;
    this->scenes[this->next_scene]->load();
}

void SceneManager::unload_all() {
    for (Scene *scene : this->scenes) {
        scene->unload();
    }
}