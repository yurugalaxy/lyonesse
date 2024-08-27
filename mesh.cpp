#include "mesh.hpp"

#include <utility>

namespace Lyonesse
{
  Mesh::Mesh(std::vector<Vertex> inVertices, std::vector<unsigned int> inIndices, std::vector<Texture> inTextures)
    : verts(std::move(inVertices)), indices(std::move(inIndices)), textures(std::move(inTextures))
  {
  }

}