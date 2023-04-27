#include "main.h"

/**
 * ShellExit - exits the shell
 * @Datashell: data relevant (stat and argss)
 * Return: 0 on success.
 */
int ShellExit(Data_shell  *Datashell)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (Datashell->argss[1] != NULL)
	{
		ustatus = _atoi(Datashell->argss[1]);
		is_digit = _isdigit(Datashell->argss[1]);
		str_len = _strlen(Datashell->argss[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			Get_the_errors(Datashell, 2);
			Datashell->stat = 2;
			return (1);
		}
		Datashell->stat = (ustatus % 256);
	}
	return (0);
}
