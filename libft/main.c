#include "libft.h"

int main(int argc, char const *argv[])
{
    if (argc == 2)
        printf("%i", ft_isalpha(argv[1][0]));
    return 0;
}
