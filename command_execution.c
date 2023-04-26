#include "main.h"

/**
 * is_cdirect - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cdirect(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _whichone - locates a command
 *
 * @cmd: command name
 * @_envir: envirment variable
 * Return: location of the command.
 */
char *_whichone(char *cmd, char **_envir)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = _getenvirr("PATH", _envir);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdirect(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_exe - determines if is an executable
 *
 * @Datashell: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_exe(Data_shell *Datashell)
{
	struct stat st;
	int i;
	char *inp;

	inp = Datashell->argss[0];
	for (i = 0; inp[i]; i++)
	{
		if (inp[i] == '.')
		{
			if (inp[i + 1] == '.')
				return (0);
			if (inp[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (inp[i] == '/' && i != 0)
		{
			if (inp[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(inp + i, &st) == 0)
	{
		return (i);
	}
	Get_the_errors(Datashell, 127);
	return (-1);
}

/**
 * check_err_cmd - verifies if user has permissions to access
 * @dir: destination directory
 * @Datashell: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_err_cmd(char *dir, Data_shell *Datashell)
{
	if (dir == NULL)
	{
		Get_the_errors(Datashell, 127);
		return (1);
	}

	if (_strcmp(Datashell->argss[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(Datashell, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(Datashell->argss[0], X_OK) == -1)
		{
			get_error(Datashell, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exe - executes command lines
 *
 * @Datashell: data relevant (argss and inp)
 * Return: 1 on success.
 */
int cmd_exe(data_shell *Datashell)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_exe(Datashell);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _whichone(Datashell->argss[0], Datashell->_envir);
		if (check_err_cmd(dir, Datashell) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _whichone(Datashell->argss[0], Datashell->_envir);
		else
			dir = Datashell->argss[0];
		execve(dir + exec, Datashell->argss, Datashell->_envir);
	}
	else if (pd < 0)
	{
		perror(Datashell->argv[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	Datashell->stat = state / 256;
	return (1);
}
