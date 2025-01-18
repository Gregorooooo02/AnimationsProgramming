#pragma once
#include <string>
/* include Vulkan header BEFORE GLFW */
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

class Window {
public:
    /* Functions */
    bool init(unsigned int width, unsigned int height, std::string title);
    bool initVulkan();
    void mainLoop();
    void cleanup();

private:
    /* Variables */
    GLFWwindow *mWindow = nullptr;
    std::string mApplicationName;

    VkInstance mInstance{};
    VkSurfaceKHR mSurface{};

    /* Functions */
    void handleWindowCloseEvents();
    void handleKeyEvents(int key, int scancode, int action, int mods);
    void handleMouseButtonEvents(int button, int action, int mods);
};