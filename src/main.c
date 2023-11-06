/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:31:46 by danalmei          #+#    #+#             */
/*   Updated: 2023/11/06 17:59:48 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"
/*
int	deal_key(int key, void *data)
{
	ft_printf("%d\n", key); 
	return (0);
}*/

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
			printf("%3d", data->z_data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
    t_fdf *data;

    data = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	ft_printf("File read correctly!\n");
	if (argc > 2)
		printf("Too many arguments!\n");
	ft_printf("Opening window ...\n");
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 500, 500, "FDF");
	data->zoom = 20;
	draw(data);
	//mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
}