#include "window.hpp"

#include "raylib.h"

Window::Window(const char* title, std::size_t width, std::size_t height) {
    InitWindow(width, height, title);
}

Window::~Window() { CloseWindow(); }
