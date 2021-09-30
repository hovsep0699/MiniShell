#include "cvector.h"


cvector_t ft_cvector_constructor(int elem_size, int size)
{
    cvector_t cvector;

    cvector.capacity = size * 2;
    cvector.data = malloc(cvector.capacity * elem_size);
    cvector.size = size;
    return cvector;
}
cvector_t ft_cvector_default_constructor()
{
    cvector_t cvec;

    cvec.data = NULL;
    cvec.size = 0;
    cvec.capacity = 2;
    return cvec;
}
void ft_cvector_destructor(cvector_t *cvec)
{
    ft_memdel((void **)&cvec->data);
}