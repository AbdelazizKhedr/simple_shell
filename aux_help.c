#include "main.h"

/**
 * help_envirr - Help information for the builtin env
 * Return: no return
 */
void help_envirr(void)
{
	char *help = "env: env [option] [name=value] [command [argss]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));

}
/**
 * help_setenvirr - Help information for the builtin setenv
 * Return: no return
 */
void help_setenvirr(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * help_unsetenvirr - Help information for the builtin unsetenv
 * Return: no return
 */
void help_unsetenvirr(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}


/**
 * help_general - Entry point for help information for the help builtin
 * Return: no return
 */
void help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[argss]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * help_exit - Help information fot the builint exit
 * Return: no return
 */
void help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
