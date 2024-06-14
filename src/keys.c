/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:04:22 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 21:08:53 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	keys(int key, t_data *data)
{
	if (key == XK_1)
		data->set = 1;
	else if (key == XK_2)
		data->set = 2;
	else if (key == XK_3)
		data->set = 3;
	else if (key == XK_4)
		data->set = 4;
	else if (key == XK_5)
		data->set = 5;
	else if (key == XK_6)
		data->set = 6;
	else if (key == XK_7)
		data->set = 7;
	else if (key == XK_x)
		data->subset = 0;
	else if (key == XK_c)
		data->subset = 1;
	else if (key == XK_v)
		data->subset = 2;
	else if (key == XK_b)
		data->subset = 3;
}

static void	keys2(int key, t_data *data)
{
	if (key == XK_s)
		data->angle_x -= 0.1;
	else if (key == XK_w)
		data->angle_x += 0.1;
	else if (key == XK_a)
		data->angle_y -= 0.1;
	else if (key == XK_d)
		data->angle_y += 0.1;
	else if (key == XK_q)
		data->angle_z -= 0.1;
	else if (key == XK_e)
		data->angle_z += 0.1;
	else if (key == XK_Up)
		data->center_y -= 50 * data->pxl_size;
	else if (key == XK_Down)
		data->center_y += 50 * data->pxl_size;
	else if (key == XK_Left)
		data->center_x -= 50 * data->pxl_size;
	else if (key == XK_Right)
		data->center_x += 50 * data->pxl_size;
	else if (key == XK_n && data->depth > 1)
		data->depth -= 1;
	else if (key == XK_m)
		data->depth += 1;
}

static void	keys3(int key, t_data *data)
{
	if (key == XK_F1 && data->max_iter > 10)
		data->max_iter -= 10;
	else if (key == XK_F5)
		data->max_iter += 10;
	else if (key == XK_F2 && data->max_iter > 50)
		data->max_iter -= 50;
	else if (key == XK_F6)
		data->max_iter += 50;
	else if (key == XK_F3 && data->max_iter > 200)
		data->max_iter -= 200;
	else if (key == XK_F7)
		data->max_iter += 200;
	else if (key == XK_F4 && data->max_iter > 500)
		data->max_iter -= 500;
	else if (key == XK_F8)
		data->max_iter += 500;
	else if (key == XK_r && data->color_set > 1)
		data->color_set -= 1;
	else if (key == XK_t && data->color_set < 4)
		data->color_set += 1;
	else if (key == XK_f && data->colors > 1)
		data->colors -= 1;
	else if (key == XK_g && data->colors < 7)
		data->colors += 1;
	create_colormap(data);
}

int	handle_input(int key, t_data *data)
{
	if (key == XK_Escape)
		return (close_window(data));
	else if (key == XK_space)
	{
		data->center_x = 0;
		data->center_y = 0;
		data->pxl_size = 0.004;
	}
	else if (key == XK_1 || key == XK_2 || key == XK_3 || key == XK_4
		|| key == XK_5 || key == XK_6 || key == XK_7
		|| key == XK_x || key == XK_c || key == XK_v || key == XK_b)
		keys(key, data);
	else if (key == XK_s || key == XK_w || key == XK_a || key == XK_d
		|| key == XK_q || key == XK_e || key == XK_Up || key == XK_Down
		|| key == XK_Left || key == XK_Right || key == XK_n || key == XK_m)
		keys2(key, data);
	else if (key == XK_F1 || key == XK_F2 || key == XK_F3 || key == XK_F4
		|| key == XK_F5 || key == XK_F6 || key == XK_F7 || key == XK_F8
		|| key == XK_r || key == XK_t || key == XK_f || key == XK_g)
		keys3(key, data);
	calculate_screen(data);
	return (0);
}
