//
// Created by kae on 21/08/24.
//

#pragma once

#include "../base.hpp"
#include "../mesh.hpp"
#include "../renderer.hpp"

namespace ECS
{
  struct Component
  {
    virtual ~Component() = default;
  };

  struct ComponentPool
  {
    Component* data[kEntityLimit] {nullptr};
  };

  struct TransformComponent : Component
  {
    glm::vec3 position {};
  };

  struct VelocityComponent : Component
  {
    glm::vec3 velocity {};
  };

  struct SpriteComponent : Component
  {
    Lyonesse::Texture texture {};
    Lyonesse::Shader shader;
    Lyonesse::Renderer& renderer;
  };
}
