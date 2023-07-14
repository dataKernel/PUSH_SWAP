#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>

int	get_best_B_to_insert(t_node *head_a, t_node *headB, int actualIndex)
{
	t_rotate_and_reverse	actual;
	t_index_and_value		mini;
	int						indert_index;
	int						nb_insert;
	int						i;

	memset(&actual, 0, sizeof(t_rotate_and_reverse));
	i = 0;
	mini.value = -1;
	while (headB)
	{
		indert_index = check_index_insert(head_a, headB->value);
		actual.rotate_a = check_nbr_rotate(head_a, actualIndex, indert_index);
		actual.reverse_a = check_nbr_reverse(head_a, actualIndex, indert_index);
		nb_insert = min(max(actual.rotate_a, actual.rotate_b), max(actual.reverse_a,
				actual.reverse_b));
		if (mini.value == -1 || nb_insert < mini.value)
		{
			mini.value = nb_insert;
			mini.index = i;
		}
		headB = headB->next;
		actual.rotate_b++;
		actual.reverse_b = size_list(headB);
	}
	return (mini.index);
}

void	insert_rotate(t_node **head_a, t_node **headB,
		t_rotate_and_reverse actual)
{
	int	i;

	i = 0;
	while (i < min(actual.rotateA, actual.rotateB))
	{
		rotate_all(head_a, headB);
		i++;
	}
	i = 0;
	if (actual.rotateA > actual.rotateB)
	{
		while (i++ < actual.rotateA - actual.rotateB)
			rotate_a(head_a);
	}
	i = 0;
	if (actual.rotateA < actual.rotateB)
	{
		while (i++ < actual.rotateB - actual.rotateA)
			rotate_a(headB);
	}
	push_a(headB, head_a);
}

void	insert_reverse(t_node **head_a, t_node **headB,
		t_rotate_and_reverse actual)
{
	int	i;

	i = 0;
	while (i < min(actual.reverseA, actual.reverseB))
	{
		reverse_all(head_a, headB);
		i++;
	}
	i = 0;
	if (actual.reverseA > actual.reverseB)
	{
		while (i++ < actual.reverseA - actual.reverseB)
			reverse(head_a);
	}
	i = 0;
	if (actual.reverseA < actual.reverseB)
	{
		while (i++ < actual.reverseB - actual.reverseA)
			reverse(headB);
	}
	push_a(headB, head_a);
}

void	insert_one(t_node **head_a, t_node **headB, int actualIndex, int indexB)
{
	t_rotate_and_reverse	actual;
	t_node					*currentB;
	int						i;

	i = 0;
	currentB = *headB;
	while (i < indexB)
	{
		currentB = currentB->next;
		i++;
	}
	actual.rotateA = check_nbr_rotate(*head_a, actualIndex,
		check_index_insert(*head_a, currentB->value));
	actual.reverseA = check_nbr_reverse(*head_a, actualIndex,
		check_index_insert(*head_a, currentB->value));
	actual.rotateB = indexB;
	actual.reverseB = (size_list(*headB) - indexB) % size_list(*headB);
	if (max(actual.rotateA, actual.rotateB) < max(actual.reverseA,
			actual.reverseB))
	{
		insert_rotate(head_a, headB, actual);
	}
	else
	{
		insert_reverse(head_a, headB, actual);
	}
}

void	insertion_into_headA(t_node **head_a, t_node **headB)
{
	int actualIndex;
	int indexB;
	int rotate_count;
	int reverse_count;
	int i;

	actualIndex = 0;
	while (*headB)
	{
		indexB = get_best_B_to_insert(*head_a, *headB, actualIndex);
		insert_one(head_a, headB, actualIndex, indexB);
		actualIndex = check_index_insert(*head_a, (*head_a)->value);
		show_results(*head_a, *headB);
	}
	rotate_count = check_nbr_rotate(*head_a, actualIndex, 0);
	reverse_count = check_nbr_reverse(*head_a, actualIndex, 0);
	i = 0;
	if (rotate_count < reverse_count)
	{
		while (i < rotate_count)
		{
			rotate_a(head_a);
			i++;
		}
	}
	else
	{
		while (i < reverse_count)
		{
			reverse(headB);
			i++;
		}
	}
	show_results(*head_a, *headB);
}