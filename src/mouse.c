/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:17:02 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 11:39:54 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// Function to handle the mouse-move event
int	mouse_move(int x, int y, t_data *data)
{
	if (abs(x - data->xs) > 3 || abs(y - data->ys) > 3)
	{
		if (data->set == 5 || data->set == 6)
		{
			data->julia_x = ((double)(x - 400)) * 0.004;
			data->julia_i = ((double)(y - 400)) * 0.004;
			calculate_screen(data);
		}
		else if (data->set == 7)
		{
			if (x - data->xs > 3)
				data->angle_x += 0.1;
			else if (x - data->xs < -3)
				data->angle_x -= 0.1;
			if (y - data->ys > 3)
				data->angle_y += 0.1;
			else if (y - data->ys < -3)
				data->angle_y -= 0.1;
			calculate_screen(data);
		}
		data->xs = x;
		data->ys = y;
	}
	return (0);
}

static void	zoom_in(t_data *data, int x, int y, double zoom)
{
	data->center_x += ((double)(x - 400)) * zoom * data->pxl_size;
	data->center_y += ((double)(y - 400)) * zoom * data->pxl_size;
	data->pxl_size *= 1 - zoom;
}

static void	zoom_out(t_data *data, int x, int y, double zoom)
{
	data->pxl_size /= 1 - zoom;
	data->center_x -= ((double)(x - 400)) * zoom * data->pxl_size;
	data->center_y -= ((double)(y - 400)) * zoom * data->pxl_size;
}

// mouse click and wheel
int	button_press(int button, int x, int y, t_data *data)
{
	if (button == 1 && (data->set == 2 || data->set == 4))
	{
		data->julia_x = ((double)(x - 400)) * 0.004;
		data->julia_i = ((double)(y - 400)) * 0.004;
	}
	else if (button == 2)
		zoom_out(data, x, y, 0.6);
	else if (button == 3)
		zoom_in(data, x, y, 0.6);
	else if (data->set == 7 && button == 4)
		data->angle_z += 0.1;
	else if (button == 4)
		zoom_in(data, x, y, 0.1);
	else if (data->set == 7 && button == 5)
		data->angle_z -= 0.1;
	else if (button == 5)
		zoom_out(data, x, y, 0.1);
	calculate_screen(data);
	return (0);
}
