#include "main.h"

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenvirr - get an environment variable
 * @name: name of the environment variable
 * @_envir: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenvirr(const char *name, char **_envir)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; _envir[i]; i++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_envir[i], name);
		if (mov)
		{
			ptr_env = _envir[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the evironment variables
 *
 * @Datashell: data relevant.
 * Return: 1 on success.
 */
int _envirr(Data_shell *Datashell)
{
	int i, j;

	for (i = 0; Datashell->_envir[i]; i++)
	{

		for (j = 0; Datashell->_envir[i][j]; j++)
			;

		write(STDOUT_FILENO, Datashell->_envir[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	Datashell->stat = 0;

	return (1);
}
