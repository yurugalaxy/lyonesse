#include "input.hpp"
#include <iostream>

namespace Lyonesse
{
  void InputHandler::HandleInput(Window& window)
  {
   if (glfwGetKey(window.glWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
   {
     Window::SetActive(false);
   }
  }

  void InputHandler::OnMouseMove(GLFWwindow* win, const double xPos, const double yPos)
  {
    auto e = static_cast<InputHandler*>(glfwGetWindowUserPointer(win));
    // std::cout << "Mouse moved to x:" << xPos << " y:" << yPos << '\n';
  }

  void InputHandler::OnResize(GLFWwindow* win, const int width, const int height)
  {
    auto e = static_cast<InputHandler*>(glfwGetWindowUserPointer(win));
    glViewport(0, 0, width, height);
    // std::cout << "Window resized to: " << width << " x " << height << '\n';
  }
}
