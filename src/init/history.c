#include "../../inc/minishell.h"
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

// utils test
// static void ft_printlst(t_shell *shell)
// {
//     t_shell *iter;

//     iter = shell;
//     while (iter->history){
//         printf("%s\n", iter->history->line);
//         iter->history = iter->history->next;
//     }
// }

static int ft_sizelst(t_history *his)
{
    int i;
    t_history *iter;
    
    i = 0;
    iter = his;
    while (iter){
        i++;
        iter = iter->next;
    }
    return (i - 1);
}

static void ft_overfollow_history(t_shell **shell, const char *line)
{
    t_history *temp;
    t_history *tail;

    tail = (*shell)->history;
    temp = (t_history *)malloc(sizeof(t_history));
    temp -> next = NULL;
    temp -> line = ft_strdup(line);
    while (tail -> next)
        tail = tail -> next;
    tail -> next = temp;
    temp -> prev = tail;
    (*shell)->history = (*shell)->history->next;
    (*shell)->history->prev = NULL;
}

static void ft_addlist_his(t_shell **shell, const char *line)
{
    t_history *iter;

    if (ft_sizelst((*shell)->history) >= 10)
    {
        ft_overfollow_history(shell, line);
        return;
    }

    iter = (*shell) -> history;
    if (!(*shell) -> history){
        (*shell) -> history = (t_history *)malloc(sizeof(t_history));
        (*shell) -> history-> line = ft_strdup(line);
        (*shell) -> history-> next = NULL;
        (*shell) -> history-> prev = NULL;
    }
    else {
        while (iter -> next)
            iter = iter -> next;
        iter -> next = (t_history *)malloc(sizeof(t_history));
        iter -> next -> line = ft_strdup(line);
        iter -> next -> next = NULL;
        iter -> next -> prev = iter;
    }
}

void ft_save_history(t_shell **shell, const char *line)
{
    ft_addlist_his(shell, line);
}
