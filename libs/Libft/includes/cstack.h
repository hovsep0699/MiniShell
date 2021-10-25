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

#endif
