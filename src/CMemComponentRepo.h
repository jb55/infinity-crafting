#ifndef _CRAFTING_MEM_COMPONENT_REPOSITORY_H_
#define _CRAFTING_MEM_COMPONENT_REPOSITORY_H_
#pragma once

#include "CComponent.h"
#include "CComponentRepo.h"
#include <map>

CRAFTING_NAMESPACE

class CMemComponentRepo : public CComponentRepo
{
public:
    CMemComponentRepo();
    virtual ~CMemComponentRepo();

    typedef std::map<KeyT, CComponent> MapType;

    virtual KeyT  store(const CComponent &component);
    virtual bool update(KeyT id, const CComponent &component);
    virtual bool retrieve(KeyT id, CComponent &component);

private:
    static KeyT idValue;
    MapType m_map;
};

CRAFTING_NAMESPACE_END


#endif /* _CRAFTING_MEM_COMPONENT_REPOSITORY_H_ */
