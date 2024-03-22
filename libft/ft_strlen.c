#include "libft.h"

int ft_strlen(const char *str)
{
    int counter;

    counter = 0;
    while (str[counter] != '\0')
        counter++;
    return (counter);
}