/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:53:10 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/19 15:01:05 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_char_to_int(char c)
{
	if (c >= '0' && c <= '9') 
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	hex_to_int(char *hex_str)
{
	int	i;
	int	base;
	int	res;

	i = 0;
	base = 1;
	res = 0;
	while (hex_str[i])
		i++;
	while (--i >= 2)
	{
		res += hex_char_to_int(hex_str[i]) * base;
		base *= 16;
	}
	return (res);
}

int	interpolate(int start, int end, float ratio)
{
	return ((int)(start + ((end - start) * ratio)));
}