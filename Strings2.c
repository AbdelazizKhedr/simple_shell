#include "main.h"

/**
 * _strdup - duplicates str in the heap.
 * @str: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *str)
{
	char *new;
	size_t length;

	length = _strlen(str);
	new = malloc(sizeof(char) * (length + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, str, length + 1);
	return (new);
}

/**
 * _strlen - Returns the lenght of a string.
 * @str: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *str)
{
	int length;

	for (length = 0; str[length] != 0; length++)
	{
	}
	return (length);
}

/**
 * cmp_chars - compare characters of strings
 * @string: input string.
 * @delimit: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char string[], const char *delimit)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; string[i]; i++)
	{
		for (j = 0; delimit[j]; j++)
		{
			if (string[i] == delimit[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - split string by delimiter.
 * @string: input string.
 * @delimit: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char string[], const char *delimit)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(string, delimit))
			return (NULL);
		splitted = string;
		i = _strlen(string);
		str_end = &string[i];
	}
	str_start = splitted;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		for (i = 0; delimit[i]; i++)
		{
			if (*splitted == delimit[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @str: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}

