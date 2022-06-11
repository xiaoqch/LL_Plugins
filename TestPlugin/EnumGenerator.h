#pragma once
class EnumGenerator
{
public:
#ifdef ENABLE_TEST_ENUM
    static void gen();
#else
    static void gen(){};
#endif // ENABLE_TEST_ENUM
};

