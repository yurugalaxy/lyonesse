//
// Created by kae on 18/08/24.
//

#pragma once

#include <bitset>
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "util/random.hpp"

namespace ECS
{
  constexpr int kComponentLimit { 4 };
  constexpr int kEntityLimit { 10 };

  enum ComponentID
  {
    POSITION = 0,
    VELOCITY,
    SPRITE,
    MODEL
  };

  enum EntityType
  {
    PLAYER,
    ENEMY,
    TILE,
    PROP,
    DECORATION,
  };

  typedef std::bitset<kComponentLimit> ComponentMask;
  typedef unsigned long long EntityID;
  static inline EntityID s_IDGen { 0 };
}

namespace Lyonesse
{
  template<typename T>
  using Shared = std::shared_ptr<T>;

  template<typename T>
  using Unique = std::unique_ptr<T>;

}