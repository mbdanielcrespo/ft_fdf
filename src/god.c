#include "../inc/fdf.h"

void	init_fdf(t_fdf *data)
{
	data->shift_x = 200;
	data->shift_y = 200;
	data->zoom = 25;
}

void	destroy_mlx(t_fdf *data)
{
	//if (data->mlx_ptr)
	//	mlx_destroy_image(data->mlx_ptr, data->win_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void    destroy_fdf(t_fdf *data)
{
	int i;

	i = 0;
	if (data)
	{
		while (data->z_data[i])
		{
			if (data->z_data[i])
				free(data->z_data[i]);
			i++;
		}
		if (data->z_data)
			free(data->z_data);
		free(data);
	}
}

void	destroy_all(t_fdf *data)
{
	destroy_mlx(data);
	destroy_fdf(data);
}