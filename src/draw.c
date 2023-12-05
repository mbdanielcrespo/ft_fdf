/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:31:36 by danalmei          #+#    #+#             */
/*   Updated: 2023/11/08 18:55:32 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	set_color(int z, int z1, t_fdf *data)
{
	if (z < 0 || z1 < 0)
		data->color = 0xe80c0c;
	else if ((z > 0 || z1 > 0))
		data->color = 0x008000;
	else
		data->color = 0xffffff;
}

void	set_zoom(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

void	set_shift(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
	*x1 += data->shift_x;
	*y1 += data->shift_y;
}

void	set_steepness(int *z, int *z1, t_fdf *data)
{
	*z *= data->steepness;
	*z1 *= data->steepness;
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	breshenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float x_step;
	float y_step;
	int max;

	x_step = x1 - x;
	y_step = y1 - y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw_line(float x, float y, float x1, float y1, t_fdf *data)
{
	int	z;
	int z1;

	z = data->z_data[(int)y][(int)x];
	z1 = data->z_data[(int)y1][(int)x1];
	set_zoom(&x, &y, &x1, &y1, data);
	set_color(z, z1, data);
	set_steepness(&z, &z1, data);
	
	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);
	
	set_shift(&x, &y, &x1, &y1, data);
	breshenham(x, y, x1, y1, data);
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
				draw_line(x, y, x + 1, y, data);
			if (y < (data->height - 2))
				draw_line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}