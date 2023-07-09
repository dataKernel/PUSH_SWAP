#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
#include <stdlib.h>

void	check_best_operation(t_node *headA, t_node *headB, int actualIndex, int insertIndex)
{
	int		sizeList;
	int		nbrRotateA;
	int		nbrReverseA;
	int		nbrRotateB;
	int		i;
	//on va avancer dans la headB pr check tout les elements
	i = 0;
	sizeList = size_list(headB);
	nbrRotateA = check_nbr_rotate(headA, actualIndex, insertIndex);
	nbrReverseA = check_nbr_reverse(headA, actualIndex, insertIndex);
	nbrRotateB = 0;
	while(headB)
	{
		nbrRotateA -= count_rr_or_rrr(nbrRotateA, nbrRotateB);
		while( i < nbrRotateA)
		{
			rotate(headA);
			i++;
		}
		while(i < nbrRotateB)
		{
			rotate(headB);
			i++;
		}
		while(i < count_rr_or_rrr(nbrRotateA, nbrRotateB))
		{
			rotate_all(headA, headB);
			i++;
		}
		headB = headB->next;
	}
}


void	free_list(t_node *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
}