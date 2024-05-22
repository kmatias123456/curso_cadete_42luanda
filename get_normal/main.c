#include <fcntl.h>  // Necessário para open()
#include <stdio.h>  // Necessário para printf()
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Abre o arquivo de teste em modo de leitura
    fd = open("LICENSE", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Lê e imprime cada linha do arquivo até que não haja mais linhas
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Fecha o arquivo
    close(fd);
    return (0);
}

