#ifndef _CRAFTING_MEM_ITEM_REPOSITORY_H_
#define _CRAFTING_MEM_ITEM_REPOSITORY_H_
#pragma once

#include "CItemRepository.h"
#include <map>

CRAFTING_NAMESPACE

class CMemItemRepository : public CItemRepository
{
public:
    CMemItemRepository();
    virtual ~CMemItemRepository();

    typedef std::map<KeyT, CItem> MapType;

    virtual KeyT  store(const CItem &item);
    virtual bool update(KeyT id, const CItem &item);
    virtual bool retrieve(KeyT id, CItem &item);

private:
    static KeyT idValue;
    MapType m_map;
};

CRAFTING_NAMESPACE_END


#endif /* _CRAFTING_MEM_ITEM_REPOSITORY_H_ */
