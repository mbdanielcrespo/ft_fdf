/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:56:21 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/18 17:25:40 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, t_size n)
{
	char	*dest;
	char	*src;
	t_size	c;

	c = 0;
	if (!destptr && !srcptr)
		return (NULL);
	dest = (char *)destptr;
	src = (char *)srcptr;
	if (dest > src)
	{
		while (n--)
			dest[n] = src[n];
	}
	else
	{
		while (n--)
		{
			dest[c] = src[c];
			c++;
		}
	}
	return (dest);
}
