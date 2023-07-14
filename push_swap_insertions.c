#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>


int	get_best_B_to_insert(t_node *head_a, t_node *head_b, int ind)
{
	t_rotate_and_reverse	actual;
	t_index_and_value		mini;
	int						insert_index;
	int						nb_insert;
	int						i;

	memset(&actual, 0, sizeof(t_rotate_and_reverse));
	i = 0;
	mini.value = -1;
	while (head_b)
	{
		insert_index = check_index_insert(head_a, head_b->value);
		actual.rotate_a = check_nbr_rotate(head_a, ind, insert_index);
		actual.reverse_a = check_nbr_reverse(head_a, ind, insert_index);
		nb_insert = min(max(actual.rotate_a, actual.rotate_b),
				max(actual.reverse_a, actual.reverse_b));
		if (mini.value == -1 || nb_insert < mini.value)
		{
			mini.value = nb_insert;
			mini.index = i;
		}
		head_b = head_b->next;
		actual.rotate_b++;
		actual.reverse_b = size_list(head_b);
	}
	return (mini.index);
}

void	insert_rotate(t_node **head_a, t_node **head_b, 
t_rotate_and_reverse actual)
{
	int	i;

	i = 0;
	while (i < min(actual.rotate_a, actual.rotate_b))
	{
		rotate_all(head_a, head_b);
		i++;
	}
	i = 0;
	if (actual.rotate_a > actual.rotate_b)
	{
		while (i++ < actual.rotate_a - actual.rotate_b)
			rotate_a(head_a);
	}
	i = 0;
	if (actual.rotate_a < actual.rotate_b)
	{
		while (i++ < actual.rotate_b - actual.rotate_a)
			rotate_a(head_b);
	}
	push_a(head_b, head_a);
}

void	insert_reverse(t_node **head_a, t_node **head_b,
		t_rotate_and_reverse actual)
{
	int	i;

	i = 0;
	while (i < min(actual.reverse_a, actual.reverse_b))
	{
		reverse_all(head_a, head_b);
		i++;
	}
	i = 0;
	if (actual.reverse_a > actual.reverse_b)
	{
		while (i++ < actual.reverse_a - actual.reverse_b)
			reverse(head_a);
	}
	i = 0;
	if (actual.reverse_a < actual.reverse_b)
	{
		while (i++ < actual.reverse_b - actual.reverse_a)
			reverse(head_b);
	}
	push_a(head_b, head_a);
}

void	insert_one(t_node **head_a, t_node **head_b, int actual_index, int indexB)
{
	t_rotate_and_reverse	actual;
	t_node					*current_b;
	int						i;

	i = 0;
	current_b = *head_b;
	while (i < indexB)
	{
		current_b = current_b->next;
		i++;
	}
	actual.rotate_a = check_nbr_rotate(*head_a, actual_index,
			check_index_insert(*head_a, current_b->value));
	actual.reverse_a = check_nbr_reverse(*head_a, actual_index,
			check_index_insert(*head_a, current_b->value));
	actual.rotate_b = indexB;
	actual.reverse_b = (size_list(*head_b) - indexB) % size_list(*head_b);
	if (max(actual.rotate_a, actual.rotate_b) < max(actual.reverse_a,
			actual.reverse_b))
	{
		insert_rotate(head_a, head_b, actual);
	}
	else
	{
		insert_reverse(head_a, head_b, actual);
	}
}

void	insertion_into_headA(t_node **head_a, t_node **head_b)
{
	int actual_index;
	int indexB;
	int rotate_count;
	int reverse_count;
	int i;

	actual_index = 0;
	while (*head_b)
	{
		indexB = get_best_B_to_insert(*head_a, *head_b, actual_index);
		insert_one(head_a, head_b, actual_index, indexB);
		actual_index = check_index_insert(*head_a, (*head_a)->value);
		show_results(*head_a, *head_b);
	}
	rotate_count = check_nbr_rotate(*head_a, actual_index, 0);
	reverse_count = check_nbr_reverse(*head_a, actual_index, 0);
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
			reverse(head_b);
			i++;
		}
	}
	show_results(*head_a, *head_b);
}