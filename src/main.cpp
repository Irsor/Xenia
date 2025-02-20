#include <fmt/core.h>
#include <GLFW/glfw3.h>

int main()
{
    if (!glfwInit())
    {
        fmt::println("Failed to initialize GLFW");
        return -1;
    }

    auto window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window)
    {
        fmt::println("Failed to create window");
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    return 0;
}