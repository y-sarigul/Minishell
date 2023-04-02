#include "../../inc/minishell.h"

static int ft_strlen_double_pointer(char **line)
{
    int i;

    i = 0;
    while (line[i] != 0)
        i++;
    printf("%d\n", i);
    return (i);
}

/*
 * Burada shell structinin icerisindeki new_history icerisine buffersize kadar
 * girilen eski cmd'leri tutuyorum gelistirmeler olabilir
 * Burada Buffsize'i asan bir durumda ne olacagine karar verilmemistir
 * ************Burayi gelistir*************
 * */
void new_history(t_shell **shell, char *line)
{
    int i;
    int i2;
    int i3;

    i = 0;
    if (!(*shell)->history)
        (*shell)->history = (char**)malloc(sizeof(char*) * BUFFSIZE);
    i2 = ft_strlen_double_pointer((*shell)->history);
    while (line[i] != '\0')
    {
        i3 = 0;
        (*shell)->history[i2] = (char*)malloc(sizeof(char) * LINESIZE);
        while (line[i]){
            (*shell)->history[i2][i3] = line[i];
            i++;
            i3++;
        }
        (*shell)->history[i2][i3] = '\0';
        i2++;
    }
    (*shell)->history[i2] = 0;
}
