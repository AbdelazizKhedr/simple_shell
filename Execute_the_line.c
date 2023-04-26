#include "main.h"

/**
 * execute_line - finds builtins and commands
 * @Datashell: data relevant (argss)
 * Return: 1 on success.
 */
int execute_line(Data_shell *Datashell)
{
	int (*builtin)(Data_shell *Datashell);

	if (Datashell->argss[0] == NULL)
		return (1);

	builtin = Get_built_in(Datashell->argss[0]);

	if (builtin != NULL)
		return (builtin(Datashell));

	return (cmd_exe(Datashell));
}
