#include "pch.h"
#ifdef ENABLE_TEST_COMMAND_REG
#include "TestCommandReg.h"
#include <RegCommandAPI.h>
#include <MC/Command.hpp>
#include <MC/CommandUtils.hpp>
namespace DynamicCommandHelper
{

} // namespace DynamicCommandHelper

using namespace DynamicCommandHelper;
//template <>
//struct std::default_delete<DynamicCommand>
//{
//    constexpr default_delete() noexcept = default;
//
//    template <class _Ty2, enable_if_t<is_convertible_v<_Ty2*, DynamicCommand*>, int> = 0>
//    default_delete(const default_delete<_Ty2>&) noexcept
//    {
//    }
//
//    void operator()(DynamicCommand* _Ptr) const noexcept /* strengthened */
//    {                                         // delete a pointer
//        static_assert(0 < sizeof(DynamicCommand), "can't delete an incomplete type");
//        if (dynamicCommandDatas.count(_Ptr->commandName)) {
//
//            size_t size = getDynamicCommandSize(dynamicCommandDatas.at(_Ptr->commandName).parameters);
//            _Ptr->~DynamicCommand();
//            delete[size](char*) _Ptr;
//        }
//        else
//        {
//            delete _Ptr;
//        }
//    }
//};


#include <MC/DataItem.hpp>
#include <MC/Player.hpp>
void TestCommandReg::test()
{
    ParameterData data(ParameterType::Actor, "actor", true);
    ParameterData data2(ParameterType::Bool, "bool", true);
    DynamicCommand::setup("test", "test", {data, data2},
                          [](CommandOrigin const& origin, CommandOutput& output, std::vector<ParameterResult> results) {
                              if (results[0].isSet)
                              {
                                  output.success("Actor is set");
                                  CommandSelector<Actor> const& result = results[0].get<CommandSelector<Actor>>();
                                  for (auto actor : result.results(origin))
                                  {
                                      output.success(fmt::format("Actor: {}", CommandUtils::getActorName(*actor)));
                                  }
                              }
                              else
                              {
                                  output.success("Actor not set");
                              }
                          });
}
#endif