#include "main.h"

/**
 * strcat_cd - concatenates the message for cd error
 * @Datashell: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(Data_shell *Datashell, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, Datashell->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, Datashell->argss[0]);
	_strcat(error, msg);
	if (Datashell->argss[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = Datashell->argss[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, Datashell->argss[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * err_Getcd - error message for cd command
 * @Datashell: data relevant (directory)
 * Return: Error message
 */
char *err_Getcd(Data_shell *Datashell)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = itoa(Datashell->counter);
	if (Datashell->argss[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(Datashell->argss[1]);
	}

	length = _strlen(Datashell->argv[0]) + _strlen(Datashell->argss[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(Datashell, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * err_NotFound - error for command not found
 * @Datashell: data relevant (counter, arguments)
 * Return: Error message
 */
char *err_NotFound(Data_shell *Datashell)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = itoa(Datashell->counter);
	length = _strlen(Datashell->argv[0]) + _strlen(ver_str);
	length += _strlen(Datashell->argss[0]) + 16;
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
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * err_ShellExit - error for exit in Exit
 * @Datashell: data relevant (counter, arguments)
 * Return: Error message
 */
char *err_ShellExit(Data_shell *Datashell)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = itoa(Datashell->counter);
	length = _strlen(Datashell->argv[0]) + _strlen(ver_str);
	length += _strlen(Datashell->argss[0]) + _strlen(Datashell->argss[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, Datashell->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, Datashell->argss[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, Datashell->argss[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
