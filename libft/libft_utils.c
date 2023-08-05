/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:22:56 by data_kernel       #+#    #+#             */
/*   Updated: 2023/08/05 16:46:13 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"
#include "../PRINTF/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	test_str(char c, char *str)
{
	while (*str != '\0')
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	tmp_result;
	int		result;
	int		check;

	result = 0;
	check = 1;
	while (test_str(*str, "\t\n\v\f\r "))
		str++;
	if (test_str(*str, "-+"))
		if (*str++ == '-')
			check = -1;
	while (*str >= '0' && *str <= '9')
	{
		tmp_result = ((long)(result)) * 10 + ((long)(*str - '0'));
		if ((check == 1 && tmp_result >= 2147483648) || 
			tmp_result >= 2147483649)
		{
			ft_printf("Error\n");
			exit(0);
		}
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * check);
}

bool	check_doublons(t_node *head_a)
{
	t_node	*i;

	while (head_a)
	{
		i = head_a->next;
		while (i)
		{
			if (head_a->value == i->value)
				return (true);
			i = i->next;
		}
		head_a = head_a->next;
	}
	return (false);
}

bool	check_list_is_ordered(t_node *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
}

void	show_results(t_node *headA, t_node *headB)
{
	int	i;

	ft_printf("===========================================\n");
	ft_printf("--------STACK_A-------|\n");
	i = 1;
	while (headA)
	{
		ft_printf("Element(A)[%i]->%i      |\n", i, headA->value);
		headA = headA->next;
		i++;
	}
	ft_printf("----------------------|\n\n");
	ft_printf("--------STACK_B-------|\n");
	i = 1;
	while (headB)
	{
		ft_printf("Element(B)[%i]->%i      |\n", i, headB->value);
		headB = headB->next;
		i++;
	}
	ft_printf("----------------------|\n");
	ft_printf("============================================\n\n");
}
