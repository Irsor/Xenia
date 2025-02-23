#include <vulkan/vulkan.hpp>
#include <fmt/core.h>
#include <memory>
#include <array>

namespace xe
{
    class RenderCore
    {
    public:
        RenderCore();
        ~RenderCore();

        void CreateInstance();

    private:
        void InitVulkan();

        VkInstance instance;
    };
}