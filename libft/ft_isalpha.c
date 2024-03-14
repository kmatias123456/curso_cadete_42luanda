#include "libft.h"

/*
*A Funcao Que Verifica.
*Se Um  CaracterE Um Alfabeto.
*/

int ft_isalpha(int c)
{
    return (
        (c >= 65 && c <= 90) ||
        (c >= 97 && c <= 122)
    );
}