/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:13:10 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/21 15:10:49 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @code 
 * int get_color(float ratio, int col_start, int col_end);
 * @endcond
 * @brief Generates a color value by interpolating between two colors \
 * @brief on a ratio.
 * @param ratio Float value between 0.0 and 1.0 = interpolation ratio.
 * @param col_start Starting color value for interpolation.
 * @param col_end Ending color value for interpolation.
 * @return (int) Interpolated Color.
 */
int	get_color(float ratio, int col_start, int col_end)
{
	int	r;
	int	g;
	int	b;

	r = interpolate((col_start >> 16) & 0xFF, (col_end >> 16) & 0xFF, ratio);
	g = interpolate((col_start >> 8) & 0xFF, (col_end >> 8) & 0xFF, ratio);
	b = interpolate(col_start & 0xFF, col_end & 0xFF, ratio);
	return ((r << 16) | (g << 8) | b);
}

/**
 * @code 
 * void fill_color_map(int *col_line, char *line);
 * @endcond
 * @brief Fills an array with color values converted from a string of \
 * @brief hex color codes.
 * @param *col_line Pointer to an array of integers to store the color values.
 * @param *line Pointer to the string to be split and converted to color values.
 * @return (void) Color Array Filled.
 */
void	fill_color_map(int *col_line, char *line)
{
	char	**nums;
	char	**num;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i] != NULL)
	{
		num = ft_split(nums[i], ',');
		if (num[1] != NULL)
			col_line[i] = hex_to_int(num[1]);
		else
			col_line[i] = 0xffffff;
		free_strs(num);
		free(nums[i]);
		i++;
	}
	free(nums);
}

/**
 * @code 
 * void read_color(char *file_name, t_fdf *data);
 * @endcond
 * @brief Reads color data from a file and fills the color map in the \ 
 * @brief FDF data structure.
 * @param *file_name Pointer to the name of the file to be read.
 * @param *data Pointer to the FDF data structure to store the color map.
 * @return (void) Color Data Read.
 */
void	read_color(char *file_name, t_fdf *data)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	data->color_map = (int **)malloc(sizeof(int *) * (data->height));
	while (i < data->height - 1)
		data->color_map[i++] = (int *)malloc(sizeof(int) * (data->width + 2));
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (i < data->height - 1)
	{
		fill_color_map(data->color_map[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	data->color_map[i] = NULL;
	close(fd);
}

/**
 * @code 
 * void print_color_map(t_fdf *data);
 * @endcond
 * @brief Prints the color map to the console, showing color values for \ 
 * @brief each point in the map.
 * @param *data Pointer to the FDF data structure containing the color map.
 * @return (void) Color Map Printed.
 */
void	print_color_map(t_fdf *data)
{
	int	i;
	int	j;

	ft_printf("\nHeight: %d\n Width: %d\n", data->height, data->width);
	i = 0;
	while (i < (data->height - 1))
	{
		j = 0;
		while (j < (data->width))
		{
			ft_printf("%i ", data->color_map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
