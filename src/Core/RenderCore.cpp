#include "RenderCore.hpp"

xe::RenderCore::RenderCore()
{
    this->InitVulkan();
}

xe::RenderCore::~RenderCore()
{
    fmt::println("Destroying Vulkan instance");
    vkDestroyInstance(this->instance, nullptr);
}

void xe::RenderCore::CreateInstance()
{
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Xenia";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";  
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_4;
    
    // Vulkan extnsions
    std::array<const char*, 2> glfwExtensions = { "VK_KHR_surface", "VK_KHR_win32_surface" };
    
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = static_cast<uint32_t>(glfwExtensions.size());
    createInfo.ppEnabledExtensionNames = glfwExtensions.data();
    createInfo.enabledLayerCount = 0;   
    
    auto instanceResult = vkCreateInstance(&createInfo, nullptr, &this->instance); 
    
    if (instanceResult != VK_SUCCESS)
    {
        fmt::println("Failed to create Vulkan instance");    
        exit(EXIT_FAILURE);
    }
}

void xe::RenderCore::InitVulkan()
{
    this->CreateInstance();
}
