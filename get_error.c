#include "main.h"

/**
 * Get_the_errors - calls the error according the builtin, syntax or permission
 * @Datashell: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int Get_the_errors(data_shell *Datashell, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(Datashell);
		break;
	case 126:
		error = error_path_126(Datashell);
		break;
	case 127:
		error = error_not_found(Datashell);
		break;
	case 2:
		if (_strcmp("exit", Datashell->args[0]) == 0)
			error = error_exit_shell(Datashell);
		else if (_strcmp("cd", Datashell->args[0]) == 0)
			error = error_get_cd(Datashell);
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
