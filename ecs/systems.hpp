//
// Created by kae on 21/08/24.
//

#pragma once

#include <iostream>

#include "scene.hpp"

namespace ECS
{
  void UpdatePositions(Scene& scene)
  {

  }

  void Init(Scene& scene)
  {
    for (int i = 0; i < kEntityLimit; ++i)
    {
      Entity currEnt = scene.GetEntity(i);
      if (currEnt.Mask().test(0) && currEnt.Mask().test(1))
      {
        scene.GetPool<TransformComponent>(0, 0)->position = { 0.0f, 0.0f, 0.0f};
      }
    }
  }
}