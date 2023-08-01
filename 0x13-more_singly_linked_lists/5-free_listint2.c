#include "lists.h"

/**
 * free_listint2 - Frees linked list of type listint_t.
 * @head: A double pointer to the first element of the list.
 *
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}

