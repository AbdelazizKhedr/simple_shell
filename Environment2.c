#include "main.h"

/**
 * Copy_information - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *Copy_information(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_envirr - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @Datashell: data structure (environ)
 * Return: no return
 */
void set_envirr(char *name, char *value, Data_shell *Datashell)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; Datashell->_envir[i]; i++)
	{
		var_env = _strdup(Datashell->_envir[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(Datashell->_envir[i]);
			Datashell->_envir[i] = Copy_information(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	Datashell->_envir = _reallocdp(Datashell->_envir, i, sizeof(char *) * (i + 2));
	Datashell->_envir[i] = Copy_information(name, value);
	Datashell->_envir[i + 1] = NULL;
}

/**
 * _setenvirr - compares env variables names
 * with the name passed.
 * @Datashell: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenvirr(Data_shell *Datashell)
{

	if (Datashell->argss[1] == NULL || Datashell->argss[2] == NULL)
	{
		Get_the_errors(Datashell, -1);
		return (1);
	}

	set_envirr(Datashell->argss[1], Datashell->argss[2], Datashell);

	return (1);
}

/**
 * _unsetenvirr - deletes a environment variable
 *
 * @Datashell: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenvirr(Data_shell *Datashell)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (Datashell->argss[1] == NULL)
	{
		Get_the_errors(Datashell, -1);
		return (1);
	}
	k = -1;
	for (i = 0; Datashell->_envir[i]; i++)
	{
		var_env = _strdup(Datashell->_envir[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, Datashell->argss[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		Get_the_errors(Datashell, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; Datashell->_envir[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = Datashell->_envir[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(Datashell->_envir[k]);
	free(Datashell->_envir);
	Datashell->_envir = realloc_environ;
	return (1);
}
