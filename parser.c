#include "shell.h"

/**
 * parser - Tokenizes a string into an array of substrings using a delimiter
 *
 * @lineptr: Pointer to the input string to be tokenized
 *
 * @delim: Delimiter character used to split the input string
 *
 * Return: Pointer to an array of strings, with each element containing a
 * substring of the input string separated by the delimiter character.
 *
 * The last element of the array is NULL.
 */
char **parser(char *lineptr, char *delim)
{
	char **cmnds = NULL;
	char *cmnd = NULL;
	int i = 0;

	cmnds = malloc(sizeof(char *) * 10);
	if (cmnds == NULL)
	{
		return (NULL);
	}

	cmnd = strtok(lineptr, delim);
	while (cmnd)
	{
		cmnds[i] = malloc(sizeof(char) * strlen(cmnd) + 1);
		if (cmnds[i] == NULL)
		{
			return (NULL);
		}
		strcpy(cmnds[i], cmnd);
		i++;
		cmnd = strtok(NULL, delim);
	}
	cmnds[i] = NULL;

	free(cmnd);
	return (cmnds);
}
