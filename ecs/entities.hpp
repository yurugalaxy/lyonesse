//
// Created by kae on 21/08/24.
//

#pragma once

#include <iostream>

#include "../base.hpp"

namespace ECS
{
  struct Entity
  {
    EntityID Init()
    {
      m_entityID = s_IDGen++;
      m_active = true;
      return m_entityID;
    }

    EntityID Init(const Entity entity)
    {
      m_entityID = s_IDGen++;
      m_active = true;
      m_componentMask = entity.m_componentMask;
      m_type = entity.m_type;
      return m_entityID;
    }

    EntityID m_entityID {};
    ComponentMask m_componentMask {};
    bool m_active {};
    EntityType m_type {};
  };
}

