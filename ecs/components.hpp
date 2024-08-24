//
// Created by kae on 21/08/24.
//

#pragma once

#include "../base.hpp"

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
}