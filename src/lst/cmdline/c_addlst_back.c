#include "../../../inc/minishell.h"

void c_addlst_back(t_cmdline **root, t_cmdline *newlst)
{
    t_cmdline *iter;

    if (!(*root))
        (*root) = newlst;
    else {
        iter = (*root);
        while (iter -> next)
            iter = iter -> next;
        iter -> next = newlst;
        newlst -> prev = iter;
    }
}
