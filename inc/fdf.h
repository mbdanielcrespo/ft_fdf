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

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_data;
	int		**color_map;
	int		zoom;
	int		steepness;
	int		shift_x;
	int		shift_y;
	char	projection;
	t_data	img_data;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

//Init
void	init_fdf(char *file_name, t_fdf *data);
// Main
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	clear_image(t_fdf *data, int color);
// Seters
void	image_controls(int key, t_fdf *data);
int		get_color(float ratio, int col_start, int col_end);
void	set_zoom(t_pt *pt1, t_pt *pt2, t_fdf *data);
void	set_shift(t_pt *pt1, t_pt *pt2, t_fdf *data);
void	set_steepness(int *z, int *z1, t_fdf *data);
// Projection
int		interpolate(int start, int end, float ratio);
void	set_isometric(t_pt *p, int z);
void	set_parallel(t_pt *p, int z);
void	projection(t_pt *pt1, t_pt *pt2, t_pt zpt, t_fdf *data);
// Draw algo
void	breshenham(t_pt pt1, t_pt pt2, t_fdf *data, t_pt color);
void	draw_line(t_pt pt1, t_pt pt2, t_fdf *data);
void	draw2(t_pt *pt1, t_pt *pt2, t_pt *curr_pt, t_fdf *data);
void	draw(t_fdf *data);
// ZDataRead
int		get_height(char *file_name);
int		get_width(char *file_name);
void	fill_z_data(int	*z_line, char *line);
void	read_file(char *file_name, t_fdf *data);
void	print_map(t_fdf *data);
// ColorRead
int		hex_char_to_int(char c);
int		hex_to_int(char *hex_str);
void	fill_color_map(int *col_line, char *line);
void	read_color(char *file_name, t_fdf *data);
void	print_color_map(t_fdf *data);
// GOD file
void	free_strs(char **strs);
void	destroy_mlx(t_fdf *data);
void	destroy_fdf(t_fdf *data);
void	destroy_all(t_fdf *data);

#endif