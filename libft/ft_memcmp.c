/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:11:58 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/23 19:22:29 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_size n)
{
	t_size	c;
	t_cuc	*ss1;
	t_cuc	*ss2;

	c = 0;
	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	while (c < n)
	{
		if (ss1[c] != ss2[c])
			return (ss1[c] - ss2[c]);
		c++;
	}
	return (0);
}
