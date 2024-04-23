/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:41:20 by yaboulan          #+#    #+#             */
/*   Updated: 2024/04/16 17:33:23 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_line(char *str)
{
	int	index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

static char	*read_into_remainder(int fd, char *remainder, int *new_line)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoinn(remainder, buffer);
		*new_line = ft_find_line(remainder);
		if (*new_line >= 0)
			break ;
	}
	free(buffer);
	return (remainder);
}

static char	*extract_line(char *remainder, int new_line)
{
	char	*line;
	char	*temp;

	if (!remainder)
		return (NULL);
	if (new_line == -1)
		line = ft_strjoinn(NULL, remainder);
	else
	{
		temp = ft_substring(remainder, 0, new_line + 1);
		line = ft_strjoinn(NULL, temp);
		free(temp);
	}
	return (line);
}

static char	*process_remainder(char *remainder, int new_line)
{
	char	*temp;

	if (!remainder)
		return (NULL);
	if (new_line == -1)
	{
		free(remainder);
		return (NULL);
	}
	temp = ft_substring(remainder, new_line + 1, ft_strlen(remainder));
	free(remainder);
	remainder = temp;
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int			new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_into_remainder(fd, remainder, &new_line);
	if (!remainder)
		return (NULL);
	if (!*remainder)
	{
		free(remainder);
		return (NULL);
	}
	line = extract_line(remainder, new_line);
	remainder = process_remainder(remainder, new_line);
	return (line);
}
// int main(int argc, char const *argv[])
// {
// 	int fd = open("get_next_line.c",O_RDONLY);
// 	char *s;
// 	while(s = get_next_line(fd))
// 	{
// 		printf("%s",s);
// 		free(s);
// 	}
// 	return (0);
// }