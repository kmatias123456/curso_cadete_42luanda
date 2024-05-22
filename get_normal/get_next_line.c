#include "get_next_line.h"

// Lê a próxima linha do arquivo descritor `fd`
char *get_next_line(int fd)
{
    static char *holder = NULL;  // Mantém os dados não processados entre as chamadas
    char *buffer;
    char *final_line;
    int read_fd;

    // Verifica a validade do descritor de arquivo e o tamanho do buffer
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    // Aloca memória para o buffer
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);

    // Verifica se o descritor de arquivo é válido
    if (read(fd, buffer, 0) < 0)
    {
        free_and_reset((void**)&buffer);
        return (NULL);
    }

    // Inicializa `holder` se for a primeira chamada
    if (!holder)
        holder = ft_strdup("");

    // Lê a linha do arquivo
    read_fd = read_line(&holder, &buffer, &final_line, fd);

    // Libera o buffer
    free_and_reset((void**)&buffer);

    // Retorna a linha lida ou NULL se houver um erro ou EOF
    if (read_fd <= 0 && !final_line)
        return (NULL);
    
    return (final_line);
}

// Lê dados do arquivo e armazena no `holder` até encontrar uma nova linha
ssize_t read_line(char **holder, char **buffer, char **final_line, int fd)
{
    ssize_t read_result = 0;  // Resultado da leitura
    char *temp_result;

    while (!ft_strchr(*holder, '\n') && read_result >= 0)
    {
        read_result = read(fd, *buffer, BUFFER_SIZE);
        if (read_result < 0)  // Verifica se houve erro na leitura
            return (-1);
        (*buffer)[read_result] = '\0';

        // Junta o buffer lido ao holder
        temp_result = *holder;
        *holder = ft_strjoin(temp_result, *buffer);
        free(temp_result);
    }

    // Separa a linha completa do restante do buffer
    *final_line = split_line(holder);

    // Se EOF foi alcançado e o holder está vazio, libera a memória e retorna 0
    if (read_result == 0 && !(*holder)[0])
    {
        free(*holder);
        *holder = NULL;
        return (0);
    }

    return (read_result);
}

// Separa a linha do buffer holder e atualiza o holder com os dados restantes
char *split_line(char **holder)
{
    int i = 0;
    char *holder_copy;
    char *temp_holder;

    // Encontra o fim da linha ou o fim do buffer
    while ((*holder)[i] != '\0')
    {
        if ((*holder)[i] == '\n')
        {
            i++;
            break;
        }
        i++;
    }

    // Se não houver uma nova linha, retorna NULL
    if (i == 0 || !*holder)
        return (NULL);

    // Cria uma cópia da linha completa
    temp_holder = *holder;
    holder_copy = ft_substr(temp_holder, 0, i);

    // Atualiza o holder com os dados restantes
    *holder = ft_strdup(&(*holder)[i]);
    free(temp_holder);

    return (holder_copy);
}

// Libera a memória e redefine o ponteiro para NULL
void free_and_reset(void **var)
{
    if (var && *var)
    {
        free(*var);
        *var = NULL;
    }
}

