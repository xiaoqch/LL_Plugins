// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class DBStoragePerformanceData {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_DBSTORAGEPERFORMANCEDATA
public:
    class DBStoragePerformanceData& operator=(class DBStoragePerformanceData const&) = delete;
    DBStoragePerformanceData(class DBStoragePerformanceData const&) = delete;
    DBStoragePerformanceData() = delete;
#endif

public:
    MCAPI void resetAll();
    MCAPI static class std::array<char const* , 11> CATEGORY_NAMES;
    MCAPI static class std::array<char const* , 4> OPERATION_NAMES;

protected:

private:

};