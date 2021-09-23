#include "clist.h"

node_t *ft_list_iterator_advance(node_t *it, int dist)
{
	int index;
	int sign;

	if (!it)
		return NULL;
	index = 0;
	sign = (dist < 0) ? -1 : 1;
	while (it && index < sign * dist)
	{
		it = (dist < 0) ? it->previous : it->next;
		++index;
	}
	return (index == sign * dist) ? it : NULL;
}

node_t *ft_list_erase(list_t *self, node_t *it)
{
	node_t *next;

	if (it == self->begin)
	{
		self->pop_front(self);
		return (self->begin);
	}
	else if (it == self->end)
	{
		self->pop_back(self);
		return (self->end);
	}
	next = it->next;
	if (it)
		it->next = it->next->next;
	if (it->next->next)
		it->next = it;
	ft_memdel((void **)&it);
	--self->size;
	return next;
}

node_t	*ft_list_erase_between(list_t *self, node_t *start, node_t *end)
{
	while (start != end)
	{
		self->erase(self, start);
		start = self->advance(start, 1);
	}
	return start;
}

