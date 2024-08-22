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
#include "ecs/ecs.hpp"

int main()
{
  Lyonesse::Window window(100, 100, "awoo");

  ECS::Scene oofScene;

  ECS::EntityID wawa = oofScene.NewEntity();
  ECS::EntityID oops = oofScene.NewEntity();


  oofScene.Assign<ECS::POSITION>(wawa);
  oofScene.Assign<ECS::SPRITE>(wawa);
  oofScene.Assign<ECS::POSITION>(oops);
  oofScene.Assign<ECS::VELOCITY>(oops);

  oofScene.Remove<ECS::VELOCITY>(oops);

  oofScene.Assign<ECS::ENEMY>(oops);

  ECS::EntityID cloney = oofScene.Clone(oops);

  for (auto& e : oofScene.entities)
  {
    if (e.m_active == true)
    {
      std::cout << e.m_type << ' ' << e.m_entityID << " at: " << &e
                << ", active: " << std::boolalpha << e.m_active
                << ", bitset: " << e.m_componentMask << '\n';
    }
  }

  while (Lyonesse::Window::Active())
  {
    Lyonesse::InputHandler::HandleInput(window);

    glClearColor(0.1f, 0.135f, 0.145f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(window.glWindow());
    glfwPollEvents();
  }
}
