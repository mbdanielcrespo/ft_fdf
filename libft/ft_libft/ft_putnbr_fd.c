/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:49:41 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/23 20:22:13 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(t_i32 n, t_i32 fd)
{
	t_i64	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
	}
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
