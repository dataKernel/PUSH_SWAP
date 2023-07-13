#include "include/stack.h"
#include <stdio.h>

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
    reverse(headA);
    reverse(headB);    
}

void    rotate_all(t_node **headA, t_node **headB)
{
    if (headA != NULL || *headA != NULL || (*headA)->next != NULL)
        rotate_a(headA);
    if (headB != NULL || *headB != NULL || (*headB)->next != NULL)
        rotate_b(headB);
}