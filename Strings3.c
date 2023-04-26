#include "main.h"

/**
 * mex_string- reverses a string.
 * @str: input string.
 * Return: no return.
 */
void mex_string(char *str)
{
	int count = 0, i, j;
	char *str2, temp;

	while (count >= 0)
	{
		if (str[count] == '\0')
			break;
		count++;
	}
	str2 = str;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str2 + j);
			*(str2 + j) = *(str2 + (j - 1));
			*(str2 + (j - 1)) = temp;
		}
	}
}

