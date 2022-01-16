#include "pch.h"
#include "TestNbt.h"

#include <MC/CompoundTag.hpp>
void testRW(std::string const& binary, bool isLittle) {
    logger.info("size: {}, isLittleEndian: {}", binary.size(), isLittle);
    auto tag = CompoundTag::fromBinaryNBT((void*)binary.c_str(), binary.size(), isLittle);
    auto newBinary = tag->toBinaryNBT(isLittle);
    if (binary == newBinary) {
        logger.info("bin->tag->bin ����ͨ��");
    }
    else {
        logger.error("bin->tag->bin ����δͨ��");
    }
    auto snbt = tag->toSNBT();
    auto newTag = CompoundTag::fromSNBT(snbt);
    if (tag->equals(*newTag)) {
        logger.info("tag->snbt->tag ����ͨ��");
    }
    else {
        logger.error("tag->snbt->tag ����δͨ��");
        WriteAllFile(fmt::format("./test/error{}.nbt", isLittle ? "" : "_big"), newTag->toBinaryNBT(isLittle), true);
        return;
    }
    auto newSnbt = newTag->toSNBT();
    if (newSnbt == snbt) {
        //logger.info("snbt->tag->snbt ����ͨ��");
    }
    else {
        logger.error("snbt->tag->snbt ����δͨ��");
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