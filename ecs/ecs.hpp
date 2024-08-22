//
// Created by kae on 21/08/24.
//

#pragma once

#include "components.hpp"
#include "../base.hpp"
#include "entities.hpp"

namespace ECS
{
  class Scene
  {
  public:
    EntityID NewEntity()
    {
      return entities[s_IDGen].Init();
    }

    EntityID Clone(const EntityID entity)
    {
      return entities[s_IDGen].Init(entities[entity]);
    }

    void Delete(const EntityID entity)
    {
      entities[entity].m_active = false;
    }

    template<ComponentID T>
    void Assign(const EntityID entity)
    {
      entities[entity].m_componentMask |= 1 << T;
    }

    template<EntityType T>
    void Assign(const EntityID entity)
    {
      entities[entity].m_type = T;
    }

    template<ComponentID T>
    void Remove(const EntityID entity)
    {
     entities[entity].m_componentMask &= ~(1 << T);
    }

    std::array<Entity, kEntityLimit> entities;
  };
}
