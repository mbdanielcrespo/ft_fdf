/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:23:59 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/18 17:43:08 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	t_u32	c;
	t_u32	w;
	char	*res;

	c = 0;
	w = 0;
	c = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (c + 1));
	if (!res)
		return (NULL);
	c = 0;
	while (s1[c] != '\0')
	{
		res[c] = s1[c];
		c++;
	}
	while (s2[w] != '\0')
	{
		res[c + w] = s2[w];
		w++;
	}
	res[c + w] = '\0';
	return (res);
}
/*
int	main()
{
	char	*s1 = "Hello ";
	char	*s2 = "World!";
	printf("s1 -> %s, s2 -> %s\n", s1, s2);
	printf("Output -> %s", ft_strjoin(s1, s2));
}
*/
