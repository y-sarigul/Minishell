#include "../../inc/minishell.h"

void parser(t_shell **shell)
{
    int i;

    i = 0;
    while ((*shell)->input.line[i]){
        c_addlst_back(&(*shell)->cmdline, c_newlst((*shell)->input.line[i], i));
        i++;
    }
}
