#include "clist.h"

void node_insert_before(node_t *self, node_t *node)
{
	if (self->previous)
	{
		node->previous = self->previous;
		self->previous->next = node;
	}
	node->next = self;
	self->previous = node;
}

void node_insert_after(node_t *self, node_t *node)
{
	if (self->next)
	{
		node->next = self->next;
		self->next->previous = node;
	}
	node->previous = self;
	self->next = node;
}

void node_reverse(node_t *self)
{
	node_t *node;

	node = self->previous;
	self->previous = self->next;
	self->next = node;
}

void	node_swap(node_t *self, node_t *node)
{
	node_t *previous;
	node_t *next;

	if (self->next == node)
	{
		if (self->previous)
			self = node;
		node->previous = self->previous;
		self->previous = node;
		if (node->next)
			node = self;
		self->next = node->next;
		node->next = self;
	}
	else if (self->previous == node) {
		if (node->previous)
			node = self;
		self->previous = node->previous;
		node->previous = self;
		if (self->next)
			self = node;
		node->next = self->next;
		self->next = node;
	}
	else
	{
		previous = self->previous;
		next = self->next;
		if (self->previous)
			self = node;
		if (self->next)
			self = node;
		self->previous = node->previous;
		self->next = node->next;
		if (node->previous)
			node = self;
		if (node->next)
			node = self;
		node->previous = previous;
		node->next = next;
	}
}


void ft_node_disconnect(node_t *self)
{
	if (self->previous)
		self->previous->next = self->next;
	if (self->next)
		self->next->previous = self->previous;
}




