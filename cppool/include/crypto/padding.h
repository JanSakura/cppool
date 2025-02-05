#ifndef _CPPOOL_CRYPTO_PADDING_H_
#define _CPPOOL_CRYPTO_PADDING_H_

#ifdef __cplusplus
#include<cstdint>
#include<random>
#else
#include<stdint.h>
#include<time.h>
#endif // __cplusplus

namespace cppool
{
	namespace crypto
	{

		uint64_t GenRandomUInt64(uint64_t _min = 0, uint64_t _max = UINT64_MAX);
		
		void GenRandomSequence(uint8_t* str, uint64_t need_length);

		/* prepare enough memory
		* example:block_size is 16, current_length is 10, than 
		* last block: {1,2,3,4,5,a,b,c,d,e} -> {1,2,3,4,5,a,b,c,d,e,6,6,6,6,6,6}
		* if block_size is 8, current_length is 8 than: 
		* last block {0,1,2,3,4,5,6,7} -> {0,1,2,3,4,5,6,7, 8,8,8,8,8,8,8,8}
		*/
		void PKCS7LastBlockPadding(unsigned char* text, int32_t& current_len_index, uint8_t block_size);

		/*IN length equal to block_size, OUT return real length*/
		void PKCS7LastBlockPaddingReverse(unsigned char* text, int32_t& current_len_index, uint8_t block_size);

	}
}

#endif
