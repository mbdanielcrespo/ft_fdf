/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:58:06 by danalmei          #+#    #+#             */
/*   Updated: 2023/12/19 13:01:28 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
