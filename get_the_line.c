#include "main.h"

/**
 * Bring_Line - assigns the line var for Get_Line
 * @linepointr: Buffer that store the inp str
 * @buffer: str that is been called to line
 * @n: size of line
 * @j: size of buffer
 */
void Bring_Line(char **linepointr, size_t *n, char *buffer, size_t j)
{

	if (*linepointr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*linepointr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*linepointr = buffer;
	}
	else
	{
		_strcpy(*linepointr, buffer);
		free(buffer);
	}
}
/**
 * Get_Line - Read inpt from stream
 * @linepointr: buffer that stores the inp
 * @n: size of linepointr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t Get_Line(char **linepointr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t inp;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (inp == 0)
		fflush(stream);
	else
		return (-1);
	inp = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && inp == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && inp != 0)
		{
			inp++;
			break;
		}
		if (inp >= BUFSIZE)
			buffer = _realloc(buffer, inp, inp + 1);
		buffer[inp] = t;
		inp++;
	}
	buffer[inp] = '\0';
	Bring_Line(linepointr, n, buffer, inp);
	retval = inp;
	if (i != 0)
		inp = 0;
	return (retval);
}
