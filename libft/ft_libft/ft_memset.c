/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:46:11 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/19 15:24:01 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*ptr, t_i32 ch, t_size n)
{
	char	*strptr;
	t_size	c;

	c = 0;
	strptr = (char *)ptr;
	while (c < n)
	{
		strptr[c] = ch;
		c++;
	}
	return (ptr);
}
