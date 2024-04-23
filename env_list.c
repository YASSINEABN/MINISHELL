#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

t_listt *env_to_list(char **envp)
{
int i;
  t_listt *head;
  
  head = NULL;

  i = -1;
  int j;
    
  t_listt *current ;
  current = NULL;
  while(envp[++i])
 
	{
	  t_listt *node = malloc(sizeof(t_listt));
	  j = -1;
	  while(envp[i][++j])
	    {
	      if(envp[i][j] == '=')
		{
		  node->index = ft_substring(envp[i], 0 , j);
		  node->value = ft_substring(envp[i],j+1 , ft_strlen(envp[i]));
		}
	}
	    
  if(head == NULL)
    head = node;
  
  else
      current->next = node;

      current = node;
}
  return head;


}
