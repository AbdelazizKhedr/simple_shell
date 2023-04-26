#include "main.h"

/**
 * exec_line - finds builtins and commands
 *
 * @Datashell: data relevant (argss)
 * Return: 1 on success.
 */
int exec_line(Data_shell *Datashell)
{
	int (*builtin)(Data_shell *Datashell);

	if (Datashell->argss[0] == NULL)
		return (1);

	builtin = get_builtin(Datashell->argss[0]);

	if (builtin != NULL)
		return (builtin(Datashell));

	return (cmd_exec(Datashell));
}
