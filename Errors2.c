#include "main.h"

/**
 * err_environment - error message for env.
 * @Datashell: data relevant (counter, arguments)
 * Return: error message.
 */
char *err_environment(Data_shell *Datashell)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = itoa(Datashell->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(Datashell->argv[0]) + _strlen(ver_str);
	length += _strlen(Datashell->argss[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, Datashell->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, Datashell->argss[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * err_path126 - error  for path and failure permission denied.
 * @Datashell: data relevant (counter, arguments).
 * Return: The error string.
 */
char *err_path126(Data_shell *Datashell)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = itoa(Datashell->counter);
	length = _strlen(Datashell->argv[0]) + _strlen(ver_str);
	length += _strlen(Datashell->argss[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, Datashell->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, Datashell->argss[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
