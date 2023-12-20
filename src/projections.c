/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:46:10 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/20 19:01:59 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @code 
 * void set_isometric(t_pt *p, int z);
 * @endcond
 * @brief Converts the point's coordinates to isometric projection.
 * @param *p Pointer to a point structure.
 * @param z Height value affecting the isometric transformation.
 * @return (void) Projection Applied.
 */
void	set_isometric(t_pt *p, int z)
{
	p->x = (p->x - p->y) * cos(0.8);
	p->y = (p->x + p->y) * sin(0.8) - z;
}

/**
 * @code 
 * void set_parallel(t_pt *p, int z);
 * @endcond
 * @brief Converts the point's coordinates to parallel projection.
 * @param *p Pointer to a point structure.
 * @param z Height value affecting the parallel transformation.
 * @return (void) Projection Applied.
 */
void	set_parallel(t_pt *p, int z)
{
	p->x = p->x - z;
	p->y = p->y - z;
}

/**
 * @code 
 * void projection(t_pt *pt1, t_pt *pt2, t_pt zpt, t_fdf *data);
 * @endcond
 * @brief Applies the selected projection (isometric or parallel) to two points.
 * @param *pt1 Pointer to the first point structure.
 * @param *pt2 Pointer to the second point structure.
 * @param zpt Structure holding height values for the transformations.
 * @param *data Pointer to the data structure containing projection type.
 * @return (void) Projection Applied.
 */
void	projection(t_pt *pt1, t_pt *pt2, t_pt zpt, t_fdf *data)
{
	if (data->projection == 'i')
	{
		set_isometric(pt1, zpt.x);
		set_isometric(pt2, zpt.y);
	}
	else if (data->projection == 'p')
	{
		set_parallel(pt1, zpt.x);
		set_parallel(pt2, zpt.y);
	}
}
