#include "main.h"

/**
 * read_line - reads input string.
 * @xyz: return value of getline function
 * Return: input string
 */
char *read_line(int *xyz)
{
	char *input = NULL;
	size_t bufsize = 0;

	*xyz = getline(&input, &bufsize, stdin);

	return (input);
}
