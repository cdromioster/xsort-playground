#include <stdint.h>
#include "xsort.h"
#include "file_utils.h"
  
// includes for performance measurements
#ifdef _WIN32
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

FILE *inputFile;
FILE *outputFile;

char outputFolder[] = "data_out/";

int main(int, char *argv[])
{
	uint16_t *inputBuff;
	uint16_t *outputBuff;

	inputBuff = (uint16_t *) malloc(50000*sizeof(uint16_t));
	outputBuff = (uint16_t *) malloc(50000*sizeof(uint16_t));
	size_t receivedWordsCount = 0; // number of received rows
	
	//Handle command line argument
	if (argv[1] != NULL){
		//inputFile =  fopen("data_in/sorted_random_50000.txt", "r");
		inputFile =  fopen(argv[1], "r");
	} else {
		printf("Error: File not found.\n");
		printf("Specify souce file as a command line argument. Example: \"xsort_file data_in/sorted_random_50000.txt data_out/sorted_random_50000_sorted.txt\"\n");

		free(inputBuff);
		free(outputBuff);
		return (404);
	}

	if (argv[2] != NULL){
		//outputFile =  fopen("data_out/sorted_random_50000_sorted.txt", "w");
		outputFile =  fopen(argv[2], "w");
	} else {
		printf("Error: Output file not specified. Example: \"xsort_file data_in/sorted_random_50000.txt data_out/sorted_random_50000_sorted.txt\"\n");

		free(inputBuff);
		free(outputBuff);
		return (405);
	}
	
	receivedWordsCount = processInputFile(inputFile, inputBuff);
	fclose(inputFile);

	uint64_t cycle_start = 0;
	uint64_t cycles_spent = 0;

	cycle_start = __rdtsc(); // remember current CPU cycle number
	xsort(inputBuff, receivedWordsCount, outputBuff);
	cycles_spent = __rdtsc() - cycle_start; // calculate used CPU cycles
	printf("Cycles spent, %llu \n", cycles_spent);

	writeOutputFile(outputFile, outputBuff, receivedWordsCount);
	fclose(outputFile);

	free(inputBuff);
	free(outputBuff);
	return (0);
}
