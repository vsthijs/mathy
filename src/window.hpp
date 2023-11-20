#include <cstddef>


class Window {
  public:
    Window(const char *title, std::size_t width, std::size_t height);
    ~Window();
};