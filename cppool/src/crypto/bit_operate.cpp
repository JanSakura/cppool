#include"crypto/bit_operate.h"

namespace cppool::crypto
{
	inline void XorBytes(uint8_t* str1, uint8_t* str2, uint64_t length)
	{
		for (size_t i = 0; i < length; ++i)
		{
			str2[i] = str1[i] ^ str2[i];
		}
	}

	uint64_t CountOneInBytes(uint8_t* str, uint64_t len)
	{
		uint64_t num_of_1 = 0;
		for (size_t i = 0; i < len * 8; ++i)
		{
			num_of_1 += GET_BITES_TARGET_BIT(str, i);
		}
		return num_of_1;
	}

	inline bool IsPowerOfTwo(uint64_t num)
	{
		// Generally, only positive integers are considered
		return ((num > 0) && ((num & (num - 1)) == 0));
	}

	void LeftCircularShift1BitFromLow(uint8_t* str, uint64_t len)
	{
		if (len < 1) return;

		uint8_t flag = str[0];

		for (uint64_t i = 0; i < len - 1; ++i)
		{
			str[i] = (str[i] >> 1) | (str[i + 1] << 7);
		}
		str[len - 1] = (str[len - 1] >> 1) | (flag << 7);

		return;
	}

	void RightCircularShift1BitFromLow(uint8_t* str, uint64_t len)
	{
		// 这个写为了两个函数看起来实现过程相似
		if (len < 1) return;

		uint8_t flag = str[len - 1];

		uint64_t i = 0x00;
		for (uint64_t _pos = 0; _pos < len - 1; ++_pos)
		{
			i = len - 1 - _pos;
			str[i] = (str[i] << 1) | (str[i - 1] >> 7);
		}
		str[0] = (str[0] << 1) | (flag >> 7);

		return;
	}
}