#include "../../inc/minishell.h"

//double pointer listeyi freelemek icin kullaniliyor
void ft_free_list(t_cmdline **cmd)
{
    while ((*cmd) != NULL)
    {
        t_cmdline *temp;
        temp = (*cmd) -> next;
        free ((*cmd));
        (*cmd) = temp;
    }
}

