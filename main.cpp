//Engine stuff
#include <iostream>

#include "base.hpp"
#include "window.hpp"
#include "input.hpp"
#include "shader.hpp"

//Imgui

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "mesh.hpp"
#include "renderer_2D.hpp"
#include "ecs/ecs.hpp"

int main()
{
  Lyonesse::Window window;

  ECS::Scene scene;

  Lyonesse::Quad quaddy;

  Lyonesse::Shader shader("../assets/shaders/basic.vert", "../assets/shaders/basic.frag");
  shader.Use();

  Lyonesse::Renderer2D rendy(quaddy);

  rendy.Init();

  while (Lyonesse::Window::Active())
  {
    Lyonesse::InputHandler::HandleInput(window);

    glClearColor(0.1f, 0.135f, 0.145f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    rendy.Render();

    glfwSwapBuffers(window.glWindow());
    glfwPollEvents();
  }
}
