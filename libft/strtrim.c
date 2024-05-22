#include <stdlib.h>
#include <stdio.h>

static int is_set_char(char c, char const *set)
{
    while (*set)
    {
        if (c == *set)
            return 1;
        set++;
    }
    return 0;
}

void ft_start(char const *s1, char const *set, int *start)
{
    while (s1[*start] && is_set_char(s1[*start], set))
        (*start)++;
}

void ft_end(char const *s1, char const *set, int *len, int start)
{
    int end = start;
    *len = start;
    while (s1[end])
    {
        if (!is_set_char(s1[end], set))
            *len = end + 1;
        end++;
    }
}

char *ft_strtrim(char const *s1, char const *set)
{
    int start;
    int len;
    int i;
    char *trimmed;

    if (!s1 || !set)
        return NULL;
    start = 0;
    ft_start(s1, set, &start);
    len = 0;
    ft_end(s1, set, &len, start);
    trimmed = (char *)malloc((len - start + 1) * sizeof(char));
    if (!trimmed)
        return NULL;
    i = 0;
    while (start < len)
    {
        trimmed[i++] = s1[start++];
    }
    trimmed[i] = '\0';
    return trimmed;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    char *result = ft_strtrim("ola Kiangebeni Matias ola", "ola");
    if (result)
    {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}
