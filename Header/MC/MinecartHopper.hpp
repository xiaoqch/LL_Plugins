// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Actor.hpp"
#include "Minecart.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class MinecartHopper : public Minecart {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MINECARTHOPPER
public:
    class MinecartHopper& operator=(class MinecartHopper const&) = delete;
    MinecartHopper(class MinecartHopper const&) = delete;
    MinecartHopper() = delete;
#endif

public:
    /*0*/ virtual ~MinecartHopper();
    /*1*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*2*/ virtual void __unk_vfn_0();
    /*3*/ virtual float getInterpolatedHeadRot(float) const;
    /*4*/ virtual class Vec3 getInterpolatedRidingOffset(float) const;
    /*5*/ virtual void __unk_vfn_1();
    /*6*/ virtual float getRidingHeight();
    /*7*/ virtual void __unk_vfn_2();
    /*8*/ virtual void __unk_vfn_3();
    /*9*/ virtual float getCameraOffset() const;
    /*10*/ virtual float getShadowHeightOffs();
    /*11*/ virtual float getShadowRadius() const;
    /*12*/ virtual void __unk_vfn_4();
    /*13*/ virtual void __unk_vfn_5();
    /*14*/ virtual void playerTouch(class Player&);
    /*15*/ virtual bool isPickable();
    /*16*/ virtual void __unk_vfn_6();
    /*17*/ virtual bool isSleeping() const;
    /*18*/ virtual void setSleeping(bool);
    /*19*/ virtual void __unk_vfn_7();
    /*20*/ virtual bool isBlocking() const;
    /*21*/ virtual bool isDamageBlocked(class ActorDamageSource const&) const;
    /*22*/ virtual void __unk_vfn_8();
    /*23*/ virtual bool isSurfaceMob() const;
    /*24*/ virtual void __unk_vfn_9();
    /*25*/ virtual void __unk_vfn_10();
    /*26*/ virtual void __unk_vfn_11();
    /*27*/ virtual class Actor* findAttackTarget();
    /*28*/ virtual bool isValidTarget(class Actor*) const;
    /*29*/ virtual void adjustDamageAmount(int&) const;
    /*30*/ virtual void onTame();
    /*31*/ virtual void onFailedTame();
    /*32*/ virtual bool isJumping() const;
    /*33*/ virtual void vehicleLanded(class Vec3 const&, class Vec3 const&);
    /*34*/ virtual bool isInvulnerableTo(class ActorDamageSource const&) const;
    /*35*/ virtual void animateHurt();
    /*36*/ virtual float getPickRadius();
    /*37*/ virtual void awardKillScore(class Actor&, int);
    /*38*/ virtual int /*enum enum ArmorMaterialType*/ getArmorMaterialTypeInSlot(int /*enum enum ArmorSlot*/) const;
    /*39*/ virtual int /*enum enum ArmorTextureType*/ getArmorMaterialTextureTypeInSlot(int /*enum enum ArmorSlot*/) const;
    /*40*/ virtual float getArmorColorInSlot(int /*enum enum ArmorSlot*/, int) const;
    /*41*/ virtual void setEquippedSlot(int /*enum enum EquipmentSlot*/, class ItemStack const&);
    /*42*/ virtual class HashedString const& queryEntityRenderer() const;
    /*43*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*44*/ virtual bool canFreeze() const;
    /*45*/ virtual int getPortalWaitTime() const;
    /*46*/ virtual bool canChangeDimensions() const;
    /*47*/ virtual void __unk_vfn_12();
    /*48*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*49*/ virtual bool canPickupItem(class ItemStack const&) const;
    /*50*/ virtual bool canBePulledIntoVehicle() const;
    /*51*/ virtual bool inCaravan() const;
    /*52*/ virtual void __unk_vfn_13();
    /*53*/ virtual bool canSynchronizeNewEntity() const;
    /*54*/ virtual void buildDebugInfo(std::string&) const;
    /*55*/ virtual int getDeathTime() const;
    /*56*/ virtual void swing();
    /*57*/ virtual void __unk_vfn_14();
    /*58*/ virtual void __unk_vfn_15();
    /*59*/ virtual float getYHeadRot() const;
    /*60*/ virtual bool isWorldBuilder() const;
    /*61*/ virtual void __unk_vfn_16();
    /*62*/ virtual bool isAdventure() const;
    /*63*/ virtual bool canDestroyBlock(class Block const&) const;
    /*64*/ virtual void setAuxValue(int);
    /*65*/ virtual void stopSpinAttack();
    /*66*/ virtual void __unk_vfn_17();
    /*67*/ virtual void __unk_vfn_18();
    /*68*/ virtual void updateEntitySpecificMolangVariables(class RenderParams&);
    /*69*/ virtual void __unk_vfn_19();
    /*70*/ virtual void __unk_vfn_20();
    /*71*/ virtual void __unk_vfn_21();
    /*72*/ virtual void destroy(class ActorDamageSource const&, bool);
    /*73*/ virtual int /*enum enum MinecartType*/ getType();
    /*74*/ virtual class Block const* getDefaultDisplayBlock() const;
    /*75*/ virtual void __unk_vfn_22();
    /*76*/ virtual int getDefaultDisplayOffset() const;
    /*77*/ virtual void applyNaturalSlowdown(class BlockSource&);
    /*
    inline void applyNaturalSlowdown(class BlockSource& a0){
        void (MinecartHopper::*rv)(class BlockSource&);
        *((void**)&rv) = dlsym("?applyNaturalSlowdown@MinecartHopper@@UEAAXAEAVBlockSource@@@Z");
        return (this->*rv)(std::forward<class BlockSource&>(a0));
    }
    */
    MCAPI MinecartHopper(class ActorDefinitionGroup*, struct ActorDefinitionIdentifier const&, class OwnerPtrT<struct EntityRefTraits> const&);

protected:

private:

};