#include<unistd.h>
#include "minishell.h"
void remove_node(t_listt **head, char *index)
{
  t_listt *headd = *head;
  t_listt *node;
  while(headd)
    {
      if(headd->next!= NULL)
	{
	  if(!ft_strncmp(headd->next->index,index,ft_strlen(index)))
	    {
	      node = headd->next;
	      free(node);
	      headd->next = headd->next->next;
	    }
	 
	}
      headd = headd->next;
    }

}

int main(int argc ,char **argv , char **envp)
{
  t_listt *head = env_to_list(envp);
  remove_node(&head , argv[2]);
  
  
  while(head)
    {
      printf("%s=%s\n",head->index,head->value);
      head = head->next;
    }
  
  
}
