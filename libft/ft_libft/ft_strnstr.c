/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:03:51 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/23 20:37:40 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *str, t_size n)
{
	t_size	c;
	t_size	w;

	c = 0;
	if (*str == '\0' || !str)
		return ((char *)big);
	while (big[c] != '\0' && c < n)
	{
		w = 0;
		while (big[c + w] == str[w] && (c + w) < n)
		{
			if (str[w + 1] == '\0')
			{
				return ((char *)&big[c]);
			}
			w++;
		}
		c++;
	}
	return (NULL);
}
