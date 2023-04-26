#include "main.h"

/**
 * cdshell - changes the current directory
 * @datash: data relevant
 * Return: 1 on success
 */
int cdshell(Data_shell *Datashell)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = Datashell->argss[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_home(Datashell);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_backword(Datashell);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(Datashell);
		return (1);
	}

	cd_forword(datash);

	return (1);
}
