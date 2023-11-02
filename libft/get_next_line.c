/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:01:38 by danalmei          #+#    #+#             */
/*   Updated: 2023/05/01 16:05:02 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*ft_read_st_save(int fd, char *st_save)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_gnl(st_save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(st_save);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		st_save = ft_strjoin_gnl(st_save, buff);
	}
	free(buff);
	return (st_save);
}

char	*ft_get_line(char *st_save)
{
	int		c;
	char	*s;

	c = 0;
	while (st_save[c] != '\0' && st_save[c] != '\n')
		c++;
	s = (char *)malloc(sizeof(char) * (c + 2));
	if (!s)
		return (NULL);
	c = 0;
	while (st_save[c] != '\0' && st_save[c] != '\n')
	{
		s[c] = st_save[c];
		c++;
	}
	if (st_save[c] == '\n')
	{
		s[c] = st_save[c];
		c++;
	}
	s[c] = '\0';
	return (s);
}

char	*ft_st_save(char *st_save)
{
	int		c;
	int		w;
	char	*s;

	c = 0;
	while (st_save[c] && st_save[c] != '\n')
		c++;
	if (!st_save[c])
	{
		free(st_save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen_gnl(st_save) - c + 1);
	if (!s)
		return (NULL);
	c++;
	w = 0;
	while (st_save[c])
		s[w++] = st_save[c++];
	s[w] = '\0';
	free(st_save);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*st_save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	st_save = ft_read_st_save(fd, st_save);
	if (!st_save)
		return (NULL);
	line = ft_get_line(st_save);
	st_save = ft_st_save(st_save);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
