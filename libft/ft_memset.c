#include "libft.h"

/*
*A Funcao Que Copia Para Um Array,
*Caracter Identificado Por (int c)
*Delimitado O Numero De Copia Por (size_t len).
*/

void    *ft_memset(void *str, int c, size_t len)
{
    unsigned int counter;
    unsigned char *memory;

    counter = 0;
    memory = str;
    while (len > counter)                    
    {
        memory[counter] = c;
        counter++;
    }
    return (memory);
}