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

/**
 * @code 
 * void destroy_mlx(t_fdf *data);
 * @endcond
 * @brief Frees the memory allocated for the MiniLibX window and image data.
 * @param *data Pointer to the FDF data structure containing MLX pointers.
 * @return (void) Resources Freed.
 */
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

/**
 * @code 
 * void free_strs(char **strs);
 * @endcond
 * @brief Frees an array of strings.
 * @param **strs Pointer to an array of strings to be freed.
 * @return (void) Array Freed.
 */
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

/**
 * @code 
 * void free_arr(int **arr);
 * @endcond
 * @brief Frees a two-dimensional integer array.
 * @param **arr Pointer to the two-dimensional array to be freed.
 * @return (void) Array Freed.
 */
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

/**
 * @code 
 * void destroy_fdf(t_fdf *data);
 * @endcond
 * @brief Frees the memory allocated for the FDF structure, including arrays for z data and color map.
 * @param *data Pointer to the FDF data structure to be freed.
 * @return (void) Data Freed.
 */
void	destroy_fdf(t_fdf *data)
{
	if (data)
	{
		free_arr(data->z_data);
		free_arr(data->color_map);
		free(data);
	}
}

/**
 * @code 
 * void destroy_all(t_fdf *data);
 * @endcond
 * @brief Frees all allocated memory and resources associated with the FDF program.
 * @brief Calls destroy_mlx and destroy_fdf functions, then exits the program.
 * @param *data Pointer to the FDF data structure.
 * @return (void) All Resources Freed.
 */
void	destroy_all(t_fdf *data)
{
	destroy_mlx(data);
	destroy_fdf(data);
	ft_printf("Data freed successfully!\n");
	exit(0);
}
