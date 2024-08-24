//
// Created by kae on 18/08/24.
//

#pragma once

#include <bitset>
#include <memory>
#include <vector>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "util/random.hpp"

namespace ECS
{
  constexpr int kComponentLimit { 4 };
  constexpr int kEntityLimit { 5 };

  typedef std::bitset<kComponentLimit> ComponentMask;
  typedef unsigned long long EntityID;
  typedef unsigned int ComponentID;
  static inline EntityID s_EntityID { 0 };
  static inline unsigned int s_ComponentID { 0 };
}

namespace Lyonesse
{
  template<typename T>
  using Shared = std::shared_ptr<T>;

  template<typename T>
  using Unique = std::unique_ptr<T>;

  template<typename T>
  using Weak = std::weak_ptr<T>;

}