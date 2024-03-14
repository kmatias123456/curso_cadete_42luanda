#include "libft.h"

/*
*A Funcao Que Verifica Se Um  Caracter,
*E Um Alfanumerico Usando ft_isdigit e ft_isalpha.
*/

int ft_isalnum(int c)
{
    return (ft_isdigit(c) || ft_isalpha(c));
}
