#include "pch.h"
#include "Utils.h"

using namespace std;

void reverseBytes(byte* bytes, size_t count) {
    auto v5 = bytes + count - 1;
    if (v5 >= bytes)
    {
        auto v7 = bytes + 1;
        do
        {
            auto v8 = *(v7 - 1);
            *(v7 - 1) = *v5;
            *v5-- = v8;
        } while (v7++ <= v5);
    }
}
template <typename T>
void toBytes(byte* bytes, T num, bool isBigEndian) {
    size_t size = sizeof(T);
    //byte* bytes = new byte[size];
    memset(bytes, 0, size);
    *(T*)bytes = num;
    if (isBigEndian)
        reverseBytes(bytes, size);
}

template void toBytes(byte* bytes, int num, bool isBigEndian);
template void toBytes(byte* bytes, short num, bool isBigEndian);
template void toBytes(byte* bytes, long num, bool isBigEndian);
template void toBytes(byte* bytes, long long num, bool isBigEndian);
