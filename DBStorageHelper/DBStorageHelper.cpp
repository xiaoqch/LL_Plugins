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

		/*����C++֧�ֵ�unsigned��int��ǿ��ת������unsigned char��ֵ��int��ֵ����ôϵͳ�ͻ��Զ����ǿ��ת��*/
		int value = (int)byte_arr[i];
		int S = value / 16;
		int Y = value % 16;

		//��C++��unsigned char��int��ǿ��ת���õ�����ת����ĸ
		if (S >= 0 && S <= 9)
		{
			hex1 = (char)(48 + S);
		}
		else
		{
			hex1 = (char)(55 + S);
		}

		//��C++��unsigned char��int��ǿ��ת���õ�������ת����ĸ
		if (Y >= 0 && Y <= 9)
		{
			hex2 = (char)(48 + Y);
		}
		else
		{
			hex2 = (char)(55 + Y);
		}

		//���һ���Ĵ���ʵ�֣������õ���������ĸ���ӳ��ַ����ﵽĿ��
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
