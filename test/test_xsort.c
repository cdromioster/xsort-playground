#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "xsort.h"
#include "file_utils.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ProductionCode);

TEST_SETUP(ProductionCode)
{
}

TEST_TEAR_DOWN(ProductionCode)
{

}

TEST(ProductionCode, xsortFunction_10RandomElements)
{
	uint16_t lengthInputFile = 10;
	char inputFilePath[] = "data_in/random_10.txt";
	
	uint16_t *inputArray;
	uint16_t *outputArray;
	FILE *inputFile;
	size_t receivedWordsCount = 0; // number of received rows

	//allocate memory
	inputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	outputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	// read input file
	inputFile =  fopen(inputFilePath, "r");
	receivedWordsCount = processInputFile(inputFile, inputArray);
	fclose(inputFile);
	
	// run xsort
	xsort(inputArray, receivedWordsCount, outputArray);
	
	// verify the number of elements in input array
	TEST_ASSERT_EQUAL(lengthInputFile, receivedWordsCount);

	// compare sum of all elements in input and output arrays
	uint64_t sumInputArray = 0;
	uint64_t sumOutputArray = 0;

	for (size_t i = 0; i < receivedWordsCount; i++) {
		sumInputArray += inputArray[i];
		sumOutputArray += outputArray[i];
	}
	TEST_ASSERT_EQUAL(sumInputArray, sumOutputArray);

	// check that each next element is bigger or equal to previous one in the output array
	uint8_t isSortedFlag = 1;
	for (size_t i = 1; i < receivedWordsCount; i++) {
		if (outputArray[i] >= outputArray[i-1]){
			continue;
		} else {
			isSortedFlag = 0; // indicate sequence error
			break;
		}
	}
	TEST_ASSERT(isSortedFlag == 1);

	free(inputArray);
	free(outputArray);
}

TEST(ProductionCode, xsortFunction_256RandomElements)
{
	uint16_t lengthInputFile = 256;
	char inputFilePath[] = "data_in/random_256.txt";
	
	uint16_t *inputArray;
	uint16_t *outputArray;
	FILE *inputFile;
	size_t receivedWordsCount = 0; // number of received rows

	//allocate memory
	inputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	outputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	// read input file
	inputFile =  fopen(inputFilePath, "r");
	receivedWordsCount = processInputFile(inputFile, inputArray);
	fclose(inputFile);
	
	// run xsort
	xsort(inputArray, receivedWordsCount, outputArray);
	
	// verify the number of elements in input array
	TEST_ASSERT_EQUAL(lengthInputFile, receivedWordsCount);

	// compare sum of all elements in input and output arrays
	uint64_t sumInputArray = 0;
	uint64_t sumOutputArray = 0;

	for (size_t i = 0; i < receivedWordsCount; i++) {
		sumInputArray += inputArray[i];
		sumOutputArray += outputArray[i];
	}
	TEST_ASSERT_EQUAL(sumInputArray, sumOutputArray);

	// check that each next element is bigger or equal to previous one in the output array
	uint8_t isSortedFlag = 1;
	for (size_t i = 1; i < receivedWordsCount; i++) {
		if (outputArray[i] >= outputArray[i-1]){
			continue;
		} else {
			isSortedFlag = 0; // indicate sequence error
			break;
		}
	}
	TEST_ASSERT(isSortedFlag == 1);

	free(inputArray);
	free(outputArray);
}

TEST(ProductionCode, xsortFunction_1000RandomElements)
{
	uint16_t lengthInputFile = 1000;
	char inputFilePath[] = "data_in/random_1000.txt";
	
	uint16_t *inputArray;
	uint16_t *outputArray;
	FILE *inputFile;
	size_t receivedWordsCount = 0; // number of received rows

	//allocate memory
	inputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	outputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	// read input file
	inputFile =  fopen(inputFilePath, "r");
	receivedWordsCount = processInputFile(inputFile, inputArray);
	fclose(inputFile);
	
	// run xsort
	xsort(inputArray, receivedWordsCount, outputArray);
	
	// verify the number of elements in input array
	TEST_ASSERT_EQUAL(lengthInputFile, receivedWordsCount);

	// compare sum of all elements in input and output arrays
	uint64_t sumInputArray = 0;
	uint64_t sumOutputArray = 0;

	for (size_t i = 0; i < receivedWordsCount; i++) {
		sumInputArray += inputArray[i];
		sumOutputArray += outputArray[i];
	}
	TEST_ASSERT_EQUAL(sumInputArray, sumOutputArray);

	// check that each next element is bigger or equal to previous one in the output array
	uint8_t isSortedFlag = 1;
	for (size_t i = 1; i < receivedWordsCount; i++) {
		if (outputArray[i] >= outputArray[i-1]){
			continue;
		} else {
			isSortedFlag = 0; // indicate sequence error
			break;
		}
	}
	TEST_ASSERT(isSortedFlag == 1);

	free(inputArray);
	free(outputArray);
}

TEST(ProductionCode, xsortFunction_10000RandomElements)
{
	uint16_t lengthInputFile = 10000;
	char inputFilePath[] = "data_in/random_10000.txt";
	
	uint16_t *inputArray;
	uint16_t *outputArray;
	FILE *inputFile;
	size_t receivedWordsCount = 0; // number of received rows

	//allocate memory
	inputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	outputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	// read input file
	inputFile =  fopen(inputFilePath, "r");
	receivedWordsCount = processInputFile(inputFile, inputArray);
	fclose(inputFile);
	
	// run xsort
	xsort(inputArray, receivedWordsCount, outputArray);
	
	// verify the number of elements in input array
	TEST_ASSERT_EQUAL(lengthInputFile, receivedWordsCount);

	// compare sum of all elements in input and output arrays
	uint64_t sumInputArray = 0;
	uint64_t sumOutputArray = 0;

	for (size_t i = 0; i < receivedWordsCount; i++) {
		sumInputArray += inputArray[i];
		sumOutputArray += outputArray[i];
	}
	TEST_ASSERT_EQUAL(sumInputArray, sumOutputArray);

	// check that each next element is bigger or equal to previous one in the output array
	uint8_t isSortedFlag = 1;
	for (size_t i = 1; i < receivedWordsCount; i++) {
		if (outputArray[i] >= outputArray[i-1]){
			continue;
		} else {
			isSortedFlag = 0; // indicate sequence error
			break;
		}
	}
	TEST_ASSERT(isSortedFlag == 1);

	free(inputArray);
	free(outputArray);
}

TEST(ProductionCode, xsortFunction_50000RandomElements)
{
	uint16_t lengthInputFile = 50000;
	char inputFilePath[] = "data_in/random_50000.txt";
	
	uint16_t *inputArray;
	uint16_t *outputArray;
	FILE *inputFile;
	size_t receivedWordsCount = 0; // number of received rows

	//allocate memory
	inputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	outputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	// read input file
	inputFile =  fopen(inputFilePath, "r");
	receivedWordsCount = processInputFile(inputFile, inputArray);
	fclose(inputFile);
	
	// run xsort
	xsort(inputArray, receivedWordsCount, outputArray);
	
	// verify the number of elements in input array
	TEST_ASSERT_EQUAL(lengthInputFile, receivedWordsCount);

	// compare sum of all elements in input and output arrays
	uint64_t sumInputArray = 0;
	uint64_t sumOutputArray = 0;

	for (size_t i = 0; i < receivedWordsCount; i++) {
		sumInputArray += inputArray[i];
		sumOutputArray += outputArray[i];
	}
	TEST_ASSERT_EQUAL(sumInputArray, sumOutputArray);

	// check that each next element is bigger or equal to previous one in the output array
	uint8_t isSortedFlag = 1;
	for (size_t i = 1; i < receivedWordsCount; i++) {
		if (outputArray[i] >= outputArray[i-1]){
			continue;
		} else {
			isSortedFlag = 0; // indicate sequence error
			break;
		}
	}
	TEST_ASSERT(isSortedFlag == 1);

	free(inputArray);
	free(outputArray);
}

TEST(ProductionCode, xsortFunction_50000AlreadySortredElements)
{
	uint16_t lengthInputFile = 50000;
	char inputFilePath[] = "data_in/sorted_random_50000.txt";
	
	uint16_t *inputArray;
	uint16_t *outputArray;
	FILE *inputFile;
	size_t receivedWordsCount = 0; // number of received rows

	//allocate memory
	inputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	outputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	// read input file
	inputFile =  fopen(inputFilePath, "r");
	receivedWordsCount = processInputFile(inputFile, inputArray);
	fclose(inputFile);
	
	// run xsort
	xsort(inputArray, receivedWordsCount, outputArray);
	
	// verify the number of elements in input array
	TEST_ASSERT_EQUAL(lengthInputFile, receivedWordsCount);

	// compare sum of all elements in input and output arrays
	uint64_t sumInputArray = 0;
	uint64_t sumOutputArray = 0;

	for (size_t i = 0; i < receivedWordsCount; i++) {
		sumInputArray += inputArray[i];
		sumOutputArray += outputArray[i];
	}
	TEST_ASSERT_EQUAL(sumInputArray, sumOutputArray);

	// check that each next element is bigger or equal to previous one in the output array
	uint8_t isSortedFlag = 1;
	for (size_t i = 1; i < receivedWordsCount; i++) {
		if (outputArray[i] >= outputArray[i-1]){
			continue;
		} else {
			isSortedFlag = 0; // indicate sequence error
			break;
		}
	}
	TEST_ASSERT(isSortedFlag == 1);

	free(inputArray);
	free(outputArray);
}

TEST(ProductionCode, xsortFunction_50000ReverseSortedElements)
{
	uint16_t lengthInputFile = 50000;
	char inputFilePath[] = "data_in/reversesorted_random_50000.txt";
	
	uint16_t *inputArray;
	uint16_t *outputArray;
	FILE *inputFile;
	size_t receivedWordsCount = 0; // number of received rows

	//allocate memory
	inputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	outputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	// read input file
	inputFile =  fopen(inputFilePath, "r");
	receivedWordsCount = processInputFile(inputFile, inputArray);
	fclose(inputFile);
	
	// run xsort
	xsort(inputArray, receivedWordsCount, outputArray);
	
	// verify the number of elements in input array
	TEST_ASSERT_EQUAL(lengthInputFile, receivedWordsCount);

	// compare sum of all elements in input and output arrays
	uint64_t sumInputArray = 0;
	uint64_t sumOutputArray = 0;

	for (size_t i = 0; i < receivedWordsCount; i++) {
		sumInputArray += inputArray[i];
		sumOutputArray += outputArray[i];
	}
	TEST_ASSERT_EQUAL(sumInputArray, sumOutputArray);

	// check that each next element is bigger or equal to previous one in the output array
	uint8_t isSortedFlag = 1;
	for (size_t i = 1; i < receivedWordsCount; i++) {
		if (outputArray[i] >= outputArray[i-1]){
			continue;
		} else {
			isSortedFlag = 0; // indicate sequence error
			break;
		}
	}
	TEST_ASSERT(isSortedFlag == 1);

	free(inputArray);
	free(outputArray);
}

TEST(ProductionCode, xsortFunction_50000FewUniqueElements)
{
	uint16_t lengthInputFile = 50000;
	char inputFilePath[] = "data_in/few_unique_50000.txt";
	
	uint16_t *inputArray;
	uint16_t *outputArray;
	FILE *inputFile;
	size_t receivedWordsCount = 0; // number of received rows

	//allocate memory
	inputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	outputArray = (uint16_t *) malloc(50000*sizeof(uint16_t));
	// read input file
	inputFile =  fopen(inputFilePath, "r");
	receivedWordsCount = processInputFile(inputFile, inputArray);
	fclose(inputFile);
	
	// run xsort
	xsort(inputArray, receivedWordsCount, outputArray);
	
	// verify the number of elements in input array
	TEST_ASSERT_EQUAL(lengthInputFile, receivedWordsCount);

	// compare sum of all elements in input and output arrays
	uint64_t sumInputArray = 0;
	uint64_t sumOutputArray = 0;

	for (size_t i = 0; i < receivedWordsCount; i++) {
		sumInputArray += inputArray[i];
		sumOutputArray += outputArray[i];
	}
	TEST_ASSERT_EQUAL(sumInputArray, sumOutputArray);

	// check that each next element is bigger or equal to previous one in the output array
	uint8_t isSortedFlag = 1;
	for (size_t i = 1; i < receivedWordsCount; i++) {
		if (outputArray[i] >= outputArray[i-1]){
			continue;
		} else {
			isSortedFlag = 0; // indicate sequence error
			break;
		}
	}
	TEST_ASSERT(isSortedFlag == 1);

	free(inputArray);
	free(outputArray);
}
