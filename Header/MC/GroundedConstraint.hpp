// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class GroundedConstraint {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GROUNDEDCONSTRAINT
public:
    class GroundedConstraint& operator=(class GroundedConstraint const&) = delete;
    GroundedConstraint(class GroundedConstraint const&) = delete;
    GroundedConstraint() = delete;
#endif

public:
    /*0*/ virtual ~GroundedConstraint();
    /*1*/ virtual bool isSatisfied(class IBlockWorldGenAPI const&, class BlockPos const&, int /*enum enum Rotation*/ const&) const;
    MCAPI GroundedConstraint(class StructureTemplate&);

protected:

private:

};