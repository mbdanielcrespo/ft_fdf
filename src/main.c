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

#include "fdf.h"

int	close_window(t_fdf *data)
{
	destroy_all(data);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > 600 || y > 600)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	deal_key(int key, t_fdf *data)
{
	if (key != 65307)
		image_controls(key, data);
	else
		destroy_all(data);
	return (0);
}

int	invalid_read(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	t_data	img;

	if (argc != 2)
		ft_error("Invalid number of arguments!");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		ft_error("Error on memory allocation");
	if (invalid_read(argv[1]))
		ft_error("Invalid read of arguments!");
	init_fdf(argv[1], data);
	ft_printf("Opening window ...\n");
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 600, "FDF");
	img.img = mlx_new_image(data->mlx_ptr, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	data->img_data = img;
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.img, 0, 0);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
