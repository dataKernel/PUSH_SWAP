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
    int     firstElem;

    oldHead = *head;
    firstElem = (*head)->value;
    while(*head != NULL)
    {
        if((*head)->next == NULL)
        {
            (*head)->value = firstElem;
            *head = oldHead;
            return ;
        }
        (*head)->value = (*head)->next->value;
        *head = (*head)->next;
    }
}

void    rotate_all(t_node **headA, t_node **headB)
{
    rotate(headA);
    rotate(headB);
}