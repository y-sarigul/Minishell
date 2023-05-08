#include "../../../inc/minishell.h"

t_cmdline *c_newlst(char *word, int index)
{
    t_cmdline *newlst;

    newlst = (t_cmdline *)malloc(sizeof(t_cmdline));
    newlst -> word = word;
    newlst -> index = index;
    newlst -> next = NULL;
    return (newlst);
}
