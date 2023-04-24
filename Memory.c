#include "main.h"

/**
 * _memcpy - copy the informations between void pointers.
 * @ptr2: destination pointer.
 * @ptr1: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *ptr2, const void *ptr1, unsigned int size)
{
	char *char_ptr1 = (char *)ptr1;
	char *char_ptr2 = (char *)ptr2;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_ptr2[i] = char_ptr1[i];
}

/**
 * _realloc - reallocates a memory block.
 * @ptr1: pointer to the memory previously allocated.
 * @size1: size, in bytes, of the allocated space of ptr1.
 * @size2: new size, in bytes, of the new memory block.
 *
 * Return: ptr1.
 * if size2 == size1, returns ptr1 without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr1, unsigned int size1, unsigned int size2)
{
	void *ptr2;

	if (ptr1 == NULL)
		return (malloc(size2));

	if (size2 == 0)
	{
		free(ptr1);
		return (NULL);
	}

	if (size2 == size1)
		return (ptr1);

	ptr2 = malloc(size2);
	if (ptr2 == NULL)
		return (NULL);

	if (size2 < size1)
		_memcpy(ptr2, ptr1, size2);
	else
		_memcpy(ptr2, ptr1, size1);

	free(ptr1);
	return (ptr2);
}

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @ptr1: double pointer to the memory previously allocated.
 * @size1: size, in bytes, of the allocated space of ptr1.
 * @size2: new size, in bytes, of the new memory block.
 *
 * Return: ptr1.
 * if size2 == size1, returns ptr1 without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr1, unsigned int size1, unsigned int size2)
{
	char **ptr2;
	unsigned int i;

	if (ptr1 == NULL)
		return (malloc(sizeof(char *) * size2));

	if (size2 == size1)
		return (ptr1);

	ptr2 = malloc(sizeof(char *) * size2);
	if (ptr2 == NULL)
		return (NULL);

	for (i = 0; i < size1; i++)
		ptr2[i] = ptr1[i];

	free(ptr1);

	return (ptr2);
}
