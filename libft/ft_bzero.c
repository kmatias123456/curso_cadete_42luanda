#include "libft.h"

/*
*A funcao que zera a memoria de um ponteiro
*Usando a funcao ft_memset.
*/

void    ft_bzero(void *b, size_t len)
{
    ft_memset(b, '\0', len);
}