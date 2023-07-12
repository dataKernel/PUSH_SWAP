#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>

int		get_best_B_to_insert(t_node *headA, t_node *headB, int actualIndex)
{
	t_rotate_and_reverse actual;
	t_index_and_value mini;
	int insertIndex;
	int nbInsert;
	int i;
	
	memset(&actual, 0, sizeof(t_rotate_and_reverse));
	i = 0;
	mini.value = -1;
	while(headB)
	{
		insertIndex = check_index_insert(headA, headB -> value);
		actual.rotateA = check_nbr_rotate(headA, actualIndex, insertIndex);
		actual.reverseA = check_nbr_reverse(headA, actualIndex, insertIndex);
		nbInsert = min(max(actual.rotateA, actual.rotateB), max(actual.reverseA, actual.reverseB));
		if (mini.value == -1 || nbInsert < mini.value)
		{
			mini.value = nbInsert;
			mini.index = i;
		}
		headB = headB -> next;
		actual.rotateB ++;
		actual.reverseB = size_list(headB);
	}
	return mini.index;
}

void insert_rotate(t_node **headA, t_node **headB, t_rotate_and_reverse actual){
	int i;

	i = 0;
	while(i < min(actual.rotateA, actual.rotateB))
	{
		rotate_all(headA, headB);
		i ++;
	}
	i = 0;
	if (actual.rotateA > actual.rotateB)
	{
		while(i++ < actual.rotateA - actual.rotateB)
			rotate(headA);
	}
	i = 0;
	if (actual.rotateA < actual.rotateB)
	{
		while(i++ < actual.rotateB - actual.rotateA)
			rotate(headB);
	}
	push_a(headB, headA);
}

void insert_reverse(t_node **headA, t_node **headB, t_rotate_and_reverse actual){
	int i;

	i = 0;
	while(i < min(actual.reverseA, actual.reverseB))
	{
		reverse_all(headA, headB);
		i ++;
	}
	i = 0;
	if (actual.reverseA > actual.reverseB)
	{
		while(i++ < actual.reverseA - actual.reverseB)
			reverse(headA);
	}
	i = 0;
	if (actual.reverseA < actual.reverseB)
	{
		while(i++ < actual.reverseB - actual.reverseA)
			reverse(headB);
	}
	push_a(headB, headA);
}

void insert_one(t_node **headA, t_node **headB, int actualIndex, int indexB){
	t_rotate_and_reverse actual;
	t_node *currentB;
	int i;

	i = 0;
	currentB = *headB;
	while (i < indexB)
	{
		currentB = currentB -> next;
		i++;
	}
	actual.rotateA = check_nbr_rotate(*headA, actualIndex,  check_index_insert(*headA, currentB -> value));
	actual.reverseA = check_nbr_reverse(*headA, actualIndex, check_index_insert(*headA, currentB -> value));

	actual.rotateB = indexB;
	actual.reverseB = (size_list(*headB) - indexB) % size_list(*headB);
	if (max(actual.rotateA, actual.rotateB) < max(actual.reverseA, actual.reverseB))
	{
		insert_rotate(headA, headB, actual);

	}
	else{
		insert_reverse(headA, headB, actual);
	}
}

void	insertion_into_headA(t_node **headA, t_node **headB)
{
	int 	actualIndex;
	int		indexB;
	int		rotate_count;
	int		reverse_count;
	int 	i;

	actualIndex = 0;
	while(*headB)
	{
		indexB = get_best_B_to_insert(*headA, *headB, actualIndex);
		insert_one(headA, headB, actualIndex, indexB);
		actualIndex = check_index_insert(*headA, (*headA) -> value);
		show_results(*headA, *headB);
	}
	rotate_count = check_nbr_rotate(*headA, actualIndex, 0);
	reverse_count = check_nbr_reverse(*headA, actualIndex, 0);
	i = 0;
	if (rotate_count < reverse_count)
	{
		while(i < rotate_count)
		{
			rotate(headA);
			i++;
		}
	}
	else
	{
		while(i < reverse_count)
		{
			reverse(headB);
			i++;
		}
	}
	show_results(*headA, *headB);
}