/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:08:31 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/07 17:12:02 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_zoom(t_pt *pt1, t_pt *pt2, t_fdf *data)
{
	pt1->x *= data->zoom;
	pt1->y *= data->zoom;
	pt2->x *= data->zoom;
	pt2->y *= data->zoom;
}

void	set_shift(t_pt *pt1, t_pt *pt2, t_fdf *data)
{
	pt1->x += data->shift_x;
	pt1->y += data->shift_y;
	pt2->x += data->shift_x;
	pt2->y += data->shift_y;
}

void	set_steepness(int *z, int *z1, t_fdf *data)
{
	*z *= data->steepness;
	*z1 *= data->steepness;
}
