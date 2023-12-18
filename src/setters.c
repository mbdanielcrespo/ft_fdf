/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:08:31 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/07 17:12:02 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_controls(int key, t_fdf *data)
{
	if (key == 65361)
		data->shift_x -= 10;
	if (key == 65362)
		data->shift_y -= 10;
	if (key == 65363)
		data->shift_x += 10;
	if (key == 65364)
		data->shift_y += 10;
	if (key == 122)
		data->zoom += 5;
	if (key == 120)
		data->zoom -= 5;
	if (key == 99)
		data->steepness += 1;
	if (key == 118)
		data->steepness -= 1;
	if (key == 112)
		data->projection = 'p';
	if (key == 105)
		data->projection = 'i';
	clear_image(data, 0x00000000);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_data.img, 0, 0);
}

void	set_zoom(t_pt *pt1, t_pt *pt2, t_fdf *data)
{
	pt1->x *= data->zoom;
	pt1->y *= data->zoom;
	pt2->x *= data->zoom;
	pt2->y *= data->zoom;
}

void	set_shift(t_pt *pt1, t_pt *pt2, t_fdf *data)
{
	pt1->x += data->shift_x;
	pt1->y += data->shift_y;
	pt2->x += data->shift_x;
	pt2->y += data->shift_y;
}

void	set_steepness(int *z, int *z1, t_fdf *data)
{
	*z *= data->steepness;
	*z1 *= data->steepness;
}

int get_color(float ratio, int col_start, int col_end)
{
	int r;
	int g;
	int b;

	r = interpolate((col_start >> 16) & 0xFF, (col_end >> 16) & 0xFF, ratio);
    g = interpolate((col_start >> 8) & 0xFF, (col_end >> 8) & 0xFF, ratio);
    b = interpolate(col_start & 0xFF, col_end & 0xFF, ratio);
	return (r << 16) | (g << 8) | b;
}