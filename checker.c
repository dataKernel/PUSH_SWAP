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
	show_results(&headA, &headB);
	printf("your choice:\n");
	while (buffer != END_OF_FILE)
	{
		read(0, &buffer, 1);
		if ((buffer != END_OF_LINE && buffer != END_OF_FILE) || i > 3)
		{
			tabFuncOptions[i] = buffer;
			i++;
		}
		else
		{
			tabFuncOptions[i] = '\0';
			i = 0;
		}
	}
	printf("tab: %s\n", tabFuncOptions);
	if(!ft_strncmp(tabFuncOptions, "pa", 3))
		printf("same result");
	return (0);
}