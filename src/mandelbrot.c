/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:16:44 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 12:07:17 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// mandelbrot-recursion: f_c(z) = z^2 + c, starting from z = 0 + 0i
int	mandelbrot(t_data *data, int x, int y)
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
		start.y = 2 * start.x * start.y + pixel.y;
		start.x = pixel.z - start.z + pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}

// mandelbrot enhanced 1
int	mandelbrot2(t_data *data, int x, int y)
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
		start.y = 2 * start.x * start.y + pixel.y;
		start.x = pixel.z - start.z + pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}

// mandelbrot enhanced 2
int	mandelbrot3(t_data *data, int x, int y)
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
		start.y = start.x * start.y + pixel.y;
		start.x = pixel.z - start.z + pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}

// mandelbrot enhanced 3
int	mandelbrot4(t_data *data, int x, int y)
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
		start.y = 2 * start.x * start.y + pixel.y;
		start.x = pixel.z - start.z - pixel.x;
		pixel.z = start.x * start.x;
		start.z = start.y * start.y;
	}
	return (data->color_map[max_iter]);
}
