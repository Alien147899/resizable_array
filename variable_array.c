
#include "variable_array.h"

Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*sizeof(a.size));
    return a;
}

void array_free(Array* a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

//Encapsulation 
int array_size(const Array* a)
{
    return a->size;
}

int* array_at(Array* a, int index)
{   
    if (index >= a->size)
    {
        array_inflate(a, 2);
    }
    return &(a->array[index]);
}

void array_inflate(Array* a , int more_size)
{
    int* more = (int*)malloc(sizeof(int)*(a->size + more_size));
    int i;
    for(i=0; i<a->size; i++)
    {
        more[i] = a->array[i];
    }
    free(a->array); //memory will be leaked if dont do this
    a->array = more;
    a->size += more_size;
}

