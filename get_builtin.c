#include "main.h"

/**
 * Get_built_in - built in that pais in the command arguments
 * @cmd: command
 * Return: function pointer of the built in command
 */
int (*Get_built_in(char *cmd))(Data_shell *)
{
	Builtin_T builtin[] = {
		{ "env", _envirr },
		{ "exit", ShellExit },
		{ "setenv", _setenvirr },
		{ "unsetenv", _unsetenvirr },
		{ "cd", cdshell },
		{ "help", Get_Help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
