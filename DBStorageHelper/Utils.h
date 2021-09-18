#pragma once
void reverseBytes(std::byte* bytes, size_t count);

template<typename T>
void toBytes(std::byte* bytes, T num, bool isBigEndian);
