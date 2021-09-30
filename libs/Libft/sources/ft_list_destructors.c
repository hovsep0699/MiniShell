#include "clist.h"

void	ft_node_destructor(node_t *self)
{
	ft_memdel((void **)&self->data);
	ft_memdel((void **)&self);
}

void	ft_list_destructor(list_t *self)
{
	while (self->begin != self->end && self->size)
		self->pop_back(self);
}

