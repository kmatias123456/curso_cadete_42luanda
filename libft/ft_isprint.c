#include "libft.h"

/*
*A Funcao Que Verifica Se Um Caracter,
*Pertence A Classe Dos Primiveis Ou Nao.
*/

int ft_isprint(int c)
{
    return (c >= 32 && c <= 126);
}
