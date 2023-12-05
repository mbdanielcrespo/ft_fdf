
#include "../inc/fdf.h"

void	init_fdf(t_fdf *data)
{
	data->shift_x = data->win_w / 2;
	data->shift_y = 0;
	data->zoom = 25;
	data->steepness = 1;
}

void	destroy_mlx(t_fdf *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}

void    destroy_fdf(t_fdf *data)
{
	int i;

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