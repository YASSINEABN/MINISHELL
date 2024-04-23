#include <unistd.h>
#include "minishell.h"

char *jbedlhome(t_listt *list)
{
  int i = -1;
  while(list)
    {
      if(!ft_strncmp(list->index,"HOME",4))
	return list->value;
      list =  list->next;
    }
  return NULL;
}
void change_pwd(t_listt **head , char *old , char *new)
{
  t_listt *headd = *head;
  while(headd)
    {
      if(!ft_strncmp(headd->index,"PWD",3))
	headd->value = new;
      if(!ft_strncmp(headd->index,"OLD_PWD",7))
	    headd->value = old;
	    headd = headd->next;
    }
}
int main(int argc , char **argv , char **envp)
{
  t_listt *head = env_to_list(envp);
  char *old_path = malloc(10);
  getcwd(old_path,10);
  char *home = jbedlhome(head);
  char *new_path;
 
  if(argc == 2)
    {
      change_pwd(&head, old_path, home);
    }
  else
    {
         new_path = argv[2];

      change_pwd(&head, old_path, new_path);
     
    }
  
  while(head)
    {
      printf("%s = %s \n",head->index , head->value);
      head = head->next;
    }
}
