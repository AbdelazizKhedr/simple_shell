#include "main.h"

/**
 * cd_dot - changes to the parent directory
 *
 * @Datashell: data relevant (environ)
 *
 * Return: no return
 */
void cd_dot(Data_shell *Datashell)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_envirr("OLDPWD", cp_pwd, Datashell);
	dir = Datashell->argss[1];
	if (_strcmp(".", dir) == 0)
	{
		set_envirr("PWD", cp_pwd, Datashell);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	mex_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_envirr("PWD", cp_strtok_pwd, Datashell);
	}
	else
	{
		chdir("/");
		set_envirr("PWD", "/", Datashell);
	}
	Datashell->stat = 0;
	free(cp_pwd);
}

/**
 * cd_forword - changes to a directory given
 * by the user
 *
 * @Datashell: data relevant (directories)
 * Return: no return
 */
void cd_forword(Data_shell  *Datashell)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = Datashell->argss[1];
	if (chdir(dir) == -1)
	{
		Get_the_errors(Datashell, 2);
		return;
	}

	cp_pwd = _strdup(pwd);
	set_envirr("OLDPWD", cp_pwd, Datashell);

	cp_dir = _strdup(dir);
	set_envirr("PWD", cp_dir, Datashell);

	free(cp_pwd);
	free(cp_dir);

	Datashell->stat = 0;

	chdir(dir);
}

/**
 * cd_backword - changes to the previous directory
 *
 * @Datashell: data relevant (environ)
 * Return: no return
 */
void cd_backword(Data_shell *Datashell)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = _getenvirr("OLDPWD", Datashell->_envir);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_envirr("OLDPWD", cp_pwd, Datashell);

	if (chdir(cp_oldpwd) == -1)
		set_envirr("PWD", cp_pwd, Datashell);
	else
		set_envirr("PWD", cp_oldpwd, Datashell);

	p_pwd = _getenvirr("PWD", Datashell->_envir);

	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	Datashell->stat = 0;

	chdir(p_pwd);
}

/**
 * cd_home - changes to home directory
 *
 * @Datashell: data relevant (environ)
 * Return: no return
 */
void cd_home(Data_shell *Datashell)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = _getenvirr("HOME", Datashell->_envir);

	if (home == NULL)
	{
		set_envirr("OLDPWD", p_pwd, Datashell);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		Get_the_errors(Datashell, 2);
		free(p_pwd);
		return;
	}

	set_envirr("OLDPWD", p_pwd, Datashell);
	set_envirr("PWD", home, Datashell);
	free(p_pwd);
	Datashell->stat = 0;
}
