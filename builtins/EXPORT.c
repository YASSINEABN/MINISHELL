#include <unistd.h>
#include "../minishell.h"

void add_node(t_listt **head , char *index , char *value)
{
  t_listt *headd = *head;
  while(headd->next)
      headd = headd->next;
  t_listt *node = malloc(sizeof(t_listt));
  node->next = NULL;
  node->index = index;
  node->value = value;
  headd->next = node;
}

int check_list(t_listt *head , char *index)
{
  while(head)
    {
      if(!ft_strncmp(head->index,index,ft_strlen(index)))
	{

	  return 1;
	}
      head= head->next;
    }
  
  return 0 ;
}

void replace_node(t_listt **head ,char *index,char *value)
{
  t_listt *headd = *head;
  
  while(headd)
    {
      if(!ft_strncmp(headd->index ,index,ft_strlen(index)))
	  headd->value =value ;
	  
	headd = headd->next;
    }
}

int main(int argc , char **argv , char **envp)
{
  t_listt *head = env_to_list(envp);
  char *index = argv[2];
  char *value = argv[4];
  if(!check_list(head,index))
    add_node(&head,index,value);
  else
    replace_node(&head,index,value);
  while(head)
    {
      printf("%s %s \n",head->index,head->value);
      head = head->next;
    }
 
}
