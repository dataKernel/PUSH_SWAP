#include "include/stack.h"
#include "include/stack_utils.h"
#include <stdio.h>
// inclusions pour read()
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

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
	printf("STATE INIT\n----------------\n");
	show_results(headA, headB);
	printf("your choice:\n");
	while (buffer != END_OF_FILE)
	{
		read(0, &buffer, 1);
		if ((buffer != END_OF_LINE && buffer != END_OF_FILE) && i < 4)
		{
			tabFuncOptions[i] = buffer;
			i++;
		}
		else
		{
			tabFuncOptions[i] = '\0';
			if(!ft_strncmp(tabFuncOptions, "sa", 3))
				swap(&headA);
			else if(!ft_strncmp(tabFuncOptions, "sb", 3))
				swap(&headB);
			else
			{
				printf("ERROR\n");
				return(-1);
			}
			i = 0;
		}
	}
	printf("AFTER STATE\n----------------\n");
	show_results(headA, headB);
	return (0);
}