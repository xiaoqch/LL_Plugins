﻿#include "pch.h"
#include "TestNbt.h"
#ifdef ENABLE_TEST_NBT

#include <MC/CompoundTag.hpp>
void testRW(std::string const& binary, bool isLittle) {
    logger.info("size: {}, isLittleEndian: {}", binary.size(), isLittle);
    auto tag = CompoundTag::fromBinaryNBT((void*)binary.c_str(), binary.size(), isLittle);
    auto newBinary = tag->toBinaryNBT(isLittle);
    if (binary == newBinary) {
        logger.info("bin->tag->bin 测试通过");
    }
    else {
        logger.error("bin->tag->bin 测试未通过");
    }
    std::string snbt = tag->toSNBT(4);
    auto newTag = CompoundTag::fromSNBT(snbt);
    if (tag->equals(*newTag)) {
        logger.info("tag->snbt->tag 测试通过");
    }
    else
    {
        auto newSnbt = newTag->toSNBT();
        std::cout << newSnbt << std::endl;
        logger.error("tag->snbt->tag 测试未通过");
        WriteAllFile(fmt::format("./test/error{}.nbt", isLittle ? "" : "_big"), newTag->toBinaryNBT(isLittle), true);
        return;
    }
    auto newSnbt = newTag->toSNBT(4);
    if (newSnbt == snbt) {
        //logger.info("snbt->tag->snbt 测试通过");
    }
    else {
        logger.error("snbt->tag->snbt 测试未通过");
        WriteAllFile(fmt::format("./test/error{}.nbt", isLittle ? "" : "_big"), newTag->toBinaryNBT(isLittle), true);
        return;
    }

}
void testNbt() {
    auto filePath = "./test/test.nbt";
    auto binary = ReadAllFile(filePath, true);
    logger.info("Testing file:  {}", filePath);
    testRW(binary.value(), true);

    filePath = "./test/test_big.nbt";
    binary = ReadAllFile(filePath, true);
    logger.info("Testing file:  {}", filePath);
    testRW(binary.value(), false);

    filePath = "./test/test_longarray.nbt";
    binary = ReadAllFile(filePath, true);
    logger.info("Testing file:  {}", filePath);
    testRW(binary.value(), true);
}
void TestNbt::test() {
    testNbt();
}
#else
void TestNbt::test()
{
}

#endif // ENABLE_TEST_NBT