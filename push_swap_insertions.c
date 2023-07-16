/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:24:09 by data_kernel       #+#    #+#             */
/*   Updated: 2023/07/16 08:50:16 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>

int	get_best_b_to_insert(t_node *head_a, t_node *head_b, int ind)
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
		actual.ra = check_nbr_rotate(head_a, ind, insert_index);
		actual.rra = check_nbr_reverse(head_a, ind, insert_index);
		nb_insert = min(max(actual.ra, actual.rb), max(actual.rra, actual.rrb));
		if (mini.value == -1 || nb_insert < mini.value)
		{
			mini.value = nb_insert;
			mini.index = i;
		}
		head_b = head_b->next;
		actual.rb++;
		actual.rrb = size_list(head_b);
	}
	return (mini.index);
}

void	insert_rotate(t_node **head_a, t_node **head_b, 
t_rotate_and_reverse actual)
{
	int	i;

	i = 0;
	while (i < min(actual.ra, actual.rb))
	{
		rotate_all(head_a, head_b);
		i++;
	}
	i = 0;
	if (actual.ra > actual.rb)
	{
		while (i++ < actual.ra - actual.rb)
			rotate_a(head_a);
	}
	i = 0;
	if (actual.ra < actual.rb)
	{
		while (i++ < actual.rb - actual.ra)
			rotate_b(head_b);
	}
	push_a(head_b, head_a);
}

void	insert_reverse(t_node **head_a, t_node **head_b,
		t_rotate_and_reverse actual)
{
	int	i;

	i = 0;
	while (i < min(actual.rra, actual.rrb))
	{
		reverse_all(head_a, head_b);
		i++;
	}
	i = 0;
	if (actual.rra > actual.rrb)
	{
		while (i++ < actual.rra - actual.rrb)
			reverse_a(head_a);
	}
	i = 0;
	if (actual.rra < actual.rrb)
	{
		while (i++ < actual.rrb - actual.rra)
			reverse_b(head_b);
	}
	push_a(head_b, head_a);
}

void	insert_one(t_node **head_a, t_node **head_b, int actual_index, 
int index_b)
{
	t_rotate_and_reverse	actual;
	t_node					*current_b;
	int						i;

	i = 0;
	current_b = *head_b;
	while (i < index_b)
	{
		current_b = current_b->next;
		i++;
	}
	actual.ra = check_nbr_rotate(*head_a, actual_index,
			check_index_insert(*head_a, current_b->value));
	actual.rra = check_nbr_reverse(*head_a, actual_index,
			check_index_insert(*head_a, current_b->value));
	actual.rb = index_b;
	actual.rrb = (size_list(*head_b) - index_b) % size_list(*head_b);
	if (max(actual.ra, actual.rb) < max(actual.rra, actual.rrb))
		insert_rotate(head_a, head_b, actual);
	else
		insert_reverse(head_a, head_b, actual);
}

void	insertion_into_head_a(t_node **head_a, t_node **head_b)
{
	int		actual_index;
	int		index_b;
	int		rotate_count;
	int		reverse_count;

	actual_index = 0;
	while (*head_b)
	{
		index_b = get_best_b_to_insert(*head_a, *head_b, actual_index);
		insert_one(head_a, head_b, actual_index, index_b);
		actual_index = check_index_insert(*head_a, (*head_a)->value);
	}
	rotate_count = check_nbr_rotate(*head_a, actual_index, 0);
	reverse_count = check_nbr_reverse(*head_a, actual_index, 0);
	insertion_ext(rotate_count, reverse_count, head_a, head_b);
}
