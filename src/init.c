/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:58:06 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/20 19:03:41 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @code 
 * void init_fdf(char *file_name, t_fdf *data);
 * @endcond
 * @brief Initializes the FDF data structure with values from a file \
 * @brief and default settings. Reads file for map and color data, sets \
 * @brief values for shift, zoom, steepness, and projection.
 * @param *file_name Pointer to the name of the file to be read.
 * @param *data Pointer to the FDF data structure to be initialized.
 * @return (void) Data Initialized.
 */
void	init_fdf(char *file_name, t_fdf *data)
{
	read_file(file_name, data);
	read_color(file_name, data);
	data->shift_x = 300;
	data->shift_y = 300;
	data->zoom = 25;
	data->steepness = 3;
	data->projection = 'i';
}
