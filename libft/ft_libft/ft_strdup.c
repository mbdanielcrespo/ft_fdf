/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:23:39 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/18 17:29:03 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	t_i32	c;
	char	*cpy;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	cpy = (char *)malloc(sizeof(char) * (c + 1));
	if (!cpy)
		return (NULL);
	c = 0;
	while (str[c] != '\0')
	{
		cpy[c] = str[c];
		c++;
	}
	cpy[c] = '\0';
	return (cpy);
}
