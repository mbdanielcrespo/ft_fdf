#ifndef FDF_H
# define FD F_H
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct	s_fdf
{
	int width;
	int height;
	int **z_data;
	int	zoom;
	int	color;

	void    *mlx_ptr;
	void    *win_ptr;
}				t_fdf;

void	breshenham(float x1, float y1, float x2, float y2, t_fdf *data);
void	read_file(char *file_name, t_fdf *data);
void	draw(t_fdf *data);
int		ft_max(int a, int b);
float	ft_abs(float a);

#endif