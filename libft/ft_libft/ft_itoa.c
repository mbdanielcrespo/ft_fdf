/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:50:07 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/19 15:18:00 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_i32	ft_count_int(signed long long int n, t_i32 *sign)
{
	t_i32	c;

	c = 0;
	*sign = 0;
	if (n < 0)
	{
		*sign = 1;
		c++;
		n = -n;
	}
	if (n == 0)
	{
		c = 1;
		*sign = -1;
	}
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static void	ft_iterate(char *str, t_i32 len, t_i64 nb)
{
	while (nb > 0)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(t_i32 n)
{
	t_i32	sign;
	t_i64	nb;
	t_i32	len;
	char	*str;

	nb = n;
	len = ft_count_int(nb, &sign);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (sign && (sign != -1))
	{
		nb = -nb;
		str[0] = '-';
	}
	else if (sign == -1)
		str[0] = '0';
	str[len--] = '\0';
	ft_iterate(str, len, nb);
	return (str);
}
/*
int	main()
{
	printf("Output -> %s, %s, %s, %s, %s\n", ft_itoa(0), ft_itoa(40)
	, ft_itoa(-45), ft_itoa(-2147483648), ft_itoa(2147483647));
}
*/
