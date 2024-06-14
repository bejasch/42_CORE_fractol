/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:49:45 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 21:28:57 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

char	ft_strcmp(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}

double	ft_atod(const char *str)
{
	double	sign;
	double	res_a;
	double	res_b;
	double	tmp;

	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	res_a = 0;
	while (*str >= '0' && *str <= '9')
		res_a = 10 * res_a + *(str++) - '0';
	if (*(str++) != '.')
		return (res_a * sign);
	res_b = 0;
	tmp = 1;
	while (*str >= '0' && *str <= '9')
	{
		tmp /= 10;
		res_b += tmp * (*str - '0');
		str++;
	}
	return ((res_a + res_b) * sign);
}

// Function to handle the close event
int	close_window(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->color_map)
		free(data->color_map);
	exit(1);
	return (0);
}

void	instructions(void)
{
	write(1, "\n\t --->> ### INSTRUCTIONS ### <<---\n", 37);
	write(1, " -> Mouse-wheel (right/middle click) to zoom in and out\n", 57);
	write(1, " -> Arrow keys to move inside the fractals\n", 44);
	write(1, " -> 'space' key to reset the view\n", 35);
	write(1, " -> Use r / t to change the color palette\n", 43);
	write(1, " -> Use f / g to change the amount of used colors\n", 51);
	write(1, "\n -> Number keys 1-7 to switch between fractals:\n", 50);
	write(1, "    • 1: Mandelbrot\n", 23);
	write(1, "    • 2: Julia set (left-click screen to change)\n", 52);
	write(1, "    • 3: Burning Ship fractal\n", 33);
	write(1, "    • 4: Julia-Ship (clickable Burning Ship-adaption)\n", 57);
	write(1, "    • 5: Julia set (change by mouse move)\n", 45);
	write(1, "    • 6: Julia-Ship (by mouse action)\n", 41);
	write(1, "    • 7: Menger-Cube-like 3D-fractal\n\n", 41);
	write(1, " -> Increase iterations in 2D-fractals by pressing:\n", 53);
	write(1, " 	 F5 (+10), F6 (+50), F7 (+200), F8 (+500)\n", 45);
	write(1, " -> Decrease iterations in 2D-fractals by pressing:\n", 53);
	write(1, " 	 F1 (-10), F2 (-50), F3 (-200), F4 (-500)\n", 45);
	write(1, " -> Morph fractals with 'x', 'c', 'v', 'b' keys\n", 49);
	write(1, " -> 3D-fractal (7) actions:\n", 29);
	write(1, "    • keys 'n' and 'm' to change the depth\n", 46);
	write(1, "    • keys 'w', 'a', 's', 'd', 'q', 'e' to rotate\n", 53);
	write(1, "    •   (mouse move and mouse wheel)\n", 40);
	write(1, " -> 'esc' key to close the window\n", 35);
	write(1, "\n     ### Have fun exploring the fractals! ###\n\n", 49);
}
