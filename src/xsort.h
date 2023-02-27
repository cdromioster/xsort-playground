#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define MAX_VALUE 50000

#define DICTIONARY_SIZE 4096 //256, 512, 1024, 2048, 4096 - number of subwords in dictionary
#define DICTIONARY_SUBWORD_BIT_COUNT 12 //(log2(DICTIONARY_SIZE)) - length of dictionary word in bits
#define PREFIX_MASK (((0xFF<<DICTIONARY_SUBWORD_BIT_COUNT) & 0xFF00) >> 8) //0xF0 - mask for the bits used in high byte by prefix
#define SUBWORD_MASK (((0xFF<<DICTIONARY_SUBWORD_BIT_COUNT) & 0xFF00) ^ 0xFF00) //0x0F00 - mask for the bits used in high byte by subword
#define BITS_IN_BYTE 8

#define LO_BYTE(a)		*((uint8_t *)&a) //extract low byte fom uint16_t
#define HI_BYTE(a)		*(((uint8_t *)&a) + 1) //extract high byte fom uint16_t

void xsort(const uint16_t* input, size_t size, uint16_t* output);
