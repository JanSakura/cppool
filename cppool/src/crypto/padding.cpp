#include"crypto/padding.h"

namespace cppool::crypto
{

	static uint64_t GenRandomUInt64(uint64_t _min = 0, uint64_t _max = UINT64_MAX)
	{
#ifdef __cplusplus
		std::random_device rd;
		std::mt19937_64 mt(rd());
		std::uniform_int_distribution<uint64_t> dist(_min, _max);
		return dist(mt);
#else
		srand((uint64_t)(time(NULL)));
		int _x = rand();
		int _y = rand();
		uint64_t _ret = _x;
		_ret = _ret << 8;
		_ret += _y;
		_ret = _ret % (_max - _min + 1) + _min;
		return _ret;
#endif
	}

	static void GenRandomSequence(uint8_t* str, uint64_t need_length)
	{
		int round = need_length / sizeof(uint64_t);
		uint64_t temp = 0;
		for (size_t i = 0; i < round; ++i)
		{
			temp = GenRandomUInt64();
			memmove(str + (i * sizeof(uint64_t)), &temp, sizeof(uint64_t));
		}
		if (need_length % sizeof(uint64_t) != 0)
		{
			uint64_t temp = GenRandomUInt64();
			memmove(str + (round * sizeof(uint64_t)), &temp, need_length % sizeof(uint64_t));
		}
		return;
	}

	static void PKCS7LastBlockPadding(unsigned char* text, size_t length, uint32_t block_size)
	{
		if (length >= block_size) return;	// _err
		uint32_t padding_len = block_size - length;
		for (uint32_t i = 0; i < padding_len; ++i)
		{
			text[length + i] = static_cast<unsigned char>(padding_len);
		}
	}

	static void PKCS7LastBlockPaddingReverse(unsigned char* text, size_t& length, uint32_t block_size)
	{
		uint32_t padding_len = (uint32_t)text[block_size - 1];

		if (padding_len > block_size) return;

		// Just easy to understand
		for (int i = block_size - 1; padding_len > 0; --i)
		{
			text[i] = '\0';
			--length;
			--padding_len;
		}
	}
}