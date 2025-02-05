#include"crypto/padding.h"

#ifdef __cplusplus
#include<cassert>
#else
#include<assert.h>
#endif

namespace cppool
{
	namespace crypto
	{

		uint64_t GenRandomUInt64(uint64_t _min, uint64_t _max)
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

		void GenRandomSequence(uint8_t* str, uint64_t need_length)
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

		void PKCS7LastBlockPadding(unsigned char* text, int32_t& current_len_index, uint8_t block_size)
		{
			if (current_len_index >= block_size) return;	// _err
			if (block_size < 1 || block_size > 0xff) return;
			uint8_t padding_len = block_size - current_len_index;
			int32_t i = 0;
			for (; i < padding_len; ++i)
			{
				text[current_len_index + i] = static_cast<unsigned char>(padding_len);
			}
			current_len_index += i;
		}

		void PKCS7LastBlockPaddingReverse(unsigned char* text, int32_t& current_len_index, uint8_t block_size)
		{
			if (block_size < 1 || block_size > 0xff) return;

			uint8_t padding_len = (uint8_t)text[block_size - 1];

			if (padding_len > block_size || padding_len < 1 || padding_len > 0xff) return;

			// Just easy to understand
			int32_t i = block_size - 1;
			for (; i > 0; --i)
			{
				text[i] = '\0';
			}
			current_len_index = i;
		}
	}
}