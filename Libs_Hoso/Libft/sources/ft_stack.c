#include "cstack.h"

bool ft_stack_iscontain(Stack *st, element_t data)
{
	Stack s;
	node_t *it;

	s = ft_stack_copy_constructor(st);
	while ((it = s.pop(&s)))
	{
		if (it->data.value == data.value)
			return (true);
	}
	ft_stack_destructor(&s);
	return (false);
}

void ft_stack_push(Stack *st, element_t data)
{
	st->data.push_front(&st->data, data);
	st->size = st->data.size;
}

node_t *ft_stack_pop(Stack *st)
{
	node_t *it;

	it = st->data.begin;
	st->data.pop_front(&st->data);
	st->size = st->data.size;
	if (it != st->data.end)
		return it;
	return NULL;
}

node_t *ft_stack_top(Stack st)
{
	return st.data.begin;
}


void	ft_stack_destructor(Stack *st)
{
	ft_list_destructor(&st->data);
}

Stack ft_stack_default_constructor()
{
	Stack st;

	st.data = ft_list_default_constructor();
	st.size = 0;
	st.push = ft_stack_push;
	st.pop = ft_stack_pop;
	st.top = ft_stack_top;
	st.contains = ft_stack_iscontain;
	st.sort = ft_quickSort;
	return st;
}

Stack ft_stack_copy_constructor(const Stack *st)
{
	Stack	copy;
	node_t	*it;

	copy.data = ft_list_default_constructor();
	copy.size = 0;
	copy.push = ft_stack_push;
	copy.pop = ft_stack_pop;
	copy.top = ft_stack_top;
	copy.contains = ft_stack_iscontain;
	copy.sort = ft_quickSort;
	it = st->data.end->previous;
	while (it)
	{
		copy.push(&copy, it->data);
		it = st->data.advance(it, -1);
	}
	return copy;
}


Stack ft_stack_array_constructor(element_t *arr, int size)
{
	Stack st;
	int index;

	index = size;
	st = ft_stack_default_constructor();
	while (--index >= 0)
		st.push(&st, arr[index]);
	return st;
}

