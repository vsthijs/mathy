#pragma once

#include <vector>

#include "raylib.h"


/// <summary>
/// Base class for all entities
/// </summary>
class Entity {
  public:
    virtual void init() = 0;
    virtual void tick() = 0;
    virtual void update(double dt) = 0;
    virtual void render() = 0;
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
