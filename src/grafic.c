/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:30:56 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 10:35:13 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// Function to put a pixel in the image buffer
void	put_to_back(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < 800 && y >= 0 && y < 800)
		*(int *)(data->img_data + y * data->size_line + x * 4) = color;
}

void	clear_image(t_data *data)
{
	int	x;
	int	y;

	y = 800;
	while (y--)
	{
		x = 800;
		while (x--)
			put_to_back(data, x, y, 0);
	}
}

void	calculate_screen(t_data *data)
{
	if (data->set == 1)
		draw_mandelbrot(data);
	else if (data->set == 2)
		draw_julia(data);
	else if (data->set == 3)
		draw_burning(data);
	else if (data->set == 4)
		draw_jurning(data);
	else if (data->set == 5 || data->set == 6)
		draw_moving(data, 800, 800);
	else
	{
		clear_image(data);
		draw_menger(data, (t_point){0, 0, 0}, 800, data->depth);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
