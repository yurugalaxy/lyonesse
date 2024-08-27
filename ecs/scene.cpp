#include "scene.hpp"

namespace ECS
{
  U16 Scene::GetID()
  {
    const U16 id = s_ComponentID++;
    return id;
  }

  U64 Scene::NewEntity()
  {
    return m_entities[s_EntityID].Init();
  }

  U64 Scene::Clone(const U64 index)
  {
    //TODO: also clone the components of the entity
    return m_entities[s_EntityID].Clone(m_entities[index]);
  }

  void Scene::DeleteEntity(const U64 entity)
  {
    for (int i = 0; i < pool.size(); ++i)
    {
      if (m_entities[entity].Mask().test(i))
      {
        pool[i].data[entity] = nullptr;
      }
    }
    m_entities[entity].Mask().reset();
  }

  void Scene::Remove(const U64 entity, const U16 componentID)
  {
    if (!m_entities[entity].Mask().test(componentID))
    {
      std::cout << "That component is not attached to this entity.\n";
    }

    pool[componentID].data[entity] = nullptr;
    m_entities[entity].Mask().reset(componentID);
  }
}
