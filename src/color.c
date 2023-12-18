

#include "fdf.h"

int hex_char_to_int(char c)
{
    if (c >= '0' && c <= '9') 
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 0;
}

int hex_to_int(char *hex_str)
{
    int i;
	int base;
	int	res;

    i = 0;
    base = 1;
    res = 0;
    while (hex_str[i])
        i++;
    while (--i >= 2)
	{
        res += hex_char_to_int(hex_str[i]) * base;
        base *= 16;
    }
    return (res);
}

void	fill_color_map(int *col_line, char *line)
{
	char **nums;
	char **num;
	int i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i] != NULL)
	{
		num = ft_split(nums[i], ',');
		if (num[1] != NULL)
			col_line[i] = hex_to_int(num[1]);
		else
			col_line[i] = 0xffffff;
		free_strs(num);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_color(char *file_name, t_fdf *data)
{
	int	i;
	char	*line;
	int fd;

	i = 0;
	data->color_map = (int **)malloc(sizeof(int *) * (data->height));
	while (i < data->height - 1)
		data->color_map[i++] = (int *)malloc(sizeof(int) * (data->width + 2));
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (i < data->height - 1)
	{
		fill_color_map(data->color_map[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	data->color_map[i] = NULL;
	close(fd);
}

void	print_color_map(t_fdf *data)
{
	int	i;
	int	j;

	ft_printf("\nHeight: %d\n Width: %d\n", data->height, data->width);
	i = 0;
	while (i < (data->height - 1))
	{
		j = 0;
		while (j < (data->width))
		{
			ft_printf("%i ", data->color_map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
