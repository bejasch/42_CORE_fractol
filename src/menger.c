/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:05:09 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 11:28:23 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	rotate_x(t_point *p, double angle)
{
	double	y;
	double	z;

	y = p->y;
	z = p->z;
	p->y = y * cos(angle) - z * sin(angle);
	p->z = y * sin(angle) + z * cos(angle);
}

static void	rotate_y(t_point *p, double angle)
{
	double	x;
	double	z;

	x = p->x;
	z = p->z;
	p->x = x * cos(angle) + z * sin(angle);
	p->z = -x * sin(angle) + z * cos(angle);
}

static void	rotate_z(t_point *p, double angle)
{
	double	x;
	double	y;

	x = p->x;
	y = p->y;
	p->x = x * cos(angle) - y * sin(angle);
	p->y = x * sin(angle) + y * cos(angle);
}

static void	inner_menger(t_data *data, t_point p, double size, int depth)
{
	int	x;
	int	y;
	int	z;

	if (depth)
		return (draw_menger(data, p, size, depth - 1));
	x = p.x;
	y = p.y;
	z = p.z;
	rotate_x(&p, data->angle_x);
	rotate_y(&p, data->angle_y);
	rotate_z(&p, data->angle_z);
	if (x + y + z > 0 && x - y + z > 0 && x + y - z > 0)
		put_to_back(data, (int)(p.x + 400), (int)(p.y + 400), 0xFFFFFF);
	else if (x + y + z > 0 && x - y + z > 0)
		put_to_back(data, (int)(p.x + 400), (int)(p.y + 400), 0xF6F930);
	else if (x + y + z > 0)
		put_to_back(data, (int)(p.x + 400), (int)(p.y + 400), 0xF62DAE);
	else
		put_to_back(data, (int)(p.x + 400), (int)(p.y + 400), 0x7CFFC4);
}

void	draw_menger(t_data *data, t_point origin, double size, int depth)
{
	int		i;
	int		j;
	int		k;
	t_point	new;

	if (depth)
		size /= 3;
	i = -2;
	while (i++ < 1)
	{
		j = -2;
		while (j++ < 1)
		{
			k = -2;
			while (k++ < 1)
			{
				if (abs(i) + abs(j) + abs(k) > 1)
					continue ;
				new.x = origin.x + i * size;
				new.y = origin.y + j * size;
				new.z = origin.z + k * size;
				inner_menger(data, new, size, depth);
			}
		}
	}
}
