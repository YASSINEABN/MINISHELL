#include <unistd.h>
#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

 size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		l;

	i = 0;
	l = ft_strlen(src);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (l);
}

 size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest;
	size_t	srcc;
	size_t	i;

	dest = ft_strlen(dst);
	srcc = ft_strlen(src);
	i = 0;
	if (size <= dest)
		return (size + srcc);
	while (src[i] && (i + dest) < size - 1)
	{
		dst[dest + i] = src[i];
		i++;
	}
	dst[dest + i] = 0;
	return (dest + srcc);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	if (s1)
		ft_strlcpy(result, s1, s1_len + 1);
	else
		result[0] = '\0';
	if (s2)
		ft_strlcat(result, s2, s1_len + s2_len + 1);
	if (!*result)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	free(s1);
	return (result);
}

char	*ft_substring(char const *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start > str_len)
		start = str_len;
	if (len > str_len - start)
		len = str_len - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str + start, len + 1);
	if (!*result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while ((str1[i] && str2[i]) && (str1[i] == str2[i] && i < n - 1))
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

