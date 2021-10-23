#ifndef CVECTOR_H
#define CVECTOR_H

#include "cstdlib.h"

typedef struct cvector cvector_t;

struct cvector
{
    void *data;
    size_t size;
    int    capacity;
};


cvector_t ft_cvector_default_constructor();

cvector_t ft_cvector_constructor(int elem_size, int size);

void    ft_cvector_destructor(cvector_t *cvec);


#endif
