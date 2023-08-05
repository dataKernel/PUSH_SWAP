/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_fuker_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:58:13 by data_kernel       #+#    #+#             */
/*   Updated: 2023/08/05 17:31:45 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack_utils.h"
#include "PRINTF/libft/libft.h"
#include <stdlib.h>

void	free_split_array(char **split_array)
{
	char	**to_free;

	to_free = split_array;
	while (*to_free)
	{
		free(*to_free);
		to_free++;
	}
	free(split_array);
}

void	ext_best_b(t_rotate_and_reverse *actual, t_index_and_value *mini)
{
	ft_memset(actual, 0, sizeof(t_rotate_and_reverse));
	(*mini).value = -1;
}

void	split_heada_headb_ext(t_node **head_a, t_node **head_b)
{
	while (size_list(*head_a) > 3)
	{
		push_b(head_a, head_b);
	}
	sort_three_elem(head_a);
}
