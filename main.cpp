//Engine stuff
#include "base.hpp"
#include "window.hpp"
#include "input.hpp"

//Imgui
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

int main()
{
  Lyonesse::Window window(1920, 1080, "awoo");

  while (Lyonesse::Window::Active())
  {
    Lyonesse::InputHandler::HandleInput(window);

    glClearColor(0.5f, 0.5f, 0.2f, 1.0f);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(window.glWindow());
    glfwPollEvents();
  }
}