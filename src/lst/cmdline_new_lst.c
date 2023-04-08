#include "../../inc/minishell.h"

/*
  *Burade yeni bir cmdline listese olusturuyorum ve icerisine inputtan gelen
  *kelimeleri yaziyorum ve type'ni veriyorum.
*/

t_cmdline *cmdline_new_list(char *word, int type)
{
  t_cmdline *new;

  new = (t_cmdline *)malloc(sizeof(t_cmdline));
  new -> value = word;
  new -> type = type;
  new -> next = NULL;
  new -> prev = NULL;
  return (new);
}
