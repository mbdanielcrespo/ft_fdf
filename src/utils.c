/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:53:10 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/21 14:42:40 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @code 
 * int hex_char_to_int(char c);
 * @endcond
 * @brief Converts a single hexadecimal character to its integer equivalent. \
 * @brief If the character is not a valid hexadecimal character, it returns 0.
 * @param c Character representing a hexadecimal digit (0-9, a-f, A-F).
 * @return (int) Digit Value.
 */
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

/**
 * @code 
 * int hex_to_int(char *hex_str);
 * @endcond
 * @brief Converts a hexadecimal string to its integer equivalent. \
 * @brief Assumes that the string is a valid hexadecimal number.
 * @param *hex_str Pointer to a string representing a hexadecimal number.
 * @return (int) Number Value.
 */
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

/**
 * @code 
 * int interpolate(int start, int end, float ratio);
 * @endcond
 * @brief Calculates linear interpolation between two values.
 * @param start Starting integer value for interpolation.
 * @param end Ending integer value for interpolation.
 * @param ratio Floating-point between 0.0 and 1.0 Interpolation ratio.
 * @return (int) Interpolated Value.
 */
int	interpolate(int start, int end, float ratio)
{
	return ((int)(start + ((end - start) * ratio)));
}
