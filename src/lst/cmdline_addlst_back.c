#include "../../inc/minishell.h"

/*
 * cmdline listesini olusturuyoruz
 * */

void cmdline_addlst_back(t_cmdline **lst, t_cmdline *new)
{
    t_cmdline *iter;

    if (!(*lst))
        (*lst) = new;
    else 
    {
        iter = (*lst);
        while (iter -> next)
            iter = iter -> next;
        iter -> next = new;
        new -> prev = iter;
    }
}
