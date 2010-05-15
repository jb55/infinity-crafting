#ifndef _CRAFT_ITEM_REPO_H_
#define _CRAFT_ITEM_REPO_H_
#pragma once

#include "CItem.h"

CRAFTING_NAMESPACE

class CItemRepository
{
public:
    CItemRepository() {};
    virtual ~CItemRepository() {};

    /**
     * The key type for item repositories, used for
     * uniquely identifying items
     */
    typedef uint64_t KeyT;

    virtual KeyT store(const CItem &item) = 0;
    virtual bool update(KeyT id, const CItem &item) = 0;
    virtual bool retrieve(KeyT id, CItem &item) = 0;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_ITEM_REPO_H_ */
