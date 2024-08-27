#include "window.hpp"

#include <cassert>
#include <iostream>
#include <sol/sol.hpp>

#include "input.hpp"

namespace Lyonesse
{
  Window::Window()
  {
    //Only 1 window allowed at a time
    assert(!s_active);
    s_active = true;

    // Get parameters from the config lua
    sol::state lua;
    lua.script_file("../scripts/config.lua");
    m_title = lua.get<sol::table>("Window").get<const char*>("title");
    m_width = lua["Window"]["resolution"]["width"];
    m_height = lua["Window"]["resolution"]["height"];
    m_aspectRatio = m_width / static_cast<float>(m_height);
    // ------------------------------------

    Initialise();
    m_windowPtr = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

    if (m_windowPtr == nullptr)
    {
      std::cout << "Unable to create window.\n";
      return;
    }

    glfwMakeContextCurrent(m_windowPtr);
    glfwSetWindowUserPointer(m_windowPtr, this);
    glfwSetFramebufferSizeCallback(m_windowPtr, InputHandler::OnResize);
    glfwSetCursorPosCallback(m_windowPtr, InputHandler::OnMouseMove);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      std::cout << "Unable to initialise GLAD.\n";
    }

    glViewport(0, 0, m_width, m_height);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glfwSwapInterval(1);

    std::cout << "Created window.\n";
  }

  Window::~Window()
  {
    s_active = false;
    glfwDestroyWindow(m_windowPtr);
    std::cout << "Destroyed window.\n";
    glfwTerminate();
  }

  void Window::Initialise()
  {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }
}
