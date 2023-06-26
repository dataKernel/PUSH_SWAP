#include "include/stack.h"
#include "include/stack_utils.h"

// inclusions pour read()
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	func_choice(t_node **headA, t_node **headB)
{

}

int 	size_list(t_node **head)
{
	t_node	*tempHead;
	int		size;

	if (*head == NULL)
		return (0);
	size = 0;
	while (*head)
	{
		*head = (*head)->next;
		size++;
	}
	return (size);
}
