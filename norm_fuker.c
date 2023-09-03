/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_fuker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:23:23 by data_kernel       #+#    #+#             */
/*   Updated: 2023/08/05 19:27:33 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "include/stack_utils.h"

void	insertion_ext(int r, int rr, t_node **head_a)
{
	int	i;

	i = 0;
	if (r < rr)
	{
		while (i < r)
		{
			rotate_a(head_a);
			i++;
		}
	}
	else
	{
		while (i < rr)
		{
			reverse_a(head_a);
			i++;
		}
	}
}

void	sort_three_elem_ext(t_node **head_a, t_node *copy_test_head)
{
	if ((*head_a)->value > (*head_a)->next->value
		&& (*head_a)->next->value > (*head_a)->next->next->value)
	{
		rotate_a(head_a);
		swap_a(head_a, false);
	}
	else if ((*head_a)->value < (*head_a)->next->value
		&& (*head_a)->next->value > (*head_a)->next->next->value)
	{
		reverse_a(head_a);
		if (!check_list_is_ordered(*head_a))
			swap_a(head_a, false);
	}
	else if ((*head_a)->value > (*head_a)->next->value
		&& (*head_a)->next->value < (*head_a)->next->next->value)
	{
		swap_a(&copy_test_head, true);
		if (check_list_is_ordered(copy_test_head))
			swap_a(head_a, false);
		else
			rotate_a(head_a);
	}
}

int	min_max(int a, int b, int c, int d)
{
	int		nb_insert;

	nb_insert = min(max(a, b), max(c, d));
	return (nb_insert);
}

int	size_list(t_node *head)
{
	int		size;

	if (head == NULL)
		return (0);
	size = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}
