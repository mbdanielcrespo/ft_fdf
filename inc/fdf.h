#ifndef FDF_H
# define FTF_H
# include <stdio.h>
# include <fcntl.h>
# include "../libft/ft_libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/ft_get_next_line/get_next_line.h"

typedef struct	s_fdf
{
    int width;
    int height;
    int **z_data;

    void    *mlx_ptr;
    void    *win_ptr;
}				t_fdf;

void    read_file(char *file_name, t_fdf *data);

#endif