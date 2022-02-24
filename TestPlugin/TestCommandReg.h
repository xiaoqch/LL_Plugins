#pragma once
namespace TestCommandReg
{
#ifdef ENABLE_TEST_COMMAND_REG
void test();
#else
inline void test(){};
#endif
}; // namespace TestCommandReg
