#include "../inc/minishell.h"
#include <stdio.h>

int main (int argc, char **argv, char **evnp)
{
    (void)argc;
    (void)argv;

    while(*evnp){
        printf("%s\n", *evnp);
        evnp++;
    }


    // init_shell(evnp);
    return 0;
}
