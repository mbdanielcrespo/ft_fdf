/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:31:36 by danalmei          #+#    #+#             */
/*   Updated: 2023/11/02 18:29:15 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	breshenham(int x1, int y1, int x2, int y2, t_fdf *data)		// (1,1, 3, 12)
{
	float x_step;
	float y_step;
	int max;

	x_step = x2 - x1; // x: 3-1=	2
	y_step = y2 - y1; // y: 12-1=	11

	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	
	while ((int)(x2 - x1) || (int)(y2 - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x2, y2, 0xfffffff);
		x2 += x_step;
		y2 += y_step;
	}
}