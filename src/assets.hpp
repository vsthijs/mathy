#pragma once

#include <string>
#include <vector>
#include <map>

#include "raylib.h"

/*
TODO: test texture loading
*/

/// <summary>
/// Used to load and get assets.
/// </summary>
class AssetManager {
  public:
    AssetManager(std::string base_path);
    ~AssetManager();

    /// <summary>
    /// Load a texture.
    /// </summary>
    /// <param name="path">relative path to the texture</param>
    Texture2D require_texture(std::string path);
    std::vector<Texture2D> require_textures(std::vector<std::string> paths);

  private:
    std::string p_base_path;
    std::map<std::string, Texture2D> p_texture_cache;
};