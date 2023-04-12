#include "../../inc/minishell.h"
/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * Burada yapilacak kontroller ve ama islemleri icin ayirdim
 * */

// > veya >> gelen double pointer icerisinde ariyor ve buldugunda 
// henuz yapilmadi yapim asamasinda
int check_greater_than(t_cmdline **root, char **line)
{
    size_t i;

    i = 0;
    while (line[i])
    {
        if (line[i][0] == '>')
        {
            if (line[i + 1] != 0 && line[i + 1][0] == '>')
            {
            }
            else if (line[i][0] == '>')
            {
            }
        }
        i++;
    }
    return (0);
}

// < veya << gelen double pointer icerisinde ariyor ve buldugunda 
// henuz yapilmadi yapim asamasinda

int less_than(t_cmdline **root, char **line)
{
    size_t i;

    i = 0;
    while (line[i])
    {
        if (line[i][0] == '<')
        {
            if (line[i + 1] != 0 && line[i + 1][0] == '<')
            {
            }
            else if (line[i][0] == '<')
            {
            }
        }
        i++;
    }
    return (0);
}
