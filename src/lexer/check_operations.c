#include "../../inc/minishell.h"

// > veya >> gelen double pointer icerisinde ariyor ve buldugunda 
// shell e kelemke icin ft_addlst_center a gonderiyor
int check_greater_than(t_shell **shell, char **line)
{
    size_t i;
    char *buff;

    i = 0;
    while (line[i])
    {
        if (line[i][0] == '>')
        {
            if (line[i + 1] != 0 && line[i + 1][0] == '>')
            {
                buff = (char *)malloc(sizeof(char) * (2 + 1));
                buff[0] = line[i][0];
                buff[1] = line[i + 1][0];
                buff[2] = '\0';
                printf("%s\n", buff);
                ft_addlst_center(shell, buff);
                i++;
            }
            else if (line[i][0] == '>')
            {
                buff = (char *)malloc(sizeof(char) * (1 + 1));
                buff[0] = line[i][0];
                buff[1] = '\0';
                printf("%s\n", buff);
                ft_addlst_center(shell, buff);
            }
            free(buff);
        }
        i++;
    }
    return (0);
}

// < veya << gelen double pointer icerisinde ariyor ve buldugunda 
// shell e kelemke icin ft_addlst_center a gonderiyor
int less_than(t_shell **shell, char **line)
{
    size_t i;
    char *buff;

    i = 0;
    while (line[i])
    {
        if (line[i][0] == '<')
        {
            if (line[i + 1] != 0 && line[i + 1][0] == '<')
            {
                buff = (char *)malloc(sizeof(char) * (2 + 1));
                buff[0] = line[i][0];
                buff[1] = line[i + 1][0];
                buff[2] = '\0';
                // ft_addlst_center(shell, buff);
                printf("%s\n", buff);
                i++;
            }
            else if (line[i][0] == '<')
            {
                buff = (char *)malloc(sizeof(char) * (1 + 1));
                buff[0] = line[i][0];
                buff[1] = '\0';
                // ft_addlst_center(shell, buff);
                printf("%s\n", buff);
            }
            free(buff);
        }
        i++;
    }
    return (0);
}
