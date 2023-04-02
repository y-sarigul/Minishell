#include "../../inc/minishell.h"

int check_greater_than(const char **line)
{
    size_t i;
    int flag;

    i = 0;
    flag = 0;
    while (line[i])
    {
        if (line[i][0] == '>')
        {
            if (buff[i + 1] != 0 && line[i + 1][0] == '>')
            {
                printf(">>\n");
                flag = 1;
                return (1);
            }
            else if (flag == 0 && line[i][0] == '>')
                printf(">\n");
        }
    }
}
