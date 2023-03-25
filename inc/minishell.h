#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_pwd{
    char **line;
}   t_pwd;

/********init********/
void init_shell(char **evnp);
void ft_parse_pwd(t_pwd **pwd, char **envp);

#endif
