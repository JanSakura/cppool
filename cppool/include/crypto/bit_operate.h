#ifndef _CPPOOL_BIT_OPERATE_H_
#define _CPPOOL_BIT_OPERATE_H_

#ifdef __cplusplus
#include<cstdint>
#else
#include<stdint.h>
#endif // __cplusplus

namespace cppool::crypto
{
	// 过多的位运算,会损害程序的运行效率

#define BYTE_BIT_NUM 8
#define BYTE_BIT_MAX_OFFSET (BYTE_BIT_NUM - 1)


#define GET_BITES_TARGET_BIT(msg, bit_index) ( (msg[(bit_index) / 8] >> ((bit_index) % 8)) & 0x01u )

#define GET_BYTES_LAST_BIT(msg, msg_len) ((msg[(msg_len) - 1] >> 7) & 0x01u)

#define SET_BYTES_TARGET_BIT(msg, bit_index, bit_value) \
{\
	if((bit_value) == 1) { msg [((bit_index) / 8)]  |=  (0x1u) << ( (bit_index) %8 );}\
	else { msg [( (bit_index) / 8 )] &= ~(0x1u << (bit_index) % 8);  }\
}
#define SET_BYTES_TARGET_BYTE(msg , byte_index, byte_value) ( msg [ (byte_index) ] = byte_value )

	inline void XorBytes(uint8_t* str1, uint8_t* str2, uint64_t length);

	uint64_t CountOneInBytes(uint8_t* str, uint64_t len);

	inline bool IsPowerOfTwo(uint64_t num);


/* 从低位循环左移 == 从高位循环右移
* 注意:字符串data按字节排序为data[0]...data[len - 1]
* 按照位bit,从低位到高位,从低字节到高字节排序: data[0][0],...,data[0][7],data[1][0],...data[len -1][0],...,data[len -1][8]
* 则每一位bit的下标index为 byte_index * 8 + inner_bit_index,以上都是从 低位 到 高位 的逻辑顺序;
* 从低位到高位循环左移,实质是右位运算,因为位运算默认是高位到低位排序,不是<<1的位运算
* 如果是从高位到低位循环左移,则才是<<1位运算
*/
	void LeftCircularShift1BitFromLow(uint8_t* str, uint64_t len);
	void RightCircularShift1BitFromLow(uint8_t* str, uint64_t len);


}

#endif