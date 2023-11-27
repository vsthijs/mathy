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

Stacked::Stacked(std::string sprite_name, std::size_t count, AssetManager am) {
    this->textures = std::vector<Texture2D>{};
    this->p_rotation = 0;

    for (int i = 0; i < count; i++) {
        this->textures.push_back(
            am.require_texture(sprite_name + std::to_string(i)));
    }
}

Stacked::~Stacked() {}

void Stacked::render(Vector2 pos) {
    int offset = 0;
    for (const Texture2D texture : this->textures) {
        DrawTextureEx(texture, Vector2{pos.x, pos.y + (offset++)}, this->p_rotation, 1, WHITE);
    }
}