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

    if (head == NULL || *head == NULL)
        return;
    oldHead = *head;
    *head = (*head)->next;
    position = *head;
    while (position)
    {
        if (position->next == NULL)
        {
            position->next = oldHead;
            oldHead->next = NULL;
        }
        position = position->next;
    }
}

void    reverse(t_node **head)
{
    t_node  *oldHead;
    t_node  *position;

    if(head == NULL || *head == NULL)
        return ;
    oldHead = *head;
    position = *head;
    while(position)
    {
        if(position->next->next == NULL)
        {
            *head = position->next;
            position->next = NULL;
            (*head)->next = oldHead;
        }
        position = position->next;
    }
}

void    reverse_all(t_node **headA, t_node **headB)
{
    rotate(headA);
    rotate(headB);    
}

void    rotate_all(t_node **headA, t_node **headB)
{
    rotate(headA);
    rotate(headB);
}

