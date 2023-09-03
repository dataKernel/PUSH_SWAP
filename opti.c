#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"
#include "include/stack_utils.h"

t_array_drop get_tab_elems_drop(t_node *head_a, int size_list)
{
    t_array_drop data_array;
    int max;
    int i;

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