#include <stdint.h>
#include <stddef.h>
#include <string.h>

void swap(uint16_t *a, uint16_t *b);
void heapify(uint16_t arr[], uint16_t n, uint16_t i);
void heapSort(const uint16_t* input, size_t n, uint16_t* output);
