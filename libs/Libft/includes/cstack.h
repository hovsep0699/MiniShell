#ifndef CSTACK_H
# define CSTACK_H

# include "clist.h"

typedef struct stack Stack;

struct stack
{
	list_t	data;
	int		size;
	node_t	*(*top)(Stack st);
	void	(*push)(Stack *st, void *data, int size);
	node_t	*(*pop)(Stack *st);

};

Stack	ft_stack_default_constructor();

void	ft_stack_push(Stack *st, void *data, int size);

node_t	*ft_stack_pop(Stack *st);

node_t	*ft_stack_top(Stack st);

Stack   ft_stack_copy_constructor(const Stack *st);

void	ft_stack_destructor(Stack *st);

#endif
