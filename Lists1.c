#include "main.h"

/**
 * Sl_node_end_Add - adds a separrator the end
 * of a sl_list.
 * @head: head of the linked list.
 * @sep: separrator found (; | &).
 * Return: address of the head.
 */
sl_list *Sl_node_end_Add(sl_list **head, char sep)
{
	sl_list *new, *temp;

	new = malloc(sizeof(sl_list));
	if (new == NULL)
		return (NULL);

	new->separrator = sep;
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
 * Sl_list_Free - free sl_list
 * @head: head of the linked list.
 * Return: no return.
 */
void Sl_list_Free(sl_list **head)
{
	sl_list *temp;
	sl_list *curr;

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

/**
 * CLI_node_end_Add - adds a line command at the
 * CLI_list end.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
CLI_list*CLI_node_end_Add(CLI_list**head, char *line)
{
	CLI_list*new, *temp;

	new = malloc(sizeof(CLI_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
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
 * CLI_list_Free- makes a line list free
 * @head: head of the linked list.
 * Return: no return.
 */
void CLI_list_Free(CLI_list**head)
{
	CLI_list*temp;
	CLI_list*curr;

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
