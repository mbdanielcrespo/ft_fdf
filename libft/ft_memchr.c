/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:01:37 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/17 17:10:32 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, t_i32 ch, t_size n)
{
	t_size	c;
	t_u8	*str;
	t_u8	chr;

	c = 0;
	str = (t_u8 *)s;
	chr = (t_u8)ch;
	while (c < n)
	{
		if (str[c] == chr)
		{
			return (&str[c]);
		}
		c++;
	}
	return (NULL);
}
