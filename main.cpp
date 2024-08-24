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

  ECS::Scene sceneGame;

  const ECS::EntityID player = sceneGame.NewEntity();
  const ECS::EntityID enemy = sceneGame.NewEntity();
  const ECS::ComponentID transformID = ECS::Scene::GetID();
  const ECS::ComponentID velocityID = ECS::Scene::GetID();

  sceneGame.Assign<ECS::TransformComponent>(player, transformID)->position = {6.1f, 8.2f, 3.8f};
  sceneGame.Assign<ECS::VelocityComponent>(enemy, velocityID)->velocity = {8.7f, 1.0f, 1.9f};
  sceneGame.Assign<ECS::TransformComponent>(enemy, transformID)->position = {2.2f, 1.1f, 2.2f};

  std::cout << "Player active components: " << sceneGame.Ent(player).Mask() << '\n';
  std::cout << "Enemy active components: " << sceneGame.Ent(enemy).Mask() << '\n';

  while (Lyonesse::Window::Active())
  {
    Lyonesse::InputHandler::HandleInput(window);

    glClearColor(0.1f, 0.135f, 0.145f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(window.glWindow());
    glfwPollEvents();
  }
}
