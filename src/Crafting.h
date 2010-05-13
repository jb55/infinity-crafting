#ifndef _CRAFTING_SYSTEM_H_
#define _CRAFTING_SYSTEM_H_
/**
 * The Flavien Brebion is a pretty cool dude license
 *
 * I hereby grant Flavien Brebion or his descendants to do whatever he wants 
 * with the following code. Credit would be pretty cool, but it's not required.
 *
 * Created by Bill Casarin (jb@jb55.com)
 */

/**
 * ------------------------------------------------------
 * Configuration START
 * ------------------------------------------------------
 **/

/**
 * Comment this out to disable all namespaces
 */

#define USE_CRAFTING_NAMESPACE

/**
 * Change the namespace name to anything you want
 */

#define CRAFTING_NAMESPACE_NAME Crafting

/** 
 * uncomment INTEGRATE_CRAFTING_SYSTEM and update namespace references to place 
 * it anywhere or don't and just leave it at the top level
 */

//#define INTEGRATE_CRAFTING_SYSTEM

#if defined(INTEGRATE_CRAFTING_SYSTEM) && defined(USE_CRAFTING_NAMESPACE)
# define CRAFTING_PARENT_NAMESPACE namespace INovae { namespace SomeNamespace {
# define CRAFTING_PARENT_NAMESPACE_END } }
#else
# define CRAFTING_PARENT_NAMESPACE
# define CRAFTING_PARENT_NAMESPACE_END
#endif

/**
 * ------------------------------------------------------
 * Configuration END
 * ------------------------------------------------------
 **/

#if defined(USE_CRAFTING_NAMESPACE)
# define CRAFTING_CHILD_NAMESPACE namespace CRAFTING_NAMESPACE_NAME { 
# define CRAFTING_CHILD_NAMESPACE_END } 
#else
# define CRAFTING_CHILD_NAMESPACE
# define CRAFTING_CHILD_NAMESPACE_END
#endif

#define CRAFTING_NAMESPACE \
    CRAFTING_PARENT_NAMESPACE CRAFTING_CHILD_NAMESPACE
#define CRAFTING_NAMESPACE_END \
    CRAFTING_CHILD_NAMESPACE_END CRAFTING_PARENT_NAMESPACE_END


CRAFTING_NAMESPACE

enum StatType
{
    kArmorThickness,            //< Armor thickness
    kHitpoints,                 //< Hitpoints
    kHullReflectiveness,        //< Hull reflectiveness to active sensors
    kMass,                      //< Mass
    kMaxInstalledEquipSize,     //< Max installed equipment size
    kCargoSpace,                //< Max item size in cargo
    kPowerGenerationRate,       //< Power generation rate
    kPowerGenerationFuelBurn,   //< Power generation fuel consumption per %
    kPowerStorageCapacity,      //< Power storage capacity
    kPowerStorageRechargeRate,  //< Power storage recharge rate
    kPowerStorageConvRatio,     //< Power storage conversion ratio
    kReactorEmission,           //< Reactor emission per %
    kNumStats                   //< Number of modifiers
};

/* Mask defining different component modifier types */
enum StatTypeFlags
{
    kArmorThicknessFlag           = 1 << kArmorThickness,
    kHitpointsFlag                = 1 << kHitpoints,
    kHullReflectivenessFlag       = 1 << kHullReflectiveness,
    kMassFlag                     = 1 << kMass,
    kMaxInstalledEquipSizeFlag    = 1 << kMaxInstalledEquipSize,
    kCargoSpaceFlag               = 1 << kCargoSpace,
    kPowerGenerationRateFlag      = 1 << kPowerGenerationRate,
    kPowerGenerationFuelBurnFlag  = 1 << kPowerGenerationFuelBurn,
    kPowerStorageCapacityFlag     = 1 << kPowerStorageCapacity,
    kPowerStorageRechargeRateFlag = 1 << kPowerStorageRechargeRate,
    kPowerStorageConvRatioFlag    = 1 << kPowerStorageConvRatio,
    kReactorEmissionFlag          = 1 << kReactorEmission
};

typedef unsigned long long uint64_t;

CRAFTING_NAMESPACE_END

#endif /* _CRAFTING_SYSTEM_H_ */
