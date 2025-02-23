#define GLFW_INCLUDE_VULKAN
#include <fmt/core.h>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>
#include "Core/RenderCore.hpp"


int main()
{
    xe::RenderCore renderCore;

    if (!glfwInit())
    {
        fmt::println("Failed to initialize GLFW");
        return -1;
    }

    auto window = glfwCreateWindow(640, 480, "Xenia", nullptr, nullptr);
    if (!window)
    {
        fmt::println("Failed to create window");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    return 0;
}