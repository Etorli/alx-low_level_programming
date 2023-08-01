#include "lists.h"

/**
 * pop_listint - deletes head node of linked list type
 * @head: pointer to the element in the linked list type
 *
 * Return: the data inside the elements that was detected,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}
