#include "clist.h"

node_t	*ft_node_default_constructor()
{
	node_t *node;

	node = ft_memalloc(sizeof(node_t));
	node->next = NULL;
	node->previous = NULL;
	node->insert_after = node_insert_after;
	node->insert_before = node_insert_before;
	node->swap = node_swap;
	node->reverse = node_reverse;
	node->disconnect = ft_node_disconnect;
	return node;
}

node_t *ft_node_copy_constructor(node_t *node)
{
	node_t *self;

	self = ft_node_default_constructor();
	self->next = node->next;
	self->previous = node->previous;
	self->insert_after = node_insert_after;
	self->insert_before = node_insert_before;
	self->swap = node_swap;
	self->reverse = node_reverse;
	self->disconnect = ft_node_disconnect;
	return self;
}

node_t *ft_node_constructor(element_t data)
{
	node_t *node;

	node = ft_memalloc(sizeof(node_t));
	node->next = NULL;
	node->previous = NULL;
	node->data = data;
	node->insert_after = node_insert_after;
	node->insert_before = node_insert_before;
	node->swap = node_swap;
	node->reverse = node_reverse;
	node->disconnect = ft_node_disconnect;
	return node;
}

list_t	ft_list_default_constructor()
{
	list_t list;

	list.begin = ft_node_default_constructor();
	list.end = ft_node_default_constructor();
	list.size = 0;
	list.push_back = ft_list_push_back;
	list.push_front = ft_list_push_front;
	list.pop_front = ft_list_pop_front;
	list.pop_back = ft_list_pop_back;
	list.advance = ft_list_iterator_advance;
	list.erase = ft_list_erase;
	list.erase_between = ft_list_erase_between;
	return list;
}

list_t	ft_list_copy_constructor(const list_t *list)
{
	list_t self;
	node_t *it;

	self = ft_list_default_constructor();
	it = list->begin;
	while (it != list->end)
	{
		self.push_back(&self, it->data);
		it = list->advance(it, 1);
	}
	return self;
}

