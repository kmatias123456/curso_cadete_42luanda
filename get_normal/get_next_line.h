#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

// Define o tamanho do buffer para leitura
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

// Declaração das funções
char    *get_next_line(int fd);
ssize_t read_line(char **holder, char **buffer, char **final_line, int fd);
char    *split_line(char **holder);
void    free_and_reset(void **var);

char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif
