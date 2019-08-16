// Code shorteners (never undef)
#ifndef RET_ERR
#define RET_ERR(fnCall) if (const VkError e = fnCall; e) return e
#endif

// Declaration shorteners
#define COMP_FN(type) bool (*comp)(const type, const type)
#define DEFINE_VK_HANDLE(name) struct name##_T; using name = name##_T*

// Namespace names shorteners
#define VE vengine
#define VE_AL vengine::algorithm
#define VE_HE vengine::helper
#define VE_VK vengine::vulkan

// Specifiers shorteners
#define INL inline
#define NX noexcept 
#define ND [[nodiscard]]