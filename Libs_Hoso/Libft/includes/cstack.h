#ifndef CSTACK_H
#define CSTACK_H

#include "clist.h"

typedef struct stack Stack;

struct stack
{
	list_t data;
	int		size;
	node_t *(*top)(Stack st);
	void	(*push)(Stack *st, element_t data);
	node_t	*(*pop)(Stack *st);
	bool	(*contains)(Stack *st, element_t data);
	void	(*sort)(element_t *arr, int low, int high);
};

Stack	ft_stack_default_constructor();

Stack	ft_stack_array_constructor(element_t *arr, int size);

void	ft_stack_push(Stack *st, element_t data);

node_t	*ft_stack_pop(Stack *st);

node_t	*ft_stack_top(Stack st);

Stack   ft_stack_copy_constructor(const Stack *st);

void	ft_stack_destructor(Stack *st);

bool	ft_stack_iscontain(Stack *st, element_t elem);

int 	ft_partition(element_t *arr, int low, int high);

void	ft_quickSort(element_t *arr, int low, int high);

#endif
