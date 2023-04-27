#include "main.h"

/**
 * Get_the_errors - calls the error according the builtin, syntax or permission
 * @Datashell: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int Get_the_errors(Data_shell  *Datashell, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = err_environment(Datashell);
		break;
	case 126:
		error = err_path126(Datashell);
		break;
	case 127:
		error = err_NotFound(Datashell);
		break;
	case 2:
		if (_strcmp("exit", Datashell->argss[0]) == 0)
			error = err_ShellExit(Datashell);
		else if (_strcmp("cd", Datashell->argss[0]) == 0)
			error = err_Getcd(Datashell);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	Datashell->stat = eval;
	return (eval);
}
