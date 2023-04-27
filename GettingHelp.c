#include "holberton.h"

/**
 * Get_Help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int Get_Help(Data_shell *Datashell)
{

	if (Datashell->argss[1] == 0)
		help_general();
	else if (_strcmp(Datashell->argss[1], "setenv") == 0)
		help_setenvirr();
	else if (_strcmp(Datashell->argss[1], "env") == 0)
		help_envirr();
	else if (_strcmp(Datashell->argss[1], "unsetenv") == 0)
		help_unsetenvirr();
	else if (_strcmp(Datashell->argss[1], "help") == 0)
		auhelp();
	else if (_strcmp(Datashell->argss[1], "exit") == 0)
		help_exit();
	else if (_strcmp(Datashell->argss[1], "cd") == 0)
		help_cd();
	else if (_strcmp(Datashell->argss[1], "alias") == 0)
		help_alias();
	else
		write(STDERR_FILENO, Datashell->argss[0],
		      _strlen(Datashell->argss[0]));

	Datashell->stat = 0;
	return (1);
}
