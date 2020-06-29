#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

uint16_t u16FlipHigherByte(uint16_t u16Number)
{
	uint8_t u8LowerByte = (uint8_t) u16Number; 
	uint8_t u8HigherByte = (uint8_t) (u16Number >> 8);

	uint8_t u8temp = (((u8HigherByte & 0xF0) >> 4) | ((u8HigherByte & 0x0F) << 4));
	printf("0x%X\n", u8temp);

	return ((u8temp << 8) | u8LowerByte);
}

/* 
 * Swapping higher bits - this was asked in Apple Interview.
 */

uint16_t u16SwapAllHigherBits(uint8_t v)
{
	uint8_t r = v & 1; // r will be reversed bits of v; first get LSB of v
	printf("r: 0x%X\n", r);

	int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end
	printf("s: 0x%x, sizeof(v): %lu bytes, CharBit: %d bits\n", s, sizeof(v), CHAR_BIT);
	printf("------------------------------------\n");

	for (v >>= 1; v; v >>= 1)
	{   
		r <<= 1;
		printf("v: 0x%X, r: 0x%X\n", v, r);
		
		r |= v & 1;
		s--;
	}

	printf("------------------------------------\n");
	printf("r: 0x%X, s: %d\n\n", r, s);
	r <<= s; // shift when v's highest bits are zero	

	printf("0x%X\n", r);
	return r;
}

int main(void)
{
	uint16_t u16Number = 0xABCD; 
	printf("Actual_Number: 0x%X, HigherByteFlipped: 0x%X\r\n", u16Number, u16FlipHigherByte(u16Number));

	u16Number = 0x05CD;	
	uint8_t u8LowerByte = (uint8_t) u16Number; 
	uint8_t u8HigherByte = (uint8_t) (u16Number >> 8);

	printf("Actual_Number: 0x%X, SwapHigherByte: 0x%X\r\n", u16Number, (((u16SwapAllHigherBits(u8HigherByte)) << 8) | u8LowerByte));

	return 0;
}