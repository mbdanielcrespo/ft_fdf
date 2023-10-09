/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:49:41 by danalmei          #+#    #+#             */
/*   Updated: 2023/05/01 20:07:10 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fdp(t_i32 n, t_i32 fd)
{
	t_i64	nb;
	int		c;

	c = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fdp('-', fd);
		nb = nb * -1;
		c++;
	}
	if (nb >= 10)
	{
		c += ft_putnbr_fdp(nb / 10, fd);
		ft_putnbr_fdp(nb % 10, fd);
		c++;
	}
	else
	{
		c += ft_putchar_fdp(nb + '0', fd);
	}
	return (c);
}
/*
int	main()
{
	ft_putnbr_fd(0, 1);
	ft_putnbr_fd(10000043, 1);
	ft_putnbr_fd(-10000043, 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putnbr_fd(-2147483648, 1);
}
*/
