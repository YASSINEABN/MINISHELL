/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:41:20 by yaboulan          #+#    #+#             */
/*   Updated: 2023/11/26 10:49:45 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		remainder = ft_strjoin(remainder, buffer);
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
		line = ft_strjoin(NULL, remainder);
	else
	{
		temp = ft_substring(remainder, 0, new_line + 1);
		line = ft_strjoin(NULL, temp);
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
	static char	*remainder[MAX_FD];
	char		*line;
	int			new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	remainder[fd] = read_into_remainder(fd, remainder[fd], &new_line);
	if (!remainder[fd])
		return (NULL);
	if (!*remainder[fd])
	{
		free(remainder[fd]);
		return (NULL);
	}
	line = extract_line(remainder[fd], new_line);
	remainder[fd] = process_remainder(remainder[fd], new_line);
	return (line);
}
// int main(int argc, char const *argv[])
// {
// 	int fd = open("get_next_line.c",O_RDONLY);
// 	int fd1 = open ("get_next_line_bonus.c",O_RDONLY);
// 	char *s;
// 	char *s2;
// 		while ((s = get_next_line(fd)) && (s2 = get_next_line(fd1)))
//     {
//         printf("%s\n", s);
//         printf("%s\n", s2);
//         free(s);
//         free(s2);
//     }
//     return (0);
// }
