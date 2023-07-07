#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>

int	check_index_insert(t_node *head, int value)
{
	int	index;

	index = 0;
	while (head)
	{
		if (head->value < value)
			index++;
		head = head->next;
	}
	return (index);
}

int		check_nbr_rotate(t_node *headA, int actualIndex, int insertIndex) 
{
	int		res;

	res = (insertIndex - actualIndex) % size_list(headA);
	if(res < 0)
		res += size_list(headA);
	return(res);
}		

int		check_nbr_reverse(t_node *headA, int actualIndex, int insertIndex) 
{
	int		res;

	res = (actualIndex - insertIndex) % size_list(headA);
	if(res < 0)
		res += size_list(headA);
	return(res);
}

void	sort_list(t_node **headA, int actualIndex, int insertIndex)
{
	int	rotateResult;
	int	reverseResult;

	rotateResult = check_nbr_rotate(*headA, actualIndex, insertIndex);
	reverseResult = check_nbr_reverse(*headA, actualIndex, insertIndex);
	if (rotateResult < 0)
		rotateResult += size_list(*headA);
	if (reverseResult < 0)
		reverseResult += size_list(*headA);
	if (rotateResult < reverseResult)
	{
		while (rotateResult > 0)
		{
			rotate(headA);
			rotateResult--;
		}
	}
	else
	{
		while (reverseResult > 0)
		{
			reverse(headA);
			reverseResult--;
		}
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