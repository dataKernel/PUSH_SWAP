/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func_advanced.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:18:32 by data_kernel       #+#    #+#             */
/*   Updated: 2023/07/13 18:39:48 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include <stdio.h>

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

void	reverse_all(t_node **headA, t_node **headB)
{
	reverse(headA);
	reverse(headB);
}

void	rotate_all(t_node **headA, t_node **headB)
{
	if (headA != NULL || *headA != NULL || (*headA)->next != NULL)
		rotate_a(headA);
	if (headB != NULL || *headB != NULL || (*headB)->next != NULL)
		rotate_b(headB);
}
