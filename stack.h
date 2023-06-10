#ifndef STACK_H
# define STACK_H

typedef struct      s_node
{
    int             value;
    struct s_node   *next; 
}t_node;

t_node  *create_node(int value);
void    push(t_node **head, t_node *node);

#endif