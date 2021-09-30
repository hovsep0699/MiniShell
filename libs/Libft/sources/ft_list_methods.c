#include "clist.h"

void ft_list_push_back(list_t *self, void *data, int size)
{
	node_t *tmp;
	
	tmp = ft_node_constructor(data, size);
	self->end->insert_before(self->end, tmp);
	if (self->size == 0)
		self->begin = tmp;
	++self->size;
}

// bool ft_list_iscontain(list_t *lst, int data, int size)
// {
// 	node_t *it;

// 	it = lst->begin;
// 	while (it != lst->end)
// 	{
// 		if (it->data.value == data.value)
// 			return (true);
// 		it = it->next;
// 	}
// 	return (false);
// }

void ft_list_push_front(list_t *self, void *data, int size)
{
	node_t *tmp;
	
	tmp = ft_node_constructor(data, size);
	if (self->size == 0)
		self->end->insert_before(self->end, tmp);
	else
		self->begin->insert_before(self->begin, tmp);
	self->begin = tmp;
	++self->size;
}

void ft_list_pop_front(list_t *self)
{
	node_t *tmp;

	if (self->size == 1)
	{
		ft_node_destructor(self->begin);
		self->begin = self->end;
		self->end->previous = NULL;
	}
	else if(self->size > 1)
	{
		tmp = self->begin->next;
		self->begin->disconnect(self->begin);
		ft_node_destructor(self->begin);
		self->begin = tmp;
	}
	--self->size;
}
void	ft_list_pop_back(list_t *self)
{
	node_t *it;

	if (self->size == 1)
		self->pop_front(self);
	else if (self->size > 1)
	{
		it = self->end->previous;
		self->end->previous->disconnect(self->end->previous);
		ft_node_destructor(it);
		--self->size;
	}
}




















