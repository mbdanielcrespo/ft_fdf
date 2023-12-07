/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:48:35 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/06 10:48:35 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_fdf *data)
{
	data->shift_x = 300;//data->w_h - data->w_h/2;
	data->shift_y = 300;//data->w_w - data->w_w/2;
	data->zoom = 25;
	data->steepness = 3;
	data->projection = 'i';
}

void	destroy_mlx(t_fdf *data)
{
	if (data->img_data.img)
		mlx_destroy_image(data->mlx_ptr, data->img_data.img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}

void	destroy_fdf(t_fdf *data)
{
	int	i;

	i = 0;
	if (data)
	{
		if (data->z_data)
		{
			if (data->z_data[i])
			{
				while (data->z_data[i])
				{
					free(data->z_data[i]);
					i++;
				}
			}
			free(data->z_data);
		}
		free(data);
	}
}

void	destroy_all(t_fdf *data)
{
	destroy_mlx(data);
	destroy_fdf(data);
	ft_printf("Data freed successfully!\n");
	exit(0);
}
