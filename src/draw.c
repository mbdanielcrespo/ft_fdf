/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:31:36 by danalmei          #+#    #+#             */
/*   Updated: 2023/11/06 18:22:22 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"
# include <math.h>

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	breshenham(float x, float y, float x1, float y1, t_fdf *data)		// (1,1, 3, 12)
{
	float x_step;
	float y_step;
	int max;
	int	z;
	int z1;

	z = data->z_data[(int)y][(int)x];
	z1 = data->z_data[(int)y1][(int)x1];
	//-----------------zoom
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	
	//-----------------color
	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	//-----------------3D
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;

	x_step = x1 - x; // x: 3 - 1 =	 2 -2
	y_step = y1 - y; // y: 12 - 1 = 11 -11
	max = ft_max(ft_abs(x_step), ft_abs(y_step));	// max (11, 2)
	x_step /= max;	// 2 / 11 = 0,181818
	y_step /= max;	// 11 / 11 = 1
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{ 
	int	x;
	int	y;

	y = 0;
	while (y < (data->height - 1))
	{
		x = 0;
		while (x < data->width)
		{
			if (x < (data->width - 1))
				breshenham(x, y, x + 1, y, data);
			if (y < (data->height - 2))
				breshenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	
}