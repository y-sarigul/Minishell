#include "../../inc/minishell.h"
#include "../../inc/libft.h"
#include <stdio.h>

static char	*find_path(char **envp)
{
    while(ft_strncmp("PWD", *envp, 4))
        envp++;
    return (*envp+4);
}


void init_shell(char **envp)
{
    t_pwd *pwd;

    pwd = (t_pwd *)malloc(sizeof(t_pwd));
    pwd = NULL;

    pwd->line = find_path(envp);
    printf("%s\n", pwd->line);
}
