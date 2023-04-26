#include "main.h"

/**
 * Character_swap - swaps | and & for non-printed chars
 * @inp: input string
 * @bool: type of swap
 * Return: swapped string
 */
char *Character_swap(char *inp, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; inp[i]; i++)
		{
			if (inp[i] == '|')
			{
				if (inp[i + 1] != '|')
					inp[i] = 16;
				else
					i++;
			}

			if (inp[i] == '&')
			{
				if (inp[i + 1] != '&')
					inp[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; inp[i]; i++)
		{
			inp[i] = (inp[i] == 16 ? '|' : inp[i]);
			inp[i] = (inp[i] == 12 ? '&' : inp[i]);
		}
	}
	return (inp);
}

/**
 * Add_node - add separators and command lines in the lists
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @inp: input string
 * Return: no return
 */
void Add_node(sl_list **head_s, CLI_list **head_l, char *inp)
{
	int i;
	char *line;

	inp = Character_swap(inp, 0);

	for (i = 0; inp[i]; i++)
	{
		if (inp[i] == ';')
			Sl_node_end_Add(head_s, inp[i]);

		if (inp[i] == '|' || inp[i] == '&')
		{
			Sl_node_end_Add(head_s, inp[i]);
			i++;
		}
	}

	line = _strtok(inp, ";|&");
	do {
		line = Character_swap(line, 1);
		CLI_node_end_Add(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * to_next - go to the next command line stored
 * @list_s: separator list
 * @list_l: command line list
 * @Datashell: data structure
 * Return: no return
 */
void to_next(sl_list **list_s, CLI_list **list_l, Data_shell *Datashell)
{
	int loop_sep;
	sl_list *ls_s;
	CLI_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (Datashell->stat == 0)
		{
			if (ls_s->separrator == '&' || ls_s->separrator == ';')
				loop_sep = 0;
			if (ls_s->separrator == '|')
				ls_l = ls_l->next_node, ls_s = ls_s->next_node;
		}
		else
		{
			if (ls_s->separrator == '|' || ls_s->separrator == ';')
				loop_sep = 0;
			if (ls_s->separrator == '&')
				ls_l = ls_l->next_node, ls_s = ls_s->next_node;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next_node;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_all_commands - splits command lines according to
 * the separators ;, | and &, and executes them
 * @Datashell: data structure
 * @inp: input string
 * Return: 0 to exit, 1 to continue
 */
int split_all_commands(Data_shell *Datashell, char *inp)
{

	sl_list *head_s, *list_s;
	CLI_list *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	Add_node(&head_s, &head_l, inp);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		Datashell->inp = list_l->line;
		Datashell->argss = Split_the_line(Datashell->inp);
		loop = execute_line(Datashell);
		free(Datashell->argss);

		if (loop == 0)
			break;

		to_next(&list_s, &list_l, Datashell);

		if (list_l != NULL)
			list_l = list_l->next_node;
	}

	Sl_list_Free(&head_s);
	CLI_list_Free(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * Split_the_line - tokenizes the inp string
 *
 * @inp: input string.
 * Return: string splitted.
 */
char **Split_the_line(char *inp)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOKK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(inp, TOKK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOKK_BUFSIZE;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOKK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}

