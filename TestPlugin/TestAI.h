#pragma once
#include <MC/SimulatedPlayer.hpp>
namespace AiTest
{
#ifdef ENABLE_TEST_AI
    inline void testLookAtGoal(SimulatedPlayer* sp) {
        //sp->aiStep();
        //sp->createAI();
        //sp->createAIGoals();
        //sp->updateAi();
        //sp->_aiStep(*sp->getMovementProxy().get());
        //sp->_serverAiMobStep();
    }
    void setupCommand(CommandRegistry& registry);
#else
void setupCommand(CommandRegistry& registry){};
#endif // ENABLE_TEST_AI

};

