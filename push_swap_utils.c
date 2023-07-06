#include <stdlib.h>
#include <stdio.h>
#include "include/stack.h"
#include "include/stack_utils.h"

int		check_index_insert(t_node *head, int value)
{
    int     index;

    index = 0;
    while(head)
    {
        if(head->value < value)
            index++;
        head = head->next;
    }
    return(index);
}

void	truc()
{
	int		res;

	
	return(res);
}

void	free_list(t_node *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
}

void	split_headA_and_headB(t_node **headA, t_node **headB)
{
	while (size_list(*headA) > 3)
	{
		push(headA, headB);
	}
	sort_three_elem(headA);
}