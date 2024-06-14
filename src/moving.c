/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:32:35 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 11:36:02 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	draw_movingjulia(t_data *data)
{
	int	x;
	int	y;

	y = 800;
	if (data->subset == 1)
	{
		while (y--)
		{
			x = 800;
			while (x--)
				put_to_back(data, x, y, julia2(data, x, y));
		}
	}
	else
	{
		while (y--)
		{
			x = 800;
			while (x--)
				put_to_back(data, x, y, julia3(data, x, y));
		}
	}
}

static void	draw_mourning(t_data *data)
{
	int	x;
	int	y;

	y = 800;
	if (data->subset == 1)
	{
		while (y--)
		{
			x = 800;
			while (x--)
				put_to_back(data, x, y, burning_julia2(data, x, y));
		}
	}
	else
	{
		while (y--)
		{
			x = 800;
			while (x--)
				put_to_back(data, x, y, burning_julia3(data, x, y));
		}
	}
}

void	draw_moving(t_data *data, int x, int y)
{
	if (data->set == 5 && data->subset == 0)
	{
		while (y--)
		{
			x = 800;
			while (x--)
				put_to_back(data, x, y, julia(data, x, y));
		}
	}
	else if (data->set == 5)
		draw_movingjulia(data);
	else if (data->set == 6 && data->subset == 0)
	{
		while (y--)
		{
			x = 800;
			while (x--)
				put_to_back(data, x, y, burning_julia(data, x, y));
		}
	}
	else
		draw_mourning(data);
}
