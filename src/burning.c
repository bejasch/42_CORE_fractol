/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:36:58 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 11:58:30 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// -recursion: f_c(z) = (|zx|+|zi|)^2 + c, starting from z = 0 + 0i
int	burning_ship(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	pixel.x = ((double)(x - 400)) * data->pxl_size + data->center_x;
	pixel.y = ((double)(y - 400)) * data->pxl_size + data->center_y;
	start.x = 0;
	start.y = 0;
	pixel.z = 0;
	start.z = 0;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z + start.z <= 4)
	{
		start.y = fabs(2 * start.x * start.y) + pixel.y;
		start.x = pixel.z - start.z + pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}

// variation 1
int	burning_ship2(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	pixel.x = ((double)(x - 400)) * data->pxl_size + data->center_x;
	pixel.y = ((double)(y - 400)) * data->pxl_size + data->center_y;
	start.x = 0;
	start.y = 0;
	pixel.z = 0;
	start.z = 0;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z - start.z <= 4)
	{
		start.y = fabs(2 * start.x * start.y) + pixel.y;
		start.x = pixel.z - start.z + pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}

// variation 2
int	burning_ship3(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	pixel.x = ((double)(x - 400)) * data->pxl_size + data->center_x;
	pixel.y = ((double)(y - 400)) * data->pxl_size + data->center_y;
	start.x = 0;
	start.y = 0;
	pixel.z = 0;
	start.z = 0;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z + start.z <= 4)
	{
		start.y = fabs(start.x * start.y) + pixel.y;
		start.x = pixel.z - start.z + pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}

// variation 3
int	burning_ship4(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	pixel.x = ((double)(x - 400)) * data->pxl_size + data->center_x;
	pixel.y = ((double)(y - 400)) * data->pxl_size + data->center_y;
	start.x = 0;
	start.y = 0;
	pixel.z = 0;
	start.z = 0;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z + start.z <= 4)
	{
		start.y = fabs(2 * start.x * start.y) + pixel.y;
		start.x = pixel.z - start.z - pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}
