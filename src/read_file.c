/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:30:10 by danalmei          #+#    #+#             */
/*   Updated: 2023/11/08 16:29:31 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	line = "init";
	while (line != NULL)
	{
		line = get_next_line(fd);
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;
	char	**wrds;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	wrds = ft_split(line, ' ');
	while (wrds[width] != NULL)
	{
		free(wrds[width]);
		width++;
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	free(wrds);
	close(fd);
	return (width);
}

void	fill_z_data(int	*z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i] != NULL)
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_data = (int **)malloc(sizeof(int *) * (data->height));
	while (i < data->height - 1)
		data->z_data[i++] = (int *)malloc((sizeof(int) * (data->width + 2)));
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (i < data->height - 1)
	{
		fill_z_data(data->z_data[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	data->z_data[i] = NULL;
	close(fd);
}

void	print_map(t_fdf *data)
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
			printf("%3d ", data->z_data[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
