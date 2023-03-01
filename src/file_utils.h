#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char* stripSpaces(char *str);
uint16_t processInputFile(FILE *file, uint16_t* pInput);
int writeOutputFile(FILE *file, const uint16_t* pOutput, size_t size);
