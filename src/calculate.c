/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:32:35 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 11:36:02 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_mandelbrot(t_data *data)
{
	int	x;
	int	y;

	y = 800;
	while (y--)
	{
		x = 800;
		while (x--)
		{
			if (!data->subset)
				put_to_back(data, x, y, mandelbrot(data, x, y));
			else if (data->subset == 1)
				put_to_back(data, x, y, mandelbrot2(data, x, y));
			else if (data->subset == 2)
				put_to_back(data, x, y, mandelbrot3(data, x, y));
			else if (data->subset == 3)
				put_to_back(data, x, y, mandelbrot4(data, x, y));
		}
	}
}

void	draw_burning(t_data *data)
{
	int	x;
	int	y;

	y = 800;
	while (y--)
	{
		x = 800;
		while (x--)
		{
			if (!data->subset)
				put_to_back(data, x, y, burning_ship(data, x, y));
			else if (data->subset == 1)
				put_to_back(data, x, y, burning_ship2(data, x, y));
			else if (data->subset == 2)
				put_to_back(data, x, y, burning_ship3(data, x, y));
			else if (data->subset == 3)
				put_to_back(data, x, y, burning_ship4(data, x, y));
		}
	}
}

void	draw_julia(t_data *data)
{
	int	x;
	int	y;

	y = 800;
	while (y--)
	{
		x = 800;
		while (x--)
		{
			if (!data->subset)
				put_to_back(data, x, y, julia(data, x, y));
			else if (data->subset == 1)
				put_to_back(data, x, y, julia2(data, x, y));
			else if (data->subset == 2)
				put_to_back(data, x, y, julia3(data, x, y));
			else if (data->subset == 3)
				put_to_back(data, x, y, julia4(data, x, y));
		}
	}
}

void	draw_jurning(t_data *data)
{
	int	x;
	int	y;

	y = 800;
	while (y--)
	{
		x = 800;
		while (x--)
		{
			if (!data->subset)
				put_to_back(data, x, y, burning_julia(data, x, y));
			else if (data->subset == 1)
				put_to_back(data, x, y, burning_julia2(data, x, y));
			else if (data->subset == 2)
				put_to_back(data, x, y, burning_julia3(data, x, y));
			else if (data->subset == 3)
				put_to_back(data, x, y, burning_julia4(data, x, y));
		}
	}
}
