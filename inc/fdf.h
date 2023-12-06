/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:04:46 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/06 15:04:46 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <mlx_int.h>
# include <libft.h>

typedef struct s_pt
{
	float	x;
	float	y;
}	t_pt;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_data;
	int		zoom;
	int		color;
	int		steepness;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

// Seters
void	set_color(int z, int z1, t_fdf *data);
void	set_zoom(t_pt *pt1, t_pt *pt2, t_fdf *data);
void	set_shift(t_pt *pt1, t_pt *pt2, t_fdf *data);
void	set_steepness(int *z, int *z1, t_fdf *data);
void	set_isometric(t_pt *p, int z);
// Draw algo
void	breshenham(t_pt pt1, t_pt pt2, t_fdf *data);
void	read_file(char *file_name, t_fdf *data);
void	draw(t_fdf *data);
int		ft_max(int a, int b);
float	ft_abs(float a);
void	init_fdf(t_fdf *data);
// GOD file
void	destroy_mlx(t_fdf *data);
void	destroy_fdf(t_fdf *data);
void	destroy_all(t_fdf *data);

#endif