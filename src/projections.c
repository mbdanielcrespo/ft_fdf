#include "fdf.h"

void	set_isometric(t_pt *p, int z)
{
	p->x = (p->x - p->y) * cos(0.8);
	p->y = (p->x + p->y) * sin(0.8) - z;
}

void	set_parallel(t_pt *p, int z)
{
	p->x = p->x - z;
	p->y = p->y - z;
}

void	projection(t_pt *pt1, t_pt *pt2, t_pt zpt, t_fdf *data)
{
	char	proj;

	proj = data->projection;
	if (proj == 'i')
	{
		set_isometric(pt1, zpt.x);
		set_isometric(pt2, zpt.y);
	}
	else if (proj == 'p')
	{
		set_parallel(pt1, zpt.x);
		set_parallel(pt2, zpt.y);
	}
}