#include "include/stack.h"
#include <stdio.h>

t_node	*pop(t_node **head)
{
	t_node *firstElem;

	if (head == NULL || *head == NULL)
	{
		return (NULL);
	}
	firstElem = *head;
	*head = (*head)->next;
	firstElem->next = NULL;
	return (firstElem);
}

void    rotate(t_node **head)
{
    t_node  *oldHead;
    t_node  *position;

    oldHead = *head;
    *head = (*head)->next;
    position = *head;

    printf("old:%i__head:%i__posi:%i", oldHead->value, (*head)->value, position->value);
}

void    rotate_all(t_node **headA, t_node **headB)
{
    rotate(headA);
    rotate(headB);
}