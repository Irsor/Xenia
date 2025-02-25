#include "VulkanApp.hpp"

xe::VulkanApp::VulkanApp()
{
    initWindow();
    initVulkan();
    createLogicalDevice();
}

xe::VulkanApp::~VulkanApp()
{
    instance.reset();
    glfwTerminate();
}

GLFWwindow* xe::VulkanApp::getWindow()
{
    return window;
}

void xe::VulkanApp::initWindow()
{
    if (!glfwInit())
    {
        fmt::println("Failed to initialize GLFW");
        exit(EXIT_FAILURE);
    }
     
    window = glfwCreateWindow(640, 480, "Xenia", nullptr, nullptr);
    if (!window)
    {
        fmt::println("Failed to create window");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
}

void xe::VulkanApp::initVulkan()
{
    vk::ApplicationInfo applicationInfo{};
    applicationInfo.setPApplicationName("Xenia")
        .setApiVersion(VK_API_VERSION_1_4)
        .setApplicationVersion(VK_MAKE_VERSION(1, 0, 0))
        .setPEngineName("No Engine");

    std::array<const char*, 2> glfwExtensions = { "VK_KHR_surface", "VK_KHR_win32_surface" };

    vk::InstanceCreateInfo instanceCreateInfo{};
    instanceCreateInfo.setPApplicationInfo(&applicationInfo)
        .setEnabledExtensionCount(glfwExtensions.size())
        .setPpEnabledExtensionNames(glfwExtensions.data())
        .setEnabledLayerCount(0);

    instance = vk::createInstanceUnique(instanceCreateInfo);  
}

void xe::VulkanApp::createLogicalDevice()  
{  
   auto physicalDevice = instance.get().enumeratePhysicalDevices()[0];  

   vk::PhysicalDeviceFeatures requiredFeatures{};
   requiredFeatures.multiDrawIndirect = VK_TRUE;
   requiredFeatures.tessellationShader = VK_TRUE;
   requiredFeatures.geometryShader = VK_TRUE;

   vk::DeviceQueueCreateInfo queueCreateInfo{};  
   queueCreateInfo.setQueueFamilyIndex(0)
       .setQueueCount(1);
 
   vk::DeviceCreateInfo deviceCreateInfo{};  
   std::array<vk::DeviceQueueCreateInfo, 1> queueCreateInfos = { queueCreateInfo };  
   deviceCreateInfo.setQueueCreateInfoCount(static_cast<uint32_t>(queueCreateInfos.size()))  
       .setPQueueCreateInfos(queueCreateInfos.data())  
       .setEnabledExtensionCount(0)  
       .setEnabledLayerCount(0)
       .setPEnabledFeatures(&requiredFeatures);
 
   device = physicalDevice.createDeviceUnique(deviceCreateInfo);  
}
