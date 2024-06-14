/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:31:19 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/13 21:29:58 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

// MLX_STRUCT
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*img_data;
	void	*img_ptr;
	int		endian;
	int		*color_map;
	int		colors;
	char	color_set;
	int		set;
	int		subset;
	double	julia_i;
	double	julia_x;
	double	center_x;
	double	center_y;
	int		xs;
	int		ys;
	double	pxl_size;
	int		max_iter;
	int		bpp;
	int		size_line;
	int		depth;
	double	angle_x;
	double	angle_y;
	double	angle_z;
}	t_data;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

// CALCULATE
void	draw_mandelbrot(t_data *data);
void	draw_julia(t_data *data);
void	draw_burning(t_data *data);
void	draw_jurning(t_data *data);
void	draw_moving(t_data *data, int x, int y);
// GRAFIC
void	calculate_screen(t_data *data);
void	clear_image(t_data *data);
void	put_to_back(t_data *data, int x, int y, int color);
// FRACTALS
int		mandelbrot(t_data *data, int x, int y);
int		mandelbrot2(t_data *data, int x, int y);
int		mandelbrot3(t_data *data, int x, int y);
int		mandelbrot4(t_data *data, int x, int y);
int		burning_ship(t_data *data, int x, int y);
int		burning_ship2(t_data *data, int x, int y);
int		burning_ship3(t_data *data, int x, int y);
int		burning_ship4(t_data *data, int x, int y);
int		julia(t_data *data, int x, int y);
int		julia2(t_data *data, int x, int y);
int		julia3(t_data *data, int x, int y);
int		julia4(t_data *data, int x, int y);
int		burning_julia(t_data *data, int x, int y);
int		burning_julia2(t_data *data, int x, int y);
int		burning_julia3(t_data *data, int x, int y);
int		burning_julia4(t_data *data, int x, int y);
int		create_colormap(t_data *data);
void	clear_image(t_data *data);
void	draw_menger(t_data *data, t_point origin, double size, int depth);
// HOOKS
int		mouse_release(int button, int x, int y, t_data *data);
int		mouse_move(int x, int y, t_data *data);
int		button_press(int button, int x, int y, t_data *data);
int		handle_input(int keysym, t_data *data);
int		colorize(t_data *data, int iter);
// UTILS
char	ft_strcmp(char *str1, char *str2);
double	ft_atod(const char *str);
void	instructions(void);
int		close_window(t_data *data);

#endif
