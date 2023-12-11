#include "assets.hpp"

AssetManager::AssetManager(std::string base_path) : p_base_path(base_path) {
    this->p_texture_cache = std::map<std::string, Texture2D>{};
}

AssetManager::~AssetManager() {}

Texture2D AssetManager::require_texture(std::string path) {
    auto search = this->p_texture_cache.find(path);
    if (search != this->p_texture_cache.end()) {
        return this->p_texture_cache[path];
    } else {
        this->p_texture_cache[path] =
            LoadTexture((this->p_base_path + path).c_str());
        return this->p_texture_cache[path];
    }
}

std::vector<Texture2D>
AssetManager::require_textures(std::vector<std::string> paths) {
    std::vector<Texture2D> textures{};
    textures.reserve(paths.size());
    for (std::string path : paths) {
        this->require_texture(path);
    }
    return textures;
}

Sound AssetManager::require_sound(std::string path) {
    return LoadSound((this->p_base_path + path).c_str());
}