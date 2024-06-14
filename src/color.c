/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:19:05 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 21:28:03 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// Function to interpolate between two colors
static unsigned int	interpolate(unsigned int col1, unsigned int col2, float t)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (1 - t) * ((col1 >> 16) & 0xFF) + t * ((col2 >> 16) & 0xFF);
	g = (1 - t) * ((col1 >> 8) & 0xFF) + t * ((col2 >> 8) & 0xFF);
	b = (1 - t) * (col1 & 0xFF) + t * (col2 & 0xFF);
	return ((r << 16) | (g << 8) | b);
}

static void	col2(t_data *data, unsigned int *col)
{
	if (data->color_set == 3)
	{
		col[0] = 0xED4D6E;
		col[1] = 0xFF1493;
		col[2] = 0xFFFFFF;
		col[3] = 0xB3DEC1;
		col[4] = 0x8075FF;
		col[5] = 0xFF6B6C;
		col[6] = 0xF1BF98;
	}
	else if (data->color_set == 4)
	{
		col[0] = 0xF194B4;
		col[1] = 0x7F9183;
		col[2] = 0x1E00EF;
		col[3] = 0x766100;
		col[4] = 0xCA2D2B;
		col[5] = 0xE4FF1A;
		col[6] = 0xE9980C;
	}
}

static unsigned int	col(t_data *data, int index)
{
	unsigned int	col[7];

	if (data->color_set == 1)
	{
		col[0] = 0xFFFFFF;
		col[1] = 0xFF0000;
		col[2] = 0x0000FF;
		col[3] = 0x00FF00;
		col[4] = 0x00FF21;
		col[5] = 0xFFFF00;
		col[6] = 0xF35B04;
	}
	else if (data->color_set == 2)
	{
		col[0] = 0x000000;
		col[1] = 0x0000FF;
		col[2] = 0x00FF00;
		col[3] = 0xFF0000;
		col[4] = 0xFFFF00;
		col[5] = 0xFFFFFF;
		col[6] = 0x000000;
	}
	else
		col2(data, col);
	return (col[index]);
}

// Function to map step to a color
static unsigned int	map_color(t_data *data, int iter)
{
	float	gradient;
	int		index;
	float	portion;

	gradient = ((float)data->colors - 1) * iter / data->max_iter;
	index = (int)gradient;
	portion = gradient - index;
	if (index >= data->colors)
		return (col(data, data->colors - 1));
	return (interpolate(col(data, index), col(data, index + 1), portion));
}

// Function to create the color map
int	create_colormap(t_data *data)
{
	int	*out;
	int	iter;

	if (data->color_map)
		free(data->color_map);
	out = (int *)malloc((data->max_iter + 1) * sizeof(int));
	if (!out)
		return (0);
	data->color_map = out;
	iter = data->max_iter;
	*out = 0;
	while (iter--)
	{
		out++;
		*out = map_color(data, iter);
	}
	return (1);
}
