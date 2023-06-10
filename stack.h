#ifndef STACK_H
# define STACK_H

typedef struct      s_node
{
    int             value;
    struct s_node   *next; 
}t_node;

t_node  *create_node(int value);
void    push(t_node **head, t_node *elem);

void    push_a(t_node **headA, t_node **headB, t_node *elem);

#endif