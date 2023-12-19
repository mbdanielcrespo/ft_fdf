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

void	destroy_mlx(t_fdf *data)
{
	if (data->img_data.img)
		mlx_destroy_image(data->mlx_ptr, data->img_data.img);
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	free_strs(char **strs)
{
	int	c;

	c = 0;
	if (strs)
	{
		while (strs[c])
		{
			free(strs[c]);
			c++;
		}
		free(strs);
	}
}

void	free_arr(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	destroy_fdf(t_fdf *data)
{
	if (data)
	{
		free_arr(data->z_data);
		free_arr(data->color_map);
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
