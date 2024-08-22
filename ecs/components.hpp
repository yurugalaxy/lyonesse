//
// Created by kae on 21/08/24.
//

#pragma once

#include "../base.hpp"

namespace ECS
{
  struct Components
  {
    bool active {};
  };

  struct PositionComponent
  {
    glm::vec2 position {};
  };

  struct VelocityComponent
  {
    glm::vec2 velocityComponent {};
  };

  class ComponentPool
  {
  public:

  };
}