#include "include/stack_utils.h"
#include "include/stack.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
	// heads definitions
	t_node  *headA;
	t_node  *headB;

	headA = NULL;
	headB = NULL;
    //protection des arguments via main
    if(argc <= 1)
        return(-1);
	init_list(&headA, argc, argv);
	show_results(&headA, &headB);
	return (0);
}