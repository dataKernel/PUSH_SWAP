/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:00:25 by data_kernel       #+#    #+#             */
/*   Updated: 2023/07/30 19:46:56 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "PRINTF/ft_printf.h"
#include "include/stack_utils.h"
#include <stdio.h>

void	push_a(t_node **headB, t_node **headA)
{
	t_node	*first_element;
	t_node	*next_element;

	ft_printf("pa\n");
	if (headB == NULL || *headB == NULL)
		return ;
	first_element = *headA;
	next_element = (*headB)->next;
	*headA = *headB;
	(*headA)->next = first_element;
	*headB = next_element;
}

void	push_b(t_node **headA, t_node **headB)
{
	t_node	*first_element;
	t_node	*next_element;

	ft_printf("pb\n");
	if (headA == NULL || *headA == NULL)
		return ;
	first_element = *headB;
	next_element = (*headA)->next;
	*headB = *headA;
	(*headB)->next = first_element;
	*headA = next_element;
}

void	swap_a(t_node **headA, bool copy)
{
	t_node	*old_head;

	if (!copy)
		ft_printf("sa\n");
	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return ;
	old_head = *headA;
	*headA = (*headA)->next;
	old_head->next = (*headA)->next;
	(*headA)->next = old_head;
}

void	swap_b(t_node **headB)
{
	t_node	*old_head;

	ft_printf("sb\n");
	if (headB == NULL || *headB == NULL || (*headB)->next == NULL)
		return ;
	old_head = *headB;
	*headB = (*headB)->next;
	old_head->next = (*headB)->next;
	(*headB)->next = old_head;
}

void	swap_all(t_node **headA, t_node **headB)
{
	ft_printf("ss\n");
	swap_a(headA, false);
	swap_b(headB);
}
