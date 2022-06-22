#include "pch.h"
#include "AbilityHelperCommand.h"
#include <MC/Level.hpp>

using namespace RegisterCommandHelper;
#include <MC/ByteTag.hpp>
void AbilityHelperCommand::execute(class CommandOrigin const& origin, class CommandOutput& output) const
{
    auto players = mPlayer.results(origin);
    if (players.empty()) {
        return output.error("%commands.generic.noTargetMatch");
    }
    if (!mIndex_isSet)
    {
        auto& player = *players.begin();
        auto tag = player->getNbt();
        logger.warn(tag->toSNBT(4));
        tag->getCompound("abilities")->getByteTag("mine")->set(false);
        tag->getCompound("abilities")->getByteTag("mayfly")->set(true);
        tag->getCompound("abilities")->putByte("noclip", true);
        player->setNbt(tag.get());
        logger.warn(player->getNbt()->toSNBT(4));
        auto abilities = &dAccess<Abilities>(player, 2512);
        bool flying = abilities->getAbility(AbilitiesIndex::Flying).getBool();
        AdventureSettingsPacket pkt(Global<Level>->getAdventureSettings(), *abilities, player->getUniqueID(), false);
        pkt.mFlag &= ~static_cast<unsigned int>(AdventureFlag::Flying);
        if (flying)
            pkt.mFlag |= static_cast<unsigned int>(AdventureFlag::Flying);
        player->sendNetworkPacket(pkt);
        player->_sendDirtyActorData();
        return;
    }
    std::string names = "";
    if (!mIndex_isSet) {
        return output.success("optional abilities: build, mine, doorandswitches, opencontainers, attackplayers, attackmobs, teleport, invulnerable, flying, mayfly, instabuild, lightning, mute, noclip");
    }
    if (!mSwitch_isSet)
    {
        for (auto player : players)
        {
            output.success(fmt::format("{}: {} = {}", 
                player->getName(), magic_enum::enum_name(mIndex), AbilitiesHelper::getPlayerAbility(*player, mIndex)));
        }
        return;
    }
    for (auto player : players)
    {
        names += ", " + player->getName();
        AbilitiesHelper::setPlayerAbility(*player, mIndex, mSwitch);
    }
    if (names.empty())
    {
        output.error("%commands.generic.noTargetMatch");
    }
    else
    {
        names = names.substr(2);
        output.success(fmt::format("Success to set ability \"{}\" {} for {}", magic_enum::enum_name(mIndex), mSwitch, names));
    }
}

void AbilityHelperCommand::setup(CommandRegistry& registry)
{
    registry.registerCommand("abilityhelper", "Abilities Pro", CommandPermissionLevel::Any, {CommandFlagValue::None}, {(CommandFlagValue)0x80});
    if (!Config::commandAlias.empty()) {
        registry.registerAlias("abilityhelper", Config::commandAlias);
    }
    registry.addEnum<AbilitiesIndex>(
        "AbilityHelper",
        {
            {"build", AbilitiesIndex::Build},
            {"mine", AbilitiesIndex::Mine},
            {"doorandswitches", AbilitiesIndex::DoorAndSwitches},
            {"opencontainers", AbilitiesIndex::OpenContainers},
            {"attackplayers", AbilitiesIndex::AttackPlayers},
            {"attackmobs", AbilitiesIndex::AttackMobs},
            //{"op", AbilitiesIndex::Op},
            {"teleport", AbilitiesIndex::Teleport},
            {"invulnerable", AbilitiesIndex::Invulnerable},
            {"flying", AbilitiesIndex::Flying},
            {"mayfly", AbilitiesIndex::MayFly},
            {"instabuild", AbilitiesIndex::InstaBuild},
            {"lightning", AbilitiesIndex::Lightning},
            //{"FlySpeed", AbilitiesIndex::FlySpeed},
            //{"WalkSpeed", AbilitiesIndex::WalkSpeed},
            {"mute", AbilitiesIndex::Mute},
            //{"worldbuilder", AbilitiesIndex::WorldBuilder},
            {"noclip", AbilitiesIndex::NoClip},
        });

    auto playerParam = makeMandatory<AbilityHelperCommand>(&AbilityHelperCommand::mPlayer, "target");
    auto indexParam = makeMandatory<CommandParameterDataType::ENUM, AbilityHelperCommand>(&AbilityHelperCommand::mIndex, "ability", "AbilityHelper", &AbilityHelperCommand::mIndex_isSet);
    auto valueParam = makeMandatory<AbilityHelperCommand>(&AbilityHelperCommand::mSwitch, "value", &AbilityHelperCommand::mSwitch_isSet);
    auto indexOptional = makeOptional<CommandParameterDataType::ENUM, AbilityHelperCommand>(&AbilityHelperCommand::mIndex, "ability", "AbilityHelper", &AbilityHelperCommand::mIndex_isSet);

    registry.registerOverload<AbilityHelperCommand>("abilityhelper", playerParam, indexParam, valueParam);
    registry.registerOverload<AbilityHelperCommand>("abilityhelper", playerParam, indexOptional);
}
#include <DynamicCommandAPI.h>
#include <ScheduleAPI.h>
#include <MC/ServerPlayer.hpp>

void onNoClipExecute(DynamicCommand const& cmd, CommandOrigin const& origin, CommandOutput& output, std::unordered_map<std::string, DynamicCommand::Result>& results)
{
    auto player = origin.getPlayer();
    if (!player)
        return output.error("only for player");
    auto abilities = AbilitiesHelper::getAbilities(*player);
    auto flying = abilities->getBool(AbilitiesIndex::Flying);
    auto noclip = abilities->getBool(AbilitiesIndex::NoClip);
    if (!noclip && !flying)
        return output.error("need flying");
    AbilitiesHelper::setPlayerAbility(*player, AbilitiesIndex::NoClip, !noclip);
}
void onFlyExecute(DynamicCommand const& cmd, CommandOrigin const& origin, CommandOutput& output, std::unordered_map<std::string, DynamicCommand::Result>& results)
{
    auto player = origin.getPlayer();
    if (!player)
        return output.error("only for player");
    auto abilities = AbilitiesHelper::getAbilities(*player);
    auto mayFly = abilities->getBool(AbilitiesIndex::MayFly);
    AbilitiesHelper::setPlayerAbility(*player, AbilitiesIndex::MayFly, !mayFly);
}
inline void registerNoClipCommand()
{
    DynamicCommand::setup("noclip", "noclip", {}, {}, {{}}, onNoClipExecute);
    DynamicCommand::setup("canfly", "canfly", {}, {}, {{}}, onFlyExecute);
}

inline auto noclip = Schedule::nextTick(registerNoClipCommand);

