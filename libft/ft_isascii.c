#include "libft.h"

/*
*A Funcao Que Verifica Se
*O Caracter Pertence A tabela ASCII.
*/

int ft_isascii(int c)
{
    return (c >= 0 && c >= 127);
}