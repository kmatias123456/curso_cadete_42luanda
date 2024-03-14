#include "libft.h"
/*
*A Funcao Que Aloca A Memoria Para Um Array
*E O Define Como Zero, Usando Malloc Para Alocacao
*E Usa O Memset Para O Definir Esplicitamente Como Zero.
*/

void    *ft_calloc(size_t num, size_t size)
{
    void *str;

    str = malloc(num * size);
    if (!str)
        return (NULL);
    ft_bzero(str, (num * size));
    return (str);
}