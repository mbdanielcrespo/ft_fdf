/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:01:45 by danalmei          #+#    #+#             */
/*   Updated: 2023/10/24 16:03:12 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char	*str, int ch);
char	*get_next_line(int fd);
char	*ft_st_save(char *st_save);
char	*ft_read_st_save(int fd, char *save);

#endif
