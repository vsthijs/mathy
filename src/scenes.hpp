#pragma once

#include <vector>

class SceneManager;

// TODO: Test Scene and SceneManager

/// <summary>
/// Base class for all scenes.
/// 
/// A scene should take care of rendering and updating the
/// entities when needed.
/// </summary>
class Scene {
  public:
    Scene(const SceneManager *parent);
    ~Scene();

    bool is_loaded();

    virtual void load() = 0;
    virtual void unload() = 0;
    virtual void update() = 0;

  private:
    const SceneManager *__parent;
    bool __is_loaded;
};

/// <summary>
/// Manages all scenes. 
/// </summary>
class SceneManager {
  public:
    SceneManager(Scene *first_scene);
    ~SceneManager();

    Scene *get_current_scene();
    size_t add_scene(Scene *scene);
    void load_scene(size_t index);
    void unload_all();

  private:
    size_t curr_scene;
    size_t next_scene;
    std::vector<Scene *> scenes;
};
