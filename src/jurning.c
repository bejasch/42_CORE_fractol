/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jurning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:18:33 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 12:09:04 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// a burning-ship-like adaption of the julia sets
int	burning_julia(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	start.x = data->julia_x;
	start.y = data->julia_i;
	pixel.x = ((double)(x - 400)) * data->pxl_size + data->center_x;
	pixel.y = ((double)(y - 400)) * data->pxl_size + data->center_y;
	pixel.z = pixel.x * pixel.x;
	start.z = pixel.y * pixel.y;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z + start.z <= 4)
	{
		pixel.y = fabs(2 * pixel.x * pixel.y) + start.y;
		pixel.x = pixel.z - start.z + start.x;
		pixel.z = pixel.x * pixel.x;
		start.z = pixel.y * pixel.y;
	}
	return (data->color_map[max_iter]);
}

// enhanced version of the burning-julia set
int	burning_julia2(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	start.x = data->julia_x;
	start.y = data->julia_i;
	pixel.x = ((double)(x - 400)) * data->pxl_size + data->center_x;
	pixel.y = ((double)(y - 400)) * data->pxl_size + data->center_y;
	pixel.z = pixel.x * pixel.x;
	start.z = pixel.y * pixel.y;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z - start.z <= 4)
	{
		pixel.y = fabs(2 * pixel.x * pixel.y) + start.y;
		pixel.x = pixel.z - start.z + start.x;
		pixel.z = pixel.x * pixel.x;
		start.z = pixel.y * pixel.y;
	}
	return (data->color_map[max_iter]);
}

// enhanced version of the burning-julia set
int	burning_julia3(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	start.x = data->julia_x;
	start.y = data->julia_i;
	pixel.x = ((double)(x - 400)) * data->pxl_size + data->center_x;
	pixel.y = ((double)(y - 400)) * data->pxl_size + data->center_y;
	pixel.z = pixel.x * pixel.x;
	start.z = pixel.y * pixel.y;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z + start.z <= 4)
	{
		pixel.y = fabs(pixel.x * pixel.y) + start.y;
		pixel.x = pixel.z - start.z + start.x;
		pixel.z = pixel.x * pixel.x;
		start.z = pixel.y * pixel.y;
	}
	return (data->color_map[max_iter]);
}

// enhanced version of the burning-julia set
int	burning_julia4(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	start.x = data->julia_x;
	start.y = data->julia_i;
	pixel.x = ((double)(x - 400)) * data->pxl_size + data->center_x;
	pixel.y = ((double)(y - 400)) * data->pxl_size + data->center_y;
	pixel.z = pixel.x * pixel.x;
	start.z = pixel.y * pixel.y;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z + start.z <= 4)
	{
		pixel.y = fabs(2 * pixel.x * pixel.y) + start.y;
		pixel.x = pixel.z - start.z - start.x;
		pixel.z = pixel.x * pixel.x;
		start.z = pixel.y * pixel.y;
	}
	return (data->color_map[max_iter]);
}
