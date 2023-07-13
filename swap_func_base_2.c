#include "include/stack.h"
#include "include/stack_utils.h"

#include <stdlib.h>

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_element(t_node **head, t_node *elem)
{
	t_node *firstElem;

	firstElem = *head;
	*head = elem;
	elem->next = firstElem;
}

void    rotate_a(t_node **headA)
{
    t_node  *oldHead;
    t_node  *position;
    
    if (headA == NULL || *headA == NULL)
        return;
    oldHead = *headA;
    *headA = (*headA)->next;
    position = *headA;
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

