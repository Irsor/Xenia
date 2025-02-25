#include <memory>

#include <vulkan/vulkan.hpp>
#include <fmt/core.h>
#include <GLFW/glfw3.h>

namespace xe
{
    class VulkanApp
    {
    public:
        VulkanApp();
        ~VulkanApp();
        
       GLFWwindow* getWindow();

    private:
        vk::UniqueInstance instance;
        GLFWwindow* window;
        vk::UniqueDevice device;

        void initWindow();
        void initVulkan();
        void createLogicalDevice();
    };
}