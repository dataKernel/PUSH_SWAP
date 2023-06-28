#include <stdio.h>
#include "include/stack.h"
#include "include/stack_utils.h"

void    ordering_three_elem(t_node **headA, t_node **headB)
{
    if(size_list(headA) == 2)
    {
        //if((*headA)->value > (*headA)->next->value)
            //swap(headA);
    }
    else
    {
        printf("value: %p\n", *headA);
        //A > B > C
        /*if((*headA)->value > (*headA)->next->value && 
        (*headA)->next->value > (*headA)->next->next->value)
        {
            rotate(headA);
            swap(headA);
        }
        //A < B > C
        else if((*headA)->value < (*headA)->next->value &&
        (*headA)->next->value > (*headA)->next->next->value)
        {
            reverse(headA);
            if(!check_list_is_ordered(*headA))
                swap(headA);
        }
        */
    }
}
