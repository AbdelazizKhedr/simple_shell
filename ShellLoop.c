#include "main.h"

/**
 * No_comment - deletes comments from input
 * @in: input string
 * Return: input without comments
 */
char *No_comment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * sh_loop - Loop of shell
 * @Datashell: data relevant (argv, inp, argss)
 * Return: no return.
 */
void sh_loop(Data_shell *Datashell)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = No_comment(input);
			if (input == NULL)
				continue;

			if (check_synt_err(Datashell, input) == 1)
			{
				Datashell->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, Datashell);
			loop = split_commands(Datashell, input);
			Datashell->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

