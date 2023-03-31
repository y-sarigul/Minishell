#include "../../inc/minishell.h"

 size_t ft_strnlen(const char *s1, const char del)
{
    size_t i;

    i = 0;
    if (!s1)
        return (-1);

    while (*s1){
        if (*s1 == del)
            return (i - 1);
        i++;
        s1++;
    }
    return (0);
}

char *ft_strstr(const char *s1, const char del)
{
    char *buff;
    int i;
    size_t size;


    size = ft_strnlen(s1, del);
    buff = (char *)malloc(sizeof(char) * (size+ 1));
    i = 0;
    while (i < size){
        buff[i] = s1[i];
        i++;
    }
    
    return (buff);
}

/*

struct node **cmd_spliplit(char **cmd_str){
    char **cmds = split_space(cmd_str, ' ');  
    char **cmds = split_opereator(cmds);
    char **cmds = split_options(cmd);

    struct node **list = lst_new();
    cmd = {"ls", "-al", "|", "grep", "samet", ">", "a.txt"};
    while (*cmd != NULL){
        *node->value; 
        *node->kind = find_kind(char *value);
        *node->prev = lst_new();
        cmd++;
        node = node -> next;
    }
}

*/
