/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:08:31 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/20 18:45:05 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @code 
 * void	image_controls(int key, t_fdf *data);
 * @endcond
 * @brief This function updates structures values based on the pessed keys \
 * @brief altering the value; clears the image by overwriting the values with \
 * @brief pixels and finally redraws the image with the updated values and puts \
 * @brief the drawing to the window.
 * @param *pt1 Pointer to the 1st point.
 * @param *pt2 Pointer to the 2nd point.
 * @param *data Pointer to the data structure.
 * @return (void).
 */
void	image_controls(int key, t_fdf *data)
{
	if (key == 65361)
		data->shift_x -= 10;
	if (key == 65362)
		data->shift_y -= 10;
	if (key == 65363)
		data->shift_x += 10;
	if (key == 65364)
		data->shift_y += 10;
	if (key == 122)
		data->zoom += 5;
	if (key == 120)
		data->zoom -= 5;
	if (key == 99)
		data->steepness += 1;
	if (key == 118)
		data->steepness -= 1;
	if (key == 112)
		data->projection = 'p';
	if (key == 105)
		data->projection = 'i';
	clear_image(data, 0x00000000);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_data.img, 0, 0);
}

/**
 * @code
 * void	set_zoom(t_pt *pt1, t_pt *pt2, t_fdf *data);
 * @endcond
 * @brief This function updates the zoom values after they've been altered.
 * @param *pt1 Pointer to the 1st point.
 * @param *pt2 Pointer to the 2nd point.
 * @param *data Pointer to the data structure.
 * @return (void).
 */
void	set_zoom(t_pt *pt1, t_pt *pt2, t_fdf *data)
{
	pt1->x *= data->zoom;
	pt1->y *= data->zoom;
	pt2->x *= data->zoom;
	pt2->y *= data->zoom;
}

/**
 * @brief This function updates the shift X and Y values after they've \
 * @brief altered.
 * @param *pt1 Pointer to the 1st point.
 * @param *pt2 Pointer to the 2nd point.
 * @param *data Pointer to the data structure.
 * @return (void).
 */
void	set_shift(t_pt *pt1, t_pt *pt2, t_fdf *data)
{
	pt1->x += data->shift_x;
	pt1->y += data->shift_y;
	pt2->x += data->shift_x;
	pt2->y += data->shift_y;
}

/**
 * @brief This function updates the z values after they've been altered.
 * @param *z Pointer to the height of point 1.
 * @param *z1 Pointer to the height of point 2.
 * @param *data Pointer to the data structure.
 * @return (void).
 */
void	set_steepness(int *z, int *z1, t_fdf *data)
{
	*z *= data->steepness;
	*z1 *= data->steepness;
}
