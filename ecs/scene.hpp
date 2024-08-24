//
// Created by kae on 22/08/24.
//

#pragma once

#include "entities.hpp"
#include "components.hpp"
#include "../base.hpp"

namespace ECS
{
  class Scene
  {
  public:
    static ComponentID GetID()
    {
      const ComponentID id = s_ComponentID++;
      return id;
    }

    EntityID NewEntity()
    {
      return m_entities[s_EntityID].Init();
    }

    EntityID Clone(const EntityID index)
    {
      return m_entities[s_EntityID].Clone(m_entities[index]);
    }

    void DeleteEntity(const EntityID index)
    {
      m_entities[index].m_componentMask.reset();
    }

    template<typename T>
    T* Assign(const EntityID entity, const ComponentID componentID)
    {
      if (pool.size() <= componentID)
      {
        pool.resize(componentID + 1);
        std::cout << "New component created at index: " << componentID << '\n';
      }

      if (pool[componentID].data[entity] == nullptr)
      {
        pool[componentID].data[entity] = new T;
        std::cout << "Component instantiated at index : " << componentID << '\n';
      }

      m_entities[entity].m_componentMask.set(componentID);
      return dynamic_cast<T*>(pool[componentID].data[entity]);
    }

    template<typename T>
    void Remove(const EntityID entity, const ComponentID componentID)
    {
      m_entities[entity].m_componentMask.reset(componentID);
    }

    Entity Ent(const EntityID i) { return m_entities[i]; }

  // private:
    Entity m_entities[kEntityLimit];
    std::vector<ComponentPool> pool;
  };
}
