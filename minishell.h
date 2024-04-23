#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"
typedef struct env{
  char *index;
  char *value;
  struct env  *next;
}t_listt;


t_listt*env_to_list(char **envp);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substring(char const *str, unsigned int start, size_t len);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
