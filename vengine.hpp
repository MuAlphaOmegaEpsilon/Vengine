#pragma once
/**
 * @brief A C++17 Vulkan barebone engine. 
 * @file vengine.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 01-07-2019
 */

#include <vulkan/vulkan.h>

using VkError = VkResult;

#define INL inline
#define ND [[nodiscard]]
#define C extern "C"
namespace vengine
{
    extern VkInstance vulkanInstance;
    extern VkPhysicalDevice vulkanPhysicalDevice;
    constexpr VkAllocationCallbacks* vulkanAllocator = nullptr;

    C ND inline VkError initializeVulkan (const char* appName, uint32_t appVersion);
    C inline void destroyVulkan ();
}
#undef C
#undef ND
#undef INL

VkError vengine::initializeVulkan (const char* appName, uint32_t appVersion)
{   using namespace vengine;
    const VkApplicationInfo vulkanAppInfo = 
    {
        VkStructureType::VK_STRUCTURE_TYPE_APPLICATION_INFO,
        nullptr,
        appName, appVersion,
        "Vengine", VK_MAKE_VERSION (1, 0, 0),
        VK_API_VERSION_1_0
    };
    const VkInstanceCreateInfo vulkanInstancingInfo = 
    {
        VkStructureType::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        nullptr,
        VkFlags {},
        &vulkanAppInfo,
        0, nullptr,
        0, nullptr
    };
    return vkCreateInstance (&vulkanInstancingInfo, vulkanAllocator, &vulkanInstance);
}

void vengine::destroyVulkan ()
{   using namespace vengine;
    vkDestroyInstance (vulkanInstance, vulkanAllocator);
}

