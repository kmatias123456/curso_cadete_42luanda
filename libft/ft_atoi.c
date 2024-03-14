#include "libft.h"

/*
*A funcao que extrai unumeros,
*Numa variaver que recebi um string.
*/

static int ft_istab(char c)
{
    return (
        c == 32 || (c >= 9 && c <= 13)
    );
}

static int ft_todec(char c)
{
    return (c - '0');
}

static int ft_sinal(char c)
{
    return (c == 43 || c == 45);
}

int ft_atoi(const char *strnb)
{
    int counter;
    int result;
    int convert;

    while (ft_istab(*strnb))
    {
        strnb++;
    }
    convert = 1;
    result = 0;
    if (ft_sinal(*strnb))
    {
        if (*strnb == 45)
        {
            convert *= (-1);
        }
        strnb++;
    }
    counter = 0;
    while (ft_isdigit(*strnb))
    {
        result = (result * 10 + ft_todec(*strnb));
        counter++;
        strnb++;
    }
    return (result * convert);
}
