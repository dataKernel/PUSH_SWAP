/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func_base_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:24:14 by data_kernel       #+#    #+#             */
/*   Updated: 2023/08/03 02:35:55 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "include/stack_utils.h"
#include "PRINTF/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_element(t_node **head, t_node *elem)
{
	t_node	*first_elem;

	first_elem = *head;
	*head = elem;
	elem->next = first_elem;
}

void	rotate_a(t_node **headA)
{
	t_node	*old_head;
	t_node	*position;

	if (!(*headA)->state)
		ft_printf("ra\n");
	if (headA == NULL || *headA == NULL)
		return ;
	old_head = *headA;
	*headA = (*headA)->next;
	position = *headA;
	while (position)
	{
		if (position->next == NULL)
		{
			position->next = old_head;
			old_head->next = NULL;
		}
		position = position->next;
	}
}

void rotate(t_node **headA)
{
	t_node *old_head;
	t_node *position;

	if (headA == NULL || *headA == NULL)
		return;
	old_head = *headA;
	*headA = (*headA)->next;
	position = *headA;
	while (position)
	{
		if (position->next == NULL)
		{
			position->next = old_head;
			old_head->next = NULL;
		}
		position = position->next;
	}
}

void	rotate_b(t_node **headB)
{
	t_node	*old_head;
	t_node	*position;

	if (!(*headB)->state)
		ft_printf("rb\n");
	if (headB == NULL || *headB == NULL)
		return ;
	old_head = *headB;
	*headB = (*headB)->next;
	position = *headB;
	while (position)
	{
		if (position->next == NULL)
		{
			position->next = old_head;
			old_head->next = NULL;
		}
		position = position->next;
	}
}
