/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:36:38 by yaboulan          #+#    #+#             */
/*   Updated: 2024/04/16 17:31:26 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoinn(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substring(char const *str, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif