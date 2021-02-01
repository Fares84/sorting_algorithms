#include "sort.h"

/**
 *insertion_sort_list - function that sorts a doubly linked list of integers in
 *ascending order
 *@list: a double linked list
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *current = *list, *head = (*list)->next;

	if (!*list)
		return;

	while (head)
	{
		temp = head;
		while (temp->prev)
		{
			current = temp->prev;
			if (current->n > temp->n)
			{
				if (current->prev)
					current->prev->next = temp;
				else
					*list = temp;

				if (temp->next)
					temp->next->prev = current;

				current->next = temp->next;
				temp->prev = current->prev;

				temp->next = current;
				current->prev = temp;
				print_list(*list);
				continue;
			}
			temp = temp->prev;
		}
		head = head->next;
	}
}
