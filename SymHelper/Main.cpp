#include "pch.h"
#include <mc/OffsetHelper.h>
#include "BlockType.h"
#include "EnumGen.h"
#include <api/scheduler/scheduler.h>

//Recipes::_loadHardcodedRecipes


void entry() {
    Event::addEventListener([](ServerStartedEV ev) {
        auto task = DelayedTask([]()->void {
            genEnum();
            }, 10);
        auto taskId = Handler::schedule(std::move(task));
        });
}