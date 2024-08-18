#include "window.hpp"

#include <cassert>
#include <iostream>

#include "input.hpp"

namespace Lyonesse
{
  Window::Window(const float width, const float height, const char* title)
    : m_title(title)
    , m_width(width)
    , m_height(height)
    , m_aspectRatio(width / height)
  {
    assert(!s_active);
    s_active = true;

    Initialise();

    m_windowPtr = glfwCreateWindow(m_width, m_height, title, nullptr, nullptr);

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
