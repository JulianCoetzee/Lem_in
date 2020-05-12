
#include "lemin.h"

void    free_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        ft_strdel(&arr[i]);
        i++;
    }
    free(arr);
}