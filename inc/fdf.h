#ifndef FDF_H
# define FTF_H
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

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