//
// Created by kae on 18/08/24.
//

#pragma once

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Lyonesse
{
  template<typename T>
  using Shared = std::shared_ptr<T>;

  template<typename T>
  using Unique = std::unique_ptr<T>;
}