#include "../../inc/minishell.h"

// This fuction merge two strings that user name and where we are
// Like ft_strjoin
static char	*creat_pwd(char const *s1, char const *s2)
{
    unsigned int	i;
    unsigned int	j;
    char			*s3;
    if (!s1 || !s2)
        return (NULL);
    s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!s3)
        return (NULL);
    i = 0;
    while (s1[i] != 0){
        s3[i] = s1[i];
        i++;
    }
    s3[i] = '@';
    i++;
    j = 0;
    while (s2[j] != 0){
        s3[i + j] = s2[j];
        j++;
    }
    s3[i + j] = 0;
    return (s3);
}

// Searching in enviroment and return source string 
static char *find_pwd(char *src, char **envp)
{
    while (ft_strncmp(src, *envp, ft_strlen(src))) {
        envp++;
    }
    return (*envp + (ft_strlen(src)));
}

void ft_parse_pwd(t_shell **shell, char **envp)
{
    int i;
    char **buff;
    char *user;

    if (!(*shell))
        (*shell) = (t_shell *)malloc(sizeof(t_shell));


    buff = ft_split(find_pwd("PWD",envp), '/');
    user = find_pwd("USER=", envp);
    i = 0;
    while (buff[i])
        i++;
    i--;
    (*shell) -> pwd.line = creat_pwd(user, buff[i]);
}
