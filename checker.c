#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	// heads definitions
	t_node *headA;
	t_node *headB;
	char buffer;
	char tabFuncOptions[4];
	int i;

	headA = NULL;
	headB = NULL;
	i = 0;
	// protection des arguments via main
	if (argc <= 1)
		return (-1);
	init_list(&headA, argc, argv);
	show_results(headA, headB);

	show_results(headA, headB);
	return (0);
}