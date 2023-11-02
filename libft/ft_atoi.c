/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:07:19 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/19 15:16:32 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_u32	ft_isspace(t_u32 ch)
{
	if (ch == 9 || ch == 10 || ch == 11
		|| ch == 12 || ch == 13 || ch == 32)
	{
		return (1);
	}
	return (0);
}

t_i32	ft_atoi(const char *str)
{
	t_i32	c;
	t_i32	sign;
	t_i32	res;

	sign = 1;
	res = 0;
	c = 0;
	while (ft_isspace(str[c]))
	{
		c++;
	}
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
		{
			sign *= -1;
		}
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = res * 10 + (str[c] - '0');
		c++;
	}
	return ((t_i32)(sign * res));
}
/*
int	main()
{
	int	a = 40;
	int	b = -345;
	int	c = -2147483648;

	printf("Outputs -> %s, %s, %s\n", a, b c);
}
*/
