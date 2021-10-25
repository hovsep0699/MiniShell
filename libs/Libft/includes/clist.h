#ifndef CLIST_H
# define CLIST_H

# include <stdlib.h>
# include <unistd.h>
# include "cstring.h"
	
// #define getlistItem(node, type) *(type *)node->data

// #define list(lst) lst = ft_list_default_constructor()

typedef struct list list_t;

typedef struct node node_t;

typedef struct element	element_t;

struct node
{
	void		*data;
	node_t		*next;
	node_t		*previous;
	int			size;
	void		(*insert_before)(node_t *self, node_t *node);
	void		(*insert_after)(node_t *self, node_t *node);
	void		(*swap)(node_t *self, node_t *node);
	void		(*reverse)(node_t *self);
	void		(*disconnect)(node_t *node);
};;


struct		list
{
	node_t		*begin;
	node_t		*end;
	int			size;
	void		(*push_back)(list_t *lst, void *data, int size);
	void		(*push_front)(list_t *lst, void *data, int size);
	void		(*pop_front)(list_t *lst);
	void		(*pop_back)(list_t *lst);
	node_t		*(*advance)(node_t *it, int dist);
	node_t		*(*erase)(list_t *lst, node_t *it);
	node_t		*(*erase_between)(list_t *lst, node_t *start, node_t *end);
	
};

void				ft_node_disconnect(node_t *node);

node_t				*ft_list_iterator_advance(node_t *it, int dist);

int					ft_list_size(list_t *self);

list_t				ft_list_default_constructor();

list_t				ft_list_copy_constructor(const list_t *list);

void				ft_swap(void *a, void *b, size_t size);

#endif


