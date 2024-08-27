//
// Created by kae on 25/08/24.
//

#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "base.hpp"

#include "shader.hpp"

namespace Lyonesse
{
  struct Vertex
  {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
  };

  struct Texture
  {
    U32 id;
    std::string type;
  };

  class Mesh
  {
  public:
    std::vector<Vertex> verts;
    std::vector<U32> indices;
    std::vector<Texture> textures;

    Mesh(std::vector<Vertex> inVertices
        , std::vector<U32> inIndices
        , std::vector<Texture> inTextures);

    void Draw(Shader& shader);
  private:
    unsigned int VAO, VBO, EBO;

    void setupMesh();
  };
}
