#include "variable_array.h"

int main()
{
    Array arr1 = array_create(4);
    int number;
    int counter = 0;
    printf("****This is the resizable array****\n");
    printf("press number -1 to show the array\n");

    while (number != -1)
    {
        printf("please enter an element:\n");
        scanf("%d", &number);
        if (number != -1)
        {
            *array_at(&arr1, counter++) = number;
        }
        else
        {   
            printf("Array: ");
            for (int i = 0; i < counter; i++)
            {   
                printf("%d ", *array_at(&arr1, i));
            }
            break;
        }
    }
    array_free(&arr1);
}