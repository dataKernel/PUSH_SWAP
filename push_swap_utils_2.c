#include "include/stack.h"
#include "include/stack_utils.h"

void	free_list(t_node *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
}