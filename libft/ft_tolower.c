/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:50:30 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/17 14:06:29 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_i32	ft_tolower(t_i32 ch)
{
	if (ch >= 65 && ch <= 90)
	{
		ch += 32;
	}
	return (ch);
}
