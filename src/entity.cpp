#include "entity.hpp"

Animated::Animated(std::vector<std::vector<Texture2D>> __animations) {
    this->animations = __animations;
}

Animated::~Animated() {}

Texture2D Animated::get_current_frame() {
    if (this->current_frame <
        this->animations[this->current_animation].size()) {
        return this->animations[this->current_animation][this->current_frame++];
    } else {
        this->current_frame = 0;
        return this->animations[this->current_animation][this->current_frame++];
    }
}