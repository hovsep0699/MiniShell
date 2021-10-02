#include "clist.h"

#include <stdio.h>
void	ft_node_destructor(node_t *self)
{
	ft_memdel((void **)&self->data);
	ft_memdel((void **)&self);
}

void	ft_list_destructor(list_t *self)
{
	if (self->size)
	{
		while (self->begin != self->end)
		{
			printf("%d\n", self->size);
			self->pop_back(self);
		}
	}
	else
		ft_node_destructor(self->begin);
	ft_node_destructor(self->end);
}

