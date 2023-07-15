/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_fuker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:23:23 by data_kernel       #+#    #+#             */
/*   Updated: 2023/07/14 16:02:42 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "include/stack_utils.h"

void	insertion_ext(int rotate_count, int reverse_count, 
t_node **head_a, t_node **head_b)
{
	int	i;

	i = 0;
	if (rotate_count < reverse_count)
	{
		while (i < rotate_count)
		{
			rotate_a(head_a);
			i++;
		}
	}
	else
	{
		while (i < reverse_count)
		{
			reverse_b(head_b);
			i++;
		}
	}
}

int	min_max(int a, int b, int c, int d)
{
	int	nb_insert;

	nb_insert = min(max(a, b), max(c, d));
	return (nb_insert);
}
