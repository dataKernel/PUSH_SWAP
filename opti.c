/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: data_kernel <data_kernel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:29:09 by data_kernel       #+#    #+#             */
/*   Updated: 2023/08/05 16:44:39 by data_kernel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
#include <stdlib.h>

t_array_drop	get_tab_elems_drop_optim(t_node *head_a, int size_list)
{
	t_array_drop	tmp;
	t_array_drop	max;
	int				i;

	i = 1;
	max = get_tab_elems_drop_from_index(head_a, size_list, 0);
	while (i < size_list)
	{
		tmp = get_tab_elems_drop_from_index(head_a, size_list, i);
		if (tmp.size_array < max.size_array)
		{
			free(max.array);
			max = tmp;
		}
		else
		{
			free(tmp.array);
		}
		i++;
	}
	return (max);
}

t_array_drop	get_tab_elems_drop_from_index(t_node *head_a, int size_list,
		int index)
{
	t_array_drop	data_array;
	int				max;
	int				i;

	i = 0;
	data_array.array = (int *)malloc(sizeof(int *) * size_list);
	while (i < index)
	{
		data_array.array[i++] = head_a->value;
		head_a = head_a->next;
	}
	max = head_a->value;
	while ((size_list--) - index > 1)
	{
		if (max < head_a->next->value)
			max = head_a->next->value;
		if (max > head_a->next->value)
		{
			data_array.array[i] = head_a->next->value;
			i++;
		}
		head_a = head_a->next;
	}
	data_array.size_array = i;
	return (data_array);
}

t_array_drop	get_tab_elems_drop(t_node *head_a, int size_list)
{
	t_array_drop	data_array;
	int				max;
	int				i;

	i = 0;
	max = head_a->value;
	data_array.array = (int *)malloc(sizeof(int *) * size_list);
	while (size_list > 1)
	{
		if (max < head_a->next->value)
			max = head_a->next->value;
		if (max > head_a->next->value)
		{
			data_array.array[i] = head_a->next->value;
			i++;
		}
		size_list--;
		head_a = head_a->next;
	}
	data_array.size_array = i;
	return (data_array);
}
>>>>>>> 67496ee3fc9f99d6bdc19ff04e32d79a6995de67
