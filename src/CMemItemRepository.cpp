#include "CMemItemRepository.h"

CRAFTING_NAMESPACE

CItemRepository::KeyT CMemItemRepository::idValue = 0;

bool CMemItemRepository::update(KeyT id, const CItem &item) 
{
    m_map[id] = item;
    return true;
}

bool CMemItemRepository::retrieve(KeyT id, CItem &item) 
{
    MapType::iterator mapIter = m_map.find(id);
    if (mapIter == m_map.end())
        return false;

    item = CItem(mapIter->second);
    return true;
}

CMemItemRepository::KeyT CMemItemRepository::store(const CItem &item) 
{
    idValue += 1;
    m_map[idValue] = item;
    return idValue;
}

CRAFTING_NAMESPACE_END
