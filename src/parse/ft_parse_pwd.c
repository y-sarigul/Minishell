#include "../../inc/minishell.h"
#include <stdio.h>

static char *find_pwd(char **envp)
{
    while (ft_strncmp("PWD", *envp, 3)) {
        envp++;
    }
    return (*envp+4);
}

void ft_parse_pwd(t_pwd **pwd, char **envp)
{
    if (!(*pwd)){
        (*pwd) = (t_pwd *)malloc(sizeof(t_pwd));
    }


    (*pwd) -> line = ft_split(find_pwd(envp), '/');
}
