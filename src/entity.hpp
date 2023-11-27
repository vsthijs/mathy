#pragma once

#include <vector>
#include <string>

#include "assets.hpp"

#include "raylib.h"


// TODO: Refactor Animated to match naming convention
// TODO: Test Animated and Stacked


/// <summary>
/// Base class for all entities
/// </summary>
class Entity {
  public:
    virtual void init() = 0;
    virtual void tick() = 0;
    virtual void update(double dt) = 0;
    virtual void render(Vector2 pos) = 0;
};


class Animated : public Entity {
  public:
    Animated(std::vector<std::vector<Texture2D>> animations);
    ~Animated();

  protected:
    unsigned int current_animation = 0;
  
  private:
    unsigned int current_frame = 0;
    std::vector<std::vector<Texture2D>> animations;
    Texture2D get_current_frame();
};

/// <summary>
/// An entity that draws a semi-3D sprite by stacking images on top of each other.
/// </summary>
class Stacked : public Entity {
  public:
    Stacked(std::string sprite_name, std::size_t count, AssetManager am);
    ~Stacked();

    void render(Vector2 pos) override;

  protected:
    float p_rotation;

  private:
    std::vector<Texture2D> textures;
};