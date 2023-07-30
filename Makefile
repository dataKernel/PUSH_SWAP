###VARS###
NAME 	= 	push_swap
PRINTF	=	PRINTF/libftprintf.a
FLAGS 	=	-Wall -Wextra -Werror	 
CC 		= 	gcc
OBJS	= 	libft_utils.o push_swap_insertions.o push_swap_utils.o \
			push_swap_utils_2.o push_swap.o swap_func_advanced.o \
			swap_func_base.o swap_func_base_2.o function_choice.o \
			norm_fuker.o 
###RULES###
all: $(NAME)
clean:
	rm -f push_swap
fclean:
	rm -f push_swap
	find . -type f -name '*.o' -delete
push_swap: $(OBJS) $(PRINTF)
	$(CC) $(OBJS) -o $(NAME) $(PRINTF)

###SRC###
push_swap.o: push_swap.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) push_swap.c -c -o push_swap.o

push_swap_insertions.o: push_swap_insertions.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) push_swap_insertions.c -c -o push_swap_insertions.o

swap_func_base.o: swap_func_base.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) swap_func_base.c -c -o swap_func_base.o

swap_func_base_2.o: swap_func_base_2.c include/stack.h include/stack_utils.h 
	$(CC) $(FLAGS) swap_func_base_2.c -c -o swap_func_base_2.o

swap_func_advanced.o: swap_func_advanced.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) swap_func_advanced.c -c -o swap_func_advanced.o

function_choice.o : function_choice.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) function_choice.c -c -o function_choice.o

push_swap_utils.o: push_swap_utils.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) push_swap_utils.c -c -o push_swap_utils.o

push_swap_utils_2.o: push_swap_utils_2.c include/stack.h include/stack_utils.h
	$(CC) $(FLAGS) push_swap_utils_2.c -c -o push_swap_utils_2.o

libft_utils.o: libft/libft_utils.c include/stack.h
	$(CC) $(FLAGS) libft/libft_utils.c -c -o libft_utils.o

norm_fuker.o: norm_fuker.c include/stack.h
	$(CC) $(FLAGS) norm_fuker.c -c -o norm_fuker.o

###PRINT###
PRINTF/libftprintf.a:
	make -C PRINTF