#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
#include <stdlib.h>

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

void	truc(t_node **headA, t_node **headB, int actualIndex, int insertIndex)
{
	int	rotateResult;
	int	reverseResult;

	rotateResult = (insertIndex - actualIndex) % size_list(*headA);
	reverseResult = (actualIndex - insertIndex) % size_list(*headA);
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