#include "pch.h"
#include "DBStorageHelper.h"



string bytesToHexStr(byte* byte_arr, int arr_len, string prefix)
{
	std::string hexstr;
	//
	for (int i = 0; nullptr != byte_arr && i < arr_len; ++i)
	{
		char hex1;
		char hex2;

		/*借助C++支持的unsigned和int的强制转换，把unsigned char赋值给int的值，那么系统就会自动完成强制转换*/
		int value = (int)byte_arr[i];
		int S = value / 16;
		int Y = value % 16;

		//将C++中unsigned char和int的强制转换得到的商转成字母
		if (S >= 0 && S <= 9)
		{
			hex1 = (char)(48 + S);
		}
		else
		{
			hex1 = (char)(55 + S);
		}

		//将C++中unsigned char和int的强制转换得到的余数转成字母
		if (Y >= 0 && Y <= 9)
		{
			hex2 = (char)(48 + Y);
		}
		else
		{
			hex2 = (char)(55 + Y);
		}

		//最后一步的代码实现，将所得到的两个字母连接成字符串达到目的
		hexstr = hexstr + prefix + hex1 + hex2;
	}

	return hexstr;
}
string bytesToHexStr(string& str, string prefix) {
	return bytesToHexStr((byte*)str.c_str(), str.length(), prefix);
}
string keyToString(string& key, string prefix) {
	if (std::regex_match(key, std::regex("[\\w ,\.\-]*")))
		return key;
	return bytesToHexStr(key, prefix);
}

string string_span::toString()
{
	return string(str, len);
}

DBStorageHelper::DBStorageHelper(Level* level)
{
	if (!level) return;
	this->levelStorage = SymCall("?getLevelStorage@Level@@UEBAAEBVLevelStorage@@XZ"
		, DBStorage*, Level*)(level);
}
