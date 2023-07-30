/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:14:06 by data_kernel       #+#    #+#             */
/*   Updated: 2023/07/30 16:42:11 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
#include <stdlib.h>

t_node	*copy_head(t_node *head)
{
	t_node	*copy_head;
	t_node	*first_elem;
	t_node	*node;

	copy_head = create_node(head->value);
	first_elem = copy_head;
	head = head->next;
	while (head)
	{
		node = create_node(head->value);
		copy_head->next = node;
		copy_head = copy_head->next;
		head = head->next;
	}
	copy_head->next = NULL;
	copy_head = first_elem;
	return (copy_head);
}

void	sort_three_elem(t_node **headA)
{
	t_node	*copy_test_head;
	
	copy_test_head = copy_head(*headA);
	if (size_list(*headA) == 1)
		return ;
	else if (size_list(*headA) == 2)
	{
		if ((*headA)->value > (*headA)->next->value)
			swap_a(headA);
	}
	else
		sort_three_elem_ext(headA, copy_test_head);
	free_list(copy_test_head);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	free_list(t_node *head)
{
	t_node	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
