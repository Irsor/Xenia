#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Engine/VulkanApp.hpp"


int main()
{
    xe::VulkanApp app;
    auto window = app.getWindow();
     
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    return 0;
}