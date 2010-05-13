#include "CMemComponentRepo.h"

CRAFTING_NAMESPACE

CComponentRepo::KeyT CMemComponentRepo::idValue = 0;

bool CMemComponentRepo::update(KeyT id, const CComponent &component) 
{
    m_map[id] = component;
    return true;
}

bool CMemComponentRepo::retrieve(KeyT id, CComponent &component) 
{
    MapType::iterator mapIter = m_map.find(id);
    if (mapIter == m_map.end())
        return false;

    component = CComponent(mapIter->second);
    return true;
}

CMemComponentRepo::KeyT CMemComponentRepo::store(const CComponent &component) 
{
    idValue += 1;
    m_map[idValue] = component;
    return idValue;
}

CRAFTING_NAMESPACE_END
