#include "main.h"

/**
 * parse_map - Parse a map from a file
 * @filename: Name of the file to read from 
 * @map: 2D array to store the map
 * @rows: Pointer to store the Rows in the map
 * @cols: Pointer to store the cols in the map
 */

void parse_map(const char *filename, int map[MAX_ROWS][MAX_COLS], int *rows, int *cols)
{
	int col;
	FILE *file = fopen(filename, "r");
	char line[MAX_COLS + 2]; /*Adding 2 for newline and null character*/


	if (!file)
	{
		perror("Unable to open file");
		return;
	}
	
	while (fgets(line, sizeof(line), file))
	{
		col = 0; /*Resets column for each row*/
		char *ptr = line; /*Using *ptr to trasverse the line*/

		while (*ptr != '\0' && *ptr != '\n' && col < MAX_COLS)
		{
			if (*ptr == '0' || *ptr == '1')
			{
				map[*rows][col] = *ptr - '0'; /*chnges the string to int and stres in the map*/
				col++;
			}
			ptr++;
		}
		*cols = col;
		(*rows)++;

	}
	fclose(file);
}
