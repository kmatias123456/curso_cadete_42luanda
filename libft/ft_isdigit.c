#include "libft.h"

/*
*A funcao que verifica se um determinado
*Caracter e ou nao um digito (0,1,2,3,4,5,6,7,8,9).
*/

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
