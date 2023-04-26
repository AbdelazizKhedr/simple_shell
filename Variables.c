#include "main.h"

/**
 * check_env - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: inp string
 * @data: data structure
 * Return: no return
 */
void check_env(S_Var **h, char *in, data_shell *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_envir;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _strlen(_envr[row] + chr + 1);
				add_rvar_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_node(h, j, NULL, 0);
}

/**
 * check_vars - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: inp string
 * @st: last stat of the Shell
 * @data: data structure
 * Return: no return
 */
int check_variables(S_Var **h, char *in, char *st, data_shell *data)
{
	int i, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->PID);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_rvar_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				add_rvar_node(h, 2, data->PID, lpd), i++;
			else if (in[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
	}

	return (i);
}

/**
 * replaced_inp - replaces string into variables
 *
 * @head: head of the linked list
 * @inp: inp string
 * @new_inp: new inp string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replaced_inp(S_Var **head, char *inp, char *new_inp, int nlen)
{
	S_Var *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (inp[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val_var))
			{
				new_inp[i] = inp[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val_var))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val_var; k++)
				{
					new_inp[i] = indx->val[k];
					i++;
				}
				j += (indx->len_var);
				i--;
			}
			indx = indx->next_node;
		}
		else
		{
			new_inp[i] = inp[j];
			j++;
		}
	}

	return (new_inp);
}

/**
 * rep_var - calls functions to replace string into vars
 *
 * @inp: inp string
 * @Datashell: data structure
 * Return: replaced string
 */
char *rep_var(char *inp, data_shell *Datashell)
{
	S_Var *head, *indx;
	char *stat, *new_inp;
	int olen, nlen;

	stat = aux_itoa(Datashell->stat);
	head = NULL;

	olen = check_vars(&head, inp, stat, Datashell);

	if (head == NULL)
	{
		free(stat);
		return (inp);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val_var - indx->len_var);
		indx = indx->next_node;
	}

	nlen += olen;

	new_inp = malloc(sizeof(char) * (nlen + 1));
	new_inp[nlen] = '\0';

	new_inp = replaced_inp(&head, inp, new_inp, nlen);

	free(inp);
	free(stat);
	free_rvar_list(&head);

	return (new_inp);
}
