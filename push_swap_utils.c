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

int		count_rr_or_rrr(int a, int b)
{
	int		count;
	
	if(a == 0 || b == 0)
		return(0);
	count = 0;
	while((a - b) > 0 || a > 0)
	{
		count++;
		a--;
	}
	return(count);
}

void	split_headA_and_headB(t_node **headA, t_node **headB)
{
	if(headA == NULL || *headA == NULL)
		return;
	while (size_list(*headA) > 3)
	{
		push_a(headA, headB);
	}
	sort_three_elem(headA);
}