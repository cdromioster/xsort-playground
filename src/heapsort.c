/*
* This is textbook based implementation of heapsort algorithm that was used as a firt solution and reference for a performance testing.
*/

#include "heapsort.h"

/**
 * function to swap array elements
 * @param a - pointer to first element
 * @param b - pointer to second element
 * @retval none
*/
void swap(uint16_t *a, uint16_t *b)
{
	uint16_t temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * modify heap to Max-Heap
*/
void heapify(uint16_t arr[], uint16_t n, uint16_t i)
{
	// Find largest among root, left child and right child
	uint32_t largest = i;
	uint32_t left = 2 * i + 1;
	uint32_t right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	// Swap and continue heapifying if root is not largest
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

/**
 * heapsort algorithm implementation
 * @param input - pointer to unsorted input array
 * @param size - number of elements to process
 * @param output - pointer to memory space for storing sorted output array
 * @retval none
*/
void heapSort(const uint16_t* input, size_t size, uint16_t* output)
{
	memcpy(output, input, size*sizeof(uint16_t));
	// Build max heap
	for (int32_t i = size / 2 - 1; i >= 0; i--){
		heapify(output, size, i);
}

	// Heap sort
	for (int32_t i = size - 1; i >= 0; i--) {
		swap(&output[0], &output[i]);

		// Heapify root element to get highest element at root again
		heapify(output, i, 0);
	}
}
