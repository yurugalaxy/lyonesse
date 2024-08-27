//
// Created by kae on 18/08/24.
//

#pragma once

#include <bitset>
#include <memory>
#include <cassert>
#include <vector>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "util/random.hpp"

typedef uint16_t U16;
typedef int16_t I16;
typedef uint32_t U32;
typedef int32_t I32;
typedef uint64_t U64;
typedef int64_t I64;

namespace ECS
{
  constexpr int kComponentLimit { 4 };
  constexpr int kEntityLimit { 5 };
  typedef std::bitset<kComponentLimit> ComponentMask;
  static inline U64 s_EntityID { 0 };
  static inline U16 s_ComponentID { 0 };
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