#include "../../../inc/minishell.h"

void c_printlst_next(t_cmdline *root)
{
    if (root == NULL)
        return ;
    while (root)
    {
        printf("%d   %s\n", root->index, root -> word);
        root = root -> next;
    }
}

void c_printlst_prev(t_cmdline *root)
{
    if (root == NULL)
        return ;
    while (root -> next)
        root = root -> next;
    while (root)
    {
        printf("%d   %s\n", root->index, root -> word);
        root = root -> prev;
    }
}
