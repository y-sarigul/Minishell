#include "../../inc/minishell.h"

/*
 * cmdline listesini olusturuyoruz
 * */

void cmdline_addlst_back(t_cmdline **lst, t_cmdline *new)
{
    t_cmdline *iter;

    if (!(*lst))
    {
        (*lst) = new;
        (*lst)->index = 0;
    }
    else 
    {
        iter = (*lst);
        while (iter -> next)
            iter = iter -> next;
        iter -> next = new;
        new -> prev = iter;
        new -> index = (iter -> index + 1);
    }
}
