/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:31:40 by data_kernel       #+#    #+#             */
/*   Updated: 2023/08/03 00:43:02 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdlib.h>
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

int	check_nbr_rotate(t_node *head_a, int actual_index, int insert_index)
{
	int	res;

	res = (insert_index - actual_index) % size_list(head_a);
	if (res < 0)
		res += size_list(head_a);
	return (res);
}

int	check_nbr_reverse(t_node *head_a, int actual_index, int insert_index)
{
	int	res;

	res = (actual_index - insert_index) % size_list(head_a);
	if (res < 0)
		res += size_list(head_a);
	return (res);
}

int	count_rr_or_rrr(int a, int b)
{
	int	count;

	if (a == 0 || b == 0)
		return (0);
	count = 0;
	while ((a - b) > 0 || a > 0)
	{
		count++;
		a--;
	}
	return (count);
}

void	split_heada_and_headb(t_node **head_a, t_node **head_b)
{
	t_array_drop	data_array;
	int				i;
	int				j;

	i = 0;
	j = size_list(*head_a);
	if (head_a == NULL || *head_a == NULL)
		return ;
	data_array = get_tab_elems_drop(*head_a, size_list(*head_a));
	if((size_list(*head_a) - data_array.size_array) > 3)
	{
		while(j > 0)
		{
			if(data_array.array[i] == (*head_a)->value)
			{
				push_b(head_a, head_b);
				i++;
			}
			else
				rotate_a(head_a);
			j--;
		}
	}
	else
	{
		while (size_list(*head_a) > 3)
		{
			push_b(head_a, head_b);
		}
		sort_three_elem(head_a);
	}
}
