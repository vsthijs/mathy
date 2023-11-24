#pragma once

#include <string>
#include <vector>

#include "raylib.h"

/*
TODO: implement AssetManager in assets.cpp
*/

/// <summary>
/// Used to load and get assets.
/// </summary>
class AssetManager {
  public:
    AssetManager(std::string base_path);
    ~AssetManager();

    /// <summary>
    /// Load a texture on-demand
    /// </summary>
    /// <param name="path">relative path to the texture</param>
    Texture2D require_texture(std::string path);

    /// <summary>
    /// Load an entire animation
    /// </summary>
    /// <param name="prefix">The path to the assets.</param>
    /// <param name="r_begin">The begin of the range</param>
    /// <param name="r_end">The end of the range</param>
    /// <returns>A vector of textures</returns>
    std::vector<Texture2D> require_animation(std::string prefix, size_t r_begin, size_t r_end);

  private:
    std::vector<Texture2D> p_textures;
    std::vector<std::string> p_texture_paths;
    std::string p_base_path;
};