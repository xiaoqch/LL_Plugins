#include "pch.h"
#include "TestNbt.h"
#ifdef ENABLE_TEST_NBT

#include <MC/CompoundTag.hpp>
#include <MC/PrettySnbtFormat.hpp>
#include <MC/ColorFormat.hpp>

inline void toFormatted(CompoundTag& tag, int indent, SnbtFormat snbtFormat)
{
    tag.toSNBT(indent, snbtFormat);
}
inline std::string toPrettySNBT(CompoundTag& tag, bool forPlayer)
{
    PrettySnbtFormat format = PrettySnbtFormat::getDefaultFormat(forPlayer);
    format.setValueColor<Tag::Type::Short>(ColorFormat::colorCodeToColorMap.at("§7"));
    return tag.toPrettySNBT(format);
}
void testRW(std::string const& binary, bool isLittle)
{
    logger.info("size: {}, isLittleEndian: {}", binary.size(), isLittle);
    auto tag = CompoundTag::fromBinaryNBT((void*)binary.c_str(), binary.size(), isLittle);
    TestFuncTime(tag->toSNBT);
    TestFuncTime(toFormatted, *tag, 4, SnbtFormat::Minimize);
    TestFuncTime(toPrettySNBT, *tag, true);
    TestFuncTime(tag->toSNBT);
    TestFuncTime(toFormatted, *tag, 4, SnbtFormat::PartialNewLine);
    TestFuncTime(toPrettySNBT, *tag, true);
    TestFuncTime(tag->toSNBT);
    TestFuncTime(toFormatted, *tag, 4, SnbtFormat::PartialNewLine);
    TestFuncTime(toPrettySNBT, *tag, true);
    logger.info(tag->toPrettySNBT(false));
    logger.info(tag->toPrettySNBT(true));
    return;
    auto newBinary = tag->toBinaryNBT(isLittle);
    if (binary == newBinary) {
        logger.info("bin->tag->bin 测试通过");
    }
    else {
        logger.error("bin->tag->bin 测试未通过");
    }
    std::string snbt = tag->toSNBT(4, SnbtFormat::Minimize);
    auto newTag = CompoundTag::fromSNBT(snbt);
    if (tag->equals(*newTag)) {
        logger.info("tag->snbt->tag 测试通过");
    }
    else
    {
        auto newSnbt = newTag->toSNBT();
        //std::cout << newSnbt << std::endl;
        logger.error("tag->snbt->tag 测试未通过");
        WriteAllFile(fmt::format("./test/error{}.nbt", isLittle ? "" : "_big"), newTag->toBinaryNBT(isLittle), true);
        return;
    }
    auto newSnbt = newTag->toSNBT(4, SnbtFormat::Minimize);
    if (newSnbt == snbt) {
        //logger.info("snbt->tag->snbt 测试通过");
    }
    else {
        logger.error("snbt->tag->snbt 测试未通过");
        WriteAllFile(fmt::format("./test/error{}.nbt", isLittle ? "" : "_big"), newTag->toBinaryNBT(isLittle), true);
        return;
    }
    logger.info(newTag->toSNBT(3));
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