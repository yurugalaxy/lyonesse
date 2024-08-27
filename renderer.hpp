//
// Created by kae on 26/08/24.
//

#pragma once

namespace Lyonesse
{
  class Renderer
  {
  public:
    virtual ~Renderer() = default;
    virtual void Init() = 0;
    virtual void Render() = 0;
  };
}