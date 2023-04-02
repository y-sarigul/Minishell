#include "../../inc/minishell.h"
#include <stdio.h>

char	**ft_split_test(char *str)
{
    int i;
    int i2;
    int i3;
    char **tab;

    i = 0;
    i2 = 0;
    tab = (char**)malloc(sizeof(**tab) * 100);
    while (str[i] != '\0')
    {
        i3 = 0;
        tab[i2] = (char*)malloc(sizeof(char) * 100);
        tab[i2][i3] = str[i];
        i++;
        i3++;
        tab[i2][i3] = '\0';
        i2++;
    }

    tab[i2] = 0;
    return (tab);
}

static int ft_check_type(char *line)
{

    int i;
    char **buff;
    int triger;

    buff = ft_split_test(line);

    i = 0;
    triger = 0;
    check_greater_than(buff);

    return(0);
}

// cmdline struct'inin icerisine atamalari yapar

void ft_addlst_lexer(t_shell **shell, size_t size)
{
    t_shell *iter;
    size_t i;

    i = 0;
    iter = (*shell);
    while (size--){
        if (!(*shell)->cmdline){
            (*shell)->cmdline = (t_cmdline *)malloc(sizeof(t_cmdline));
            (*shell)->cmdline->next = NULL;
            (*shell)->cmdline->prev = NULL;
            (*shell)->cmdline->value = (*shell)->cmd.splited_line[i];
            (*shell)->cmdline->type = 0;
        }
        else {
            while (iter -> cmdline -> next)
                iter -> cmdline = iter -> cmdline -> next;
            iter -> cmdline -> next = (t_cmdline *)malloc(sizeof(t_cmdline));
            iter -> cmdline -> next -> value = (*shell)->cmd.splited_line[i];
        }
        ft_check_type((*shell)->cmd.splited_line[i]);
        i++;
    }
}

