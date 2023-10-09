#include "../inc/fdf.h"

/*void	test_gnl(char *filename)
{
	int	fd;
	char *line;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
}*/

int main(int argc, char **argv)
{
    t_fdf *data;
	//char *line;
	//int	fd;
	int	i;
	int	j;

    data = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	if (argc > 2)
		printf("Too many arguments!");
	i = 0;
	printf("Height: %d\n Width: %d\n", data->height, data->width);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}