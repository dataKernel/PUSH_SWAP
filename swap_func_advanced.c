/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func_advanced.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:18:32 by data_kernel       #+#    #+#             */
/*   Updated: 2023/08/05 16:24:21 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "PRINTF/ft_printf.h"
#include <stdio.h>

void	reverse_a(t_node **head)
{
	t_node	*old_head;
	t_node	*position;

	ft_printf("rra\n");
	if (head == NULL || *head == NULL)
		return ;
	old_head = *head;
	position = *head;
	while (position)
	{
		if (position->next->next == NULL)
		{
			*head = position->next;
			position->next = NULL;
			(*head)->next = old_head;
		}
		position = position->next;
	}
}

void	reverse(t_node **head)
{
	t_node	*old_head;
	t_node	*position;

	if (head == NULL || *head == NULL)
		return ;
	old_head = *head;
	position = *head;
	while (position)
	{
		if (position->next->next == NULL)
		{
			*head = position->next;
			position->next = NULL;
			(*head)->next = old_head;
		}
		position = position->next;
	}
}

void	reverse_b(t_node **head)
{
	t_node	*old_head;
	t_node	*position;

	ft_printf("rrb\n");
	if (head == NULL || *head == NULL)
		return ;
	old_head = *head;
	position = *head;
	while (position)
	{
		if (position->next->next == NULL)
		{
			*head = position->next;
			position->next = NULL;
			(*head)->next = old_head;
		}
		position = position->next;
	}
}

void	reverse_all(t_node **headA, t_node **headB)
{
	ft_printf("rrr\n");
	reverse(headA);
	reverse(headB);
}

void	rotate_all(t_node **headA, t_node **headB)
{
	ft_printf("rr\n");
	rotate(headA);
	rotate(headB);
}
