#include "pch.h"
#include "OperationAgentCommand.h"
#include "AgentManager.h"
#include <MC/CommandUtils.hpp>

#define KEY_NO_TARGET "%commands.generic.noTargetMatch"
#define KEY_TOO_MANY_TARGER "%commands.generic.tooManyTargets"

#define AssertUniqueTarger(results) \
if (results.empty())\
    return output.error(KEY_NO_TARGET);\
else if(results.count()>1)\
    return output.error(KEY_TOO_MANY_TARGER);

using namespace RegisterCommandHelper;

void OperationAgentCommand::execute(class CommandOrigin const& origin, class CommandOutput& output) const {
    auto& manager = AgentManager::getManager();
    switch (mOperation)
    {
    case OperationAgentCommand::Operation::Set: {
        Actor* master;
        Actor* agent;
        auto masterRes = mMaster.results(origin);
        AssertUniqueTarger(masterRes);
        master = *masterRes.begin();
        if (mAgent_isSet) {
            auto agentRes = mAgent.results(origin);
            AssertUniqueTarger(agentRes);
            agent = *agentRes.begin();
        }
        else {
            agent = origin.getEntity();
            if (!agent)
                return output.error(KEY_NO_TARGET);
        }
        if (manager.setAgent(agent, master)) {
            output.success("代理设置成功");
        }
        else {
            output.error("未知错误");
        }
        break;
    }
    case OperationAgentCommand::Operation::Clear:
        if (mAgent_isSet) {
            int count = 0;
            auto res = mAgent.results(origin);
            for (auto actor : res) {
                count += manager.removeAgent(actor);
            }
            switch (count) {
            case 0:
                output.error(KEY_NO_TARGET);
                break;
            case 1:
                output.success("清除了 " + (*res.begin())->getNameTag() + " 的代理");
                break;
            default:
                output.success("清除了 " + std::to_string(count) + " 个代理");
                break;
            }
        }
        else { // 没有输入实体，默认为执行指令的实体
            Actor* entity = origin.getEntity();
            if (!entity) {
                output.error(KEY_NO_TARGET);
            }
            else if (manager.removeAgent(entity)) {
                output.success("清除了 " + entity->getNameTag() + " 的代理");
            }
            else {
                output.error("清除代理失败");
            }
        }
        break;
    case OperationAgentCommand::Operation::Query: {
        Actor* agent = nullptr;
        if (mAgent_isSet) {
            auto results = mAgent.results(origin);
            AssertUniqueTarger(results);
            agent = *results.begin();
        }
        else {
            agent = origin.getEntity();
            if (!agent)
                return output.error(KEY_NO_TARGET);
        }
        auto master = AgentManager::tryGetMaster(agent);
        if (!master) {
            output.error(getActorDescription(agent) + " 没有设置任何代理");
        }
        else {
            output.success(getActorDescription(agent) + " -> " + getActorDescription(master));
        }
        break;
    }
    case OperationAgentCommand::Operation::Help:
        output.success(origin.getEntity() ? HELP_TEXT_FOR_PLAYER : HELP_TEXT);
        break;
    case OperationAgentCommand::Operation::List:
        output.success("代理列表(Agent->Master): ");
        manager.forEach([&origin, &output](Actor* agent, Actor* master)->void {
        std::string strAgent = getActorDescription(agent);
        std::string strMaster = getActorDescription(master);
        output.success(strAgent + " -> " + strMaster);
            });
        break;
    case OperationAgentCommand::Operation::ClearAll:
        if (auto count = manager.clearAll())
            output.success("已清除所有代理设置，共 " + std::to_string(count) + " 个");
        else
            output.error("当前没有已设置代理");
        break;
    case OperationAgentCommand::Operation::Version:
        output.success(PLUGIN_VERSION_STRING);
        break;
    case OperationAgentCommand::Operation::Reload:
        if (Config::initConfig()) {
            output.success("配置文件重载完成");
        }
        else {
            output.success("配置文件重载失败");
        }
        break;
    default:
        break;
    }
}

void OperationAgentCommand::setup(CommandRegistry& registry) {
    registry.registerCommand("opagent", "Operation Agent", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
    registry.addEnum<Operation>("SetAction", {
        {"set", Operation::Set},
        });
    registry.addEnum<Operation>("ActionWithMaster", {
        {"clear", Operation::Clear},
        {"query", Operation::Query},
        });
    registry.addEnum<Operation>("Action", {
        {"help", Operation::Help},
        {"list", Operation::List},
        {"clearall", Operation::ClearAll},
        {"version", Operation::Version},
        {"reload", Operation::Reload},
        });
    auto actionSet = makeMandatory<CommandParameterDataType::ENUM>(&OperationAgentCommand::mOperation, "action", "SetAction");
    auto actionWithMaster = makeMandatory<CommandParameterDataType::ENUM>(&OperationAgentCommand::mOperation, "action", "ActionWithMaster");
    auto action = makeMandatory<CommandParameterDataType::ENUM>(&OperationAgentCommand::mOperation, "action", "Action");
    actionSet.addOptions((CommandParameterOption)1);
    actionWithMaster.addOptions((CommandParameterOption)1);
    action.addOptions((CommandParameterOption)1);

    auto masterParam = makeMandatory(&OperationAgentCommand::mMaster, "master");
    auto agentParam = makeOptional(&OperationAgentCommand::mAgent, "agent", &OperationAgentCommand::mAgent_isSet);
    registry.registerOverload<OperationAgentCommand>("opagent", actionSet, masterParam, agentParam);
    registry.registerOverload<OperationAgentCommand>("opagent", actionWithMaster, agentParam);
    registry.registerOverload<OperationAgentCommand>("opagent", action);
}
