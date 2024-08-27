//
// Created by kae on 21/08/24.
//

#pragma once

#include "../base.hpp"

namespace ECS
{
  class Entity
  {
  public:
    U64 Init()
    {
      m_entityID = s_EntityID++;
      std::cout << "Created new entity: " << m_entityID << '\n';
      return m_entityID;
    }

    U64 Clone(const Entity entity)
    {
      m_entityID = s_EntityID++;
      m_componentMask = entity.m_componentMask;
      return m_entityID;
    }

    ComponentMask Mask() { return m_componentMask; }

  private:
    U64 m_entityID {};
    ComponentMask m_componentMask {};
  };
}

