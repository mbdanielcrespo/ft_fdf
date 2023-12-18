/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:31:36 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/07 15:22:57 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_fdf *data, int color)
{
    int	x;
	int	y;

	y = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
    while (y < 600)
	{
		x = 0;
        while (x < 600)
		{
            my_mlx_pixel_put(&(data->img_data), x, y, color);
			x++;
        }
		y++;
    }
}

void	breshenham(t_pt pt1, t_pt pt2, t_fdf *data, t_pt color)
{
	float	x_step;
	float	y_step;
	float	ratio;
	int		max;
	int	c;

	c = 0;
	ratio = 0;
	x_step = pt2.x - pt1.x;
	y_step = pt2.y - pt1.y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(pt1.x - pt2.x) || (int)(pt1.y - pt2.y))
	{
		ratio = (float)c / max;
		my_mlx_pixel_put(&(data->img_data), pt1.x, pt1.y, get_color(ratio, color.x, color.y));
		pt1.x += x_step;
		pt1.y += y_step;
		c++;
	}
}

void	draw_line(t_pt pt1, t_pt pt2, t_fdf *data)
{
	int	z;
	int	z1;
	t_pt zpt;
	t_pt color;

	z = data->z_data[(int)pt1.y][(int)pt1.x];
	z1 = data->z_data[(int)pt2.y][(int)pt2.x];
	color.x = data->color_map[(int)pt1.y][(int)pt1.x];
	color.y = data->color_map[(int)pt2.y][(int)pt2.x];
	set_zoom(&pt1, &pt2, data);
	set_steepness(&z, &z1, data);
	zpt.x = z;
	zpt.y = z1;
	projection(&pt1, &pt2, zpt, data);
	set_shift(&pt1, &pt2, data);
	breshenham(pt1, pt2, data, color);
}

void	draw2(t_pt *pt1, t_pt *pt2, t_pt *curr_pt, t_fdf *data)
{
	if (curr_pt->x < (data->width - 1))
	{
		pt1->x = curr_pt->x;
		pt1->y = curr_pt->y;
		pt2->x = curr_pt->x + 1;
		pt2->y = curr_pt->y;
		draw_line(*pt1, *pt2, data);
	}
	if (curr_pt->y < (data->height - 2))
	{
		pt1->x = curr_pt->x;
		pt1->y = curr_pt->y;
		pt2->x = curr_pt->x;
		pt2->y = curr_pt->y + 1;
		draw_line(*pt1, *pt2, data);
	}
}

void	draw(t_fdf *data)
{
	t_pt	curr_pt;
	t_pt	pt1;
	t_pt	pt2;

	curr_pt.y = 0;
	while (curr_pt.y < (data->height - 1))
	{
		curr_pt.x = 0;
		while (curr_pt.x < data->width)
		{
			draw2(&pt1, &pt2, &curr_pt, data);
			curr_pt.x++;
		}
		curr_pt.y++;
	}
}
