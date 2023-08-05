/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_choice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:48:51 by data_kernel       #+#    #+#             */
/*   Updated: 2023/08/05 16:49:41 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "PRINTF/libft/libft.h"
#include "include/stack_utils.h"

// inclusions pour read()
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void	func_choice_base(t_node **headA, t_node **headB, char *str)
{
	if (!ft_strncmp(str, "sa", 3))
		swap_a(headA, false);
	else if (!ft_strncmp(str, "sb", 3))
		swap_b(headB);
	else if (!ft_strncmp(str, "ss", 3))
		swap_all(headA, headB);
	else if (!ft_strncmp(str, "pa", 3))
		push_a(headB, headA);
	else if (!ft_strncmp(str, "pb", 3))
		push_b(headA, headB);
	else
		func_choice_advanced(headA, headB, str);
}

void	func_choice_advanced(t_node **headA, t_node **headB, char *str)
{
	if (!ft_strncmp(str, "ra", 3))
		rotate_a(headA);
	else if (!ft_strncmp(str, "rb", 3))
		rotate_b(headB);
	else if (!ft_strncmp(str, "rr", 3))
		rotate_all(headA, headB);
	else if (!ft_strncmp(str, "rra", 3))
		reverse_a(headA);
	else if (!ft_strncmp(str, "rrb", 3))
		reverse_b(headB);
	else if (!ft_strncmp(str, "rrr", 3))
		reverse_all(headA, headB);
	else
	{
		printf("Error\n");
		exit(1);
	}
}

void	exec_swap_func(t_node **headA, t_node **headB)
{
	char	choice[4];
	char	buffer;
	int		i;

	i = 0;
	printf("__choice__:\n");
	while (buffer != END_OF_FILE)
	{
		read(0, &buffer, 1);
		if (buffer != END_OF_LINE && buffer != END_OF_FILE && i < 4)
		{
			choice[i] = buffer;
			i++;
		}
		else
		{
			choice[i] = '\0';
			func_choice_base(headA, headB, choice);
			i = 0;
		}
	}
}
