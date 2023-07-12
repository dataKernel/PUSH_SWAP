###VARS###
NAME 	= 	push_swap
FLAGS 	=	 
CC 		= 	gcc
OBJS	= 	libft_utils.c push_swap_insertions.c push_swap_utils.c \
			push_swap_utils_2.c push_swap.c swap_func_advanced.c \
			swap_func_base.c function_utils.c
###RULES###
all: $(NAME)

fclean: find . -type f -name '*.o' -delete

push_swap: $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

###SRC###
push_swap.o: push_swap.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) push_swap.c -c -o push_swap.o

push_swap_insertions.o: push_swap_insertions.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) push_swap_insertions.c -c -o push_swap_insertions.o

push_swap_func_base.o: push_swap_func_base.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) push_swap_func_base.c -c -o push_swap_func_base.o

push_swap_func_advanced.o: push_swap_func_advanced.c include/stack.h include/stack_advanced.h
	$(CC) $(FLAGS) push_swap_func_advanced.c -c -o push_swap_func_advanced.o

function_utils.o : function_utils.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) function_utils.c -c -o function_utils.o

qqqqmmmpush_swap_utils.o: push_swap_utils.c include/stack.h include/stack_advanced.h
	$(CC) $(FLAGS) push_swap_utils.c -c -o push_swap_utils.o

push_swap_utils_2.o: push_swap_utils_2.c include/stack.h include/stack_advanced.h
	$(CC) $(FLAGS) push_swap_utils_2.c -c -o push_swap_utils_2.o

libft_utils.o: libft_utils.c include/stack.h
	$(CC) $(FLAGS) libft_utils.c -c -o libft_utils.o