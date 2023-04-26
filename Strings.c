#include "main.h"

/**
 * _strcat - concatenate two strings
 * @destination: char pointer the destination of the copied string
 * @source: const char pointer the source of string
 * Return: the destination
 */
char *_strcat(char *destination, const char *source)
{
	int i;
	int j;

	for (i = 0; destination[i] != '\0'; i++)
		;

	for (j = 0; source[j] != '\0'; j++)
	{
		destination[i] = source[j];
		i++;
	}

	destination[i] = '\0';
	return (destination);
}
/**
 * *_strcpy - Copy string pointed by the source.
 * @destination: Type char pointer the destination of the copied string
 * @source: Type char pointer the source of str
 * Return: the destination.
 */
char *_strcpy(char *destination, char *source)
{

	size_t a;

	for (a = 0; source[a] != '\0'; a++)
	{
		destination[a] = source[a];
	}
	destination[a] = '\0';

	return (destination);
}
/**
 * _strcmp - Function compares two strings.
 * @str1: type str compared
 * @str2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i]; i++)
		;

	if (str1[i] > str2[i])
		return (1);
	if (str1[i] < str2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *Accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(Accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(Accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
