/*
Every word in the input array consists of 16 bits. To minimize nubmer 
of the input array lookup iterations, every word is divided into prefix and subword.
Local dictionary variable with a size corresponding to total number of all possible
subwords is used to store the number of occurances of this subword in input array.
lookup iterations are performed for every possible suffix.
On every iteration, if input array word suffix corresponds to iteration number then
dictionary value at index corresponding to subword is incremented.
If any subword with current prefix was found during iteration, then corresponding
word is transferred into output array.
As the iterations are happening from smallest suffix to biggest and from smallest
subword to biggest this means that output array is beeng formed from smallest word
in input array to biggest. This guarantees that output array is sorted.

Example:
dictionary size: 4096 words (12 bits per subword)
input array value: 42942 = 0xA7BE
subword: 0x07BE - lower 12 bits
prefix: 0xA - remaining bits bitshifted by 12positions
*/

#include "xsort.h"

/**
 * Dictionary assisted custom sorting function
 * @param input - pointer to unsorted input array
 * @param size - number of elements to process
 * @param output - pointer to memory space for storing sorted output array
 * @retval none
*/
void xsort(const uint16_t* input, size_t size, uint16_t* output)
{
	size_t sorted_count = 0; // variable to store number of already processed variables
	uint16_t values_counter[DICTIONARY_SIZE]; // "dictionary" that contains number of words (corresponding to array index) found
	uint16_t low_byte; // subword of currently processed word 
	uint8_t values_found_flag = 1; // flag to indicate that some values were found on current iteration
	
	// iterate through all possible prefixes
	for (uint16_t high_byte = 0; high_byte <= ceil(MAX_VALUE/DICTIONARY_SIZE); high_byte++){
		
		// condition to stop itaration through array if all values already processed
		if (sorted_count >= size) {
			break;
		}

		// reset dictionary before starting iteration
		//if (values_found_flag != 0){
			// only reset dictionary before first iteration or when some values were found on previous iteration 
			// this saves CPU cycles if no values were found and dictionary is already empty
			memset(values_counter, 0, DICTIONARY_SIZE*sizeof(uint16_t));
		//	values_found_flag = 0;
		//}
		
		// lookup for values with curent prefix by iterate through an input array words
		for (uint16_t index = 0; index < size; index++){
			if ((HI_BYTE(input[index]) & PREFIX_MASK) == (high_byte << (DICTIONARY_SUBWORD_BIT_COUNT-BITS_IN_BYTE))){
				// if value with current prefix found then increment dictionary value with index corresponding to subword of found word
				low_byte = input[index] & (SUBWORD_MASK | 0xFF);
				values_counter[low_byte] ++;
				values_found_flag = 1;
			}
		}
		
		// if any items with current prefix was foundin input array
		if (values_found_flag != 0){
			// then populate the output array with corresponding words
			for (uint16_t j = 0; j < (DICTIONARY_SIZE); j++){
				while ( values_counter[j] >= 1){ // if the same word what found multiple times
					// then output array will be populed with this word corresponding ammount of times, one after another
					low_byte = j;
					output[sorted_count] = (high_byte << DICTIONARY_SUBWORD_BIT_COUNT) | low_byte;
					sorted_count++;
					values_counter[j]--;
				}
			}
		}
	}
}
	