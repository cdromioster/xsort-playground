#include "file_utils.h"

/**
 * Function to strip spaces from the string
 * @param  *str - pointer to source string
 * @retval String stripped of leading and trailing spaces
*/
char* stripSpaces(char *str)
{
	// get word length ignoring line ends works for LF, CR, CRLF, LFCR
	unsigned char length = strcspn(str, "\r\n");
	
	// trim leading spaces
	while(str[0] == ' '){
		str++;
		length--;
	}
	
	// trim trailing spaces
	while(str[length-1] == ' '){
		length--;
	}
	// add line ending to explicitly mark end of word in string
	str[length] = '\n';
	
	return str;
}

/**
 * Function to read input file
 * @param file - file handler
 * @param pInput - pointer to array for reading into
 * @return number of words processed
*/
uint16_t processInputFile(FILE *file, uint16_t* pInput)
{
	char linesize; // variable to store current line length
	char lineSizeBeforeSpaces; // current line Length till first space
	char currentline[256]; // line readout buffer
	char* p_CurrentLine; // pointer to a readout buffer
	uint16_t receivedCharacters = 0; // number of received characters
	uint16_t _receivedRowsCount = 0; // number of received rows
	
	while (fgets(currentline, sizeof(currentline), file) != NULL) {
		// Strip received line of spaces
		p_CurrentLine = stripSpaces(currentline);
		linesize = strcspn(p_CurrentLine, "\r\n"); // get word length ignoring line ends works for LF, CR, CRLF, LFCR
		
		// Check if there are multiple words in one line
		lineSizeBeforeSpaces = strcspn(p_CurrentLine, " ");
		if (lineSizeBeforeSpaces < linesize) {
			printf("Error: Two numbers in one line:\n");
			printf("	%s",p_CurrentLine);
			return (0);
		}
		
		if (linesize > 0) {
			pInput[_receivedRowsCount] = strtol(p_CurrentLine,NULL,10);
			receivedCharacters += linesize;
			_receivedRowsCount += 1;
		} else {
			// Skip empty line
		}
		
		// Handle too many characters in input file
		if(_receivedRowsCount > 50000) {
			printf("Error: Too many numbers received.\n");
			printf("	Total characters received: %d\n", receivedCharacters);
			return (0);
		}
	}
	return _receivedRowsCount;
}

/**
 * Function to write output file 
 * @param file - file handler
 * @param pOutput - pointer to array that needs to be written into file
 * @param size - number of elements to write
 * @return number of words processed
*/
int writeOutputFile(FILE *file, const uint16_t* pOutput, size_t size)
{
	// size_t items_written = fwrite(pOutput, sizeof(uint16_t), size, file);
	size_t items_written = 0;
	for (size_t i = 0; i < size; i++) {
		fprintf(file, "%u\n", pOutput[i]);
		items_written++;
	}

	if (items_written != size) {
		return (1);
	}

	return (0);
}
