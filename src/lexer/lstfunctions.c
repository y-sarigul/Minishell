#include "../../inc/minishell.h"
#include <stdio.h>

// redirections'lari buldugumuzda bunlari cmd linin bulundugu konumdan
// sonraki konuma ekliyor
void ft_addlst_center(t_shell **shell, char *redirection)
{
    t_shell *iter;

    iter =(*shell);
    while (iter -> cmdline -> next)
        iter -> cmdline = iter -> cmdline -> next;
    iter -> cmdline -> next = (t_cmdline *)malloc(sizeof(t_cmdline));
    iter -> cmdline -> next -> value = redirection;
    iter -> cmdline -> next -> next = NULL;
    iter -> cmdline -> next -> prev = iter -> cmdline;
    iter -> cmdline -> next -> type = 2; // Degisebir
}
