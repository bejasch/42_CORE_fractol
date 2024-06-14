/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:29:00 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 12:02:18 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// julia set: shows one point complex point c in f_c(z) = z^2 + c for various z
int	julia(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	pixel.x = data->julia_x;
	pixel.y = data->julia_i;
	start.x = (x - 400) * data->pxl_size + data->center_x;
	start.y = (y - 400) * data->pxl_size + data->center_y;
	pixel.z = start.x * start.x;
	start.z = start.y * start.y;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z + start.z <= 4)
	{
		start.y = 2 * start.x * start.y + pixel.y;
		start.x = pixel.z - start.z + pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}

// julia enhanced 1
int	julia2(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	pixel.x = data->julia_x;
	pixel.y = data->julia_i;
	start.x = (x - 400) * data->pxl_size + data->center_x;
	start.y = (y - 400) * data->pxl_size + data->center_y;
	pixel.z = start.x * start.x;
	start.z = start.y * start.y;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z - start.z <= 4)
	{
		start.y = 2 * start.x * start.y + pixel.y;
		start.x = pixel.z - start.z + pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}

// julia enhanced 2
int	julia3(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	pixel.x = data->julia_x;
	pixel.y = data->julia_i;
	start.x = (x - 400) * data->pxl_size + data->center_x;
	start.y = (y - 400) * data->pxl_size + data->center_y;
	pixel.z = start.x * start.x;
	start.z = start.y * start.y;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z + start.z <= 4)
	{
		start.y = start.x * start.y + pixel.y;
		start.x = pixel.z - start.z + pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}

// julia enhanced 3
int	julia4(t_data *data, int x, int y)
{
	t_point	pixel;
	t_point	start;
	int		max_iter;

	pixel.x = data->julia_x;
	pixel.y = data->julia_i;
	start.x = (x - 400) * data->pxl_size + data->center_x;
	start.y = (y - 400) * data->pxl_size + data->center_y;
	pixel.z = start.x * start.x;
	start.z = start.y * start.y;
	max_iter = data->max_iter + 1;
	while (--max_iter && pixel.z + start.z <= 4)
	{
		start.y = 2 * start.x * start.y + pixel.y;
		start.x = pixel.z - start.z - pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}
