//
// Created by kae on 26/08/24.
//

#pragma once
#include "base.hpp"
#include "renderer.hpp"

namespace Lyonesse
{
  struct Quad
  {
    float vertices[8] = {
      0.0f, 1.0f,
      1.0f, 0.0f,
      0.0f, 0.0f,
      1.0f, 1.0f
    };

    int indices[6] = {
      0, 1, 2, 0, 1, 3
    };

    float texCoords[8] = {
      0.0f, 1.0f,
      1.0f, 0.0f,
      0.0f, 0.0f,
      1.0f, 1.0f,
    };
  };

  class Renderer2D
  {
  public:
    explicit Renderer2D(Quad& inQuad)
      : quad(inQuad)
    {}
    void Init() ;
    void Render() ;

  private:
    U32 VAO{};
    U32 VBO{};
    U32 EBO{};
    Quad& quad;
  };
}
