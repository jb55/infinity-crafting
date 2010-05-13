#ifndef _CRAFT_COMPONENT_REPO_H_
#define _CRAFT_COMPONENT_REPO_H_
#pragma once

CRAFTING_NAMESPACE

class CComponentRepository
{
public:
    CComponentRepository ();
    virtual ~CComponentRepository ();

    /**
     * The key type for component repositories, used for
     * uniquely identifying components
     */
    typedef uint64_t KeyT;

    virtual KeyT store(const CComponent &component) = 0;
    virtual bool update(KeyT id, const CComponent &component) = 0;
    virtual bool retrieve(KeyT id, CComponent &component) = 0;
};

CRAFTING_NAMESPACE_END

#endif /* _CRAFT_COMPONENT_REPO_H_ */
