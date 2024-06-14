/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:02:07 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 21:28:44 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// Function to initialize window and image
static int	outer_inits(t_data *data)
{
	data->img_ptr = 0;
	data->img_data = 0;
	data->win_ptr = 0;
	data->color_map = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->img_ptr = mlx_new_image(data->mlx_ptr, 800, 800);
	if (!data->img_ptr)
		return (0);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_line, &data->endian);
	if (!data->img_data)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 800, "Crazy Fract'ol!");
	if (!data->win_ptr)
		return (0);
	if (!create_colormap(data))
		return (0);
	return (1);
}

// Initialize data-struct
static int	init_data_struct(t_data *data, int argc, char **argv)
{
	data->max_iter = 100;
	data->colors = 7;
	data->color_set = 1;
	data->center_x = 0.0;
	data->center_y = 0.0;
	data->pxl_size = 0.005;
	data->xs = 0;
	data->ys = 0;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->depth = 4;
	data->subset = 0;
	if (argc == 4)
	{
		data->julia_x = ft_atod(argv[2]);
		data->julia_i = ft_atod(argv[3]);
	}
	else
	{
		data->julia_x = 0;
		data->julia_i = 0;
	}
	return (outer_inits(data));
}

static int	handling_msg(void)
{
	write(1, "\n\t --->> ### INPUT HANDLING ### <<---\n", 39);
	write(1, "     -> 1 or 3 arguments are needed to call! <-\n\n", 50);
	write(1, " • The first argument to the function call can be:\n\t", 55);
	write(1, "\"mandelbrot\": Mandelbrot set (after Benoît Mandelbrot)", 56);
	write(1, "\n\t\"julia\": Julia set (after Gaston Julia) for x^2\n", 51);
	write(1, "\t\"ship\": Burning Ship (after Michael Michelitsch)\n", 51);
	write(1, "\t\"jurning\": Using Ship-adaption in Julia set\n", 46);
	write(1, "\t\"julmove\": mouse position dependent Julia set\n", 48);
	write(1, "\t\"jurnmove\": mouse position dependent Ship-adaption\n", 53);
	write(1, "\t\"cube\": projection of a Menger-Cube-like 3D-fractal\n", 54);
	write(1, "\n • You can also add the 2 arguments ax and bi, where\n", 57);
	write(1, "\tax: represents the real part for the julia-set\n", 49);
	write(1, "\tbi: represents the imaginary part for the julia-set\n\n", 55);
	write(1, "     -> Example input: \"./fractol julia -0.6 0.6\"\n", 51);
	return (1);
}

static char	handle_args(t_data *data, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot"))
		data->set = 1;
	else if (ft_strcmp(argv[1], "julia"))
		data->set = 2;
	else if (ft_strcmp(argv[1], "ship"))
		data->set = 3;
	else if (ft_strcmp(argv[1], "jurning"))
		data->set = 4;
	else if (ft_strcmp(argv[1], "julmove"))
		data->set = 5;
	else if (ft_strcmp(argv[1], "jurnmove"))
		data->set = 6;
	else if (ft_strcmp(argv[1], "cube"))
		data->set = 7;
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!(argc == 2 || argc == 4))
		return (handling_msg());
	if (!handle_args(&data, argv))
		return (handling_msg());
	if (!init_data_struct(&data, argc, argv))
		close_window(&data);
	instructions();
	calculate_screen(&data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_hook(data.win_ptr, 6, 64, mouse_move, &data);
	mlx_mouse_hook(data.win_ptr, button_press, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
}
