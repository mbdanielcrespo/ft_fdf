/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:31:46 by danalmei          #+#    #+#             */
/*   Updated: 2023/11/08 18:58:28 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

void	init_window(int width, int height, t_fdf *data)
{
	data->win_w = width;
	data->win_h = height;	
}

void	window_controls(int key, t_fdf *data)
{
	if (key == 65307)
		destroy_all(data);
}

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
	if (key == 97)
		data->alpha += 0.2;
	if (key == 100)
		data->alpha -= 0.2;
	if (key == 119)
		data->beta += 0.1;
	if (key == 115)
		data->beta -= 0.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

int	deal_key(int key, t_fdf *data)
{
	//ft_printf("key: %d\n", key);
	if (key != 65307)
		image_controls(key, data);
	else
		window_controls(key, data);
	return (0);
}

void	print_map(t_fdf *data)
{
	int	i;
	int j;

	ft_printf("\nHeight: %d\n Width: %d\n", data->height, data->width);
	i = 0;
	while (i < (data->height - 1))
	{
		j = 0;
		while (j < (data->width))
		{
			printf("%4d", data->z_data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
    t_fdf *data;

	if (argc != 2)
		ft_error("Invalid number of arguments!");
    data = (t_fdf*)malloc(sizeof(t_fdf));
	if (!data)
		ft_error("Error on memory allocation");
	read_file(argv[1], data);
	init_window(1200, 1200, data);
	printf("width: %d, height %d\n", data->win_w, data->width);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_w, data->win_h, "FDF");
	init_fdf(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}