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

int hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') 
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 0;
}

int hex_to_int(const char *hex_str)
{
    int i;
	int base;
	int	res;

    i = 0;
    base = 1;
    res = 0;
    while (hex_str[i])
        i++;
    while (--i >= 2)
	{
        res += hex_char_to_int(hex_str[i]) * base;
        base *= 16;
    }
    return res;
}


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
	//char	**num;
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

void	fill_color_map(int *col_line, char *line)
{
	char **nums;
	char **num;
	int i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i] != NULL)
	{
		num = ft_split(nums[i], ',');
		if (num[1] != NULL)
			col_line[i] = hex_to_int(nums[1]);
		else
			col_line[i] = 0xffffff;
		free_strs(num);
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
		data->z_data[i++] = (int *)malloc(sizeof(int) * (data->width + 2));
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


void	read_color(char *file_name, t_fdf *data)
{
	int	i;
	char	*line;
	int fd;

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
/*
void	color_data(char *file_name, t_fdf *data)
{
		int	c;
		int fd;
		char	*line;

		c = 0;
		//fd = open(file_name, O_RDONLY);
		//line = get_next_line(fd);
		data->
		
		
}*/

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
		printf("\n");
		i++;
	}
}

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
			printf("%d ", data->color_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
