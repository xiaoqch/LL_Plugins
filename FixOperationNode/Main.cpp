#include "pch.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Level.hpp>
#include <PlayerInfoAPI.h>
#include <ScheduleAPI.h>
#include <I18nAPI.h>
#include <exception>

void entry()
{
}

TInstanceHook(class LevelChunk*, "?getChunk@BlockSource@@QEBAPEAVLevelChunk@@AEBVChunkPos@@@Z",
              BlockSource, ChunkPos const& cpos)
{
    static bool inited = ([]() { _set_se_translator(seh_exception::TranslateSEHtoCE); return true; })();
    try
    {
        return original(this, cpos);
    }
    catch (const seh_exception& e)
    {
        logger.error("SEH Exception detected!");
        logger.error("{}", TextEncoding::toUTF8(e.what()));
        logger.error("in BlockSource({})::getChunk({}, {})", (void*)this, cpos.x, cpos.z);
    }
    catch (const std::exception& e)
    {
        logger.error("Exception detected!");
        logger.error("{}", TextEncoding::toUTF8(e.what()));
        logger.error("in BlockSource({})::getChunk({}, {})", (void*)this, cpos.x, cpos.z);
    }
    catch (...)
    {
        logger.error("Exception detected!");
        logger.error("in BlockSource({})::getChunk({}, {})", (void*)this, cpos.x, cpos.z);
    }
    return nullptr;
}

