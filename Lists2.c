#include "main.h"

/**
 * SVar_node_ Add - adds the variable in the
 * S_Var end.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val_var: value of the variable.
 * @lval: length of the value.
 * Return: the address head.
 */
S_Var *SVar_node_ Add(S_Var **head, int lvar, char *val_var, int lval)
{
	S_Var *new, *temp;

	new = malloc(sizeof(S_Var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val_var = val_var;
	new->len_val_var = lval;

	new->next_node = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next_node != NULL)
			temp = temp->next_node;
		temp->next_node = new;
	}

	return (*head);
}

/**
 * SVar_list_Free - free S_Var list
 * @head: head of the linked list.
 * Return: no return.
 */
void SVar_list_Free(S_Var **head)
{
	S_Var *temp;
	S_Var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next_node;
			free(temp);
		}
		*head = NULL;
	}
}
