#pragma once
/**
 * @brief Vengine, a C++17 Vulkan barebone engine.
 * The main header file to include to use the Vengine library,
 * @file vengine.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 01-07-2019
 */

#define VK_NO_STDINT_H // #include <stdint.h> is inside api.hpp
#include <vulkan/vulkan.h>
#include <vengine/api.hpp>

VkError vengine::vulkan::initialize (const char* appName, uint32_t appVersion)
{   using namespace vengine::vulkan;
    const VkApplicationInfo appInfo = 
    {
        VkStructureType::VK_STRUCTURE_TYPE_APPLICATION_INFO,
        nullptr,
        appName, appVersion,
        "Vengine", VK_MAKE_VERSION (1, 0, 0),
        VK_API_VERSION_1_0
    };
    const VkInstanceCreateInfo instancingInfo = 
    {
        VkStructureType::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        nullptr,
        VkFlags {},
        &appInfo,
        0, nullptr,
        0, nullptr
    };
    return vkCreateInstance (&instancingInfo, allocator, &instance);
}

void vengine::vulkan::destroy ()
{   using namespace vengine::vulkan;
    vkDestroyInstance (instance, allocator);
}

