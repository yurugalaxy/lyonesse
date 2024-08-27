//
// Created by kae on 22/08/24.
//

#pragma once

#include "entities.hpp"
#include "components.hpp"
#include "../base.hpp"
#include "../renderer.hpp"

namespace ECS
{
  class Scene
  {
  public:
    static U16 GetID();
    U64 NewEntity();
    U64 Clone(U64 index);
    void DeleteEntity(U64 entity);
    Entity GetEntity(const U64 entity) { return m_entities[entity]; }
    void Remove(U64 entity, U16 componentID);

    template<typename T>
    T* GetPool(const U64 entity, const U16 componentID)
    {
        return dynamic_cast<T*>(pool[componentID].data[entity]);
    }

    template<typename T>
    T* Assign(const U64 entity, const U16 componentID)
  {
    if (pool.size() <= componentID)
    {
      pool.resize(componentID + 1);
      std::cout << "New component created at index: " << componentID << '\n';
    }

    if (pool[componentID].data[entity] == nullptr)
    {
      pool[componentID].data[entity] = new T;
      std::cout << "Existing component instantiated at index : " << componentID << '\n';
    }

    m_entities[entity].Mask().set(componentID);
    return dynamic_cast<T*>(pool[componentID].data[entity]);
  }

    void SetRenderer(Lyonesse::Renderer& renderer);

  private:
    Entity m_entities[kEntityLimit];
    std::vector<ComponentPool> pool;
  };
}
