/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:15:28 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/09 23:50:58 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 480
# define HEIGHT 480
# define MAX_ITERATIONS 100

# define MANDELBROT 1
# define JULIA 2
# define NEWTON 3

typedef struct s_complex
{
	double	re;
	double	im;
	double	fx;
	double	fx_prime;
}				t_complex;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*buf; // pointer to img
	int		set;
	int		colour;
	int		pixel_bits;
	int		size_line;
	int		endian;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	zoom; // zoom
}					t_fractal;

void	validate_argument(t_fractal *f, int ac, char **av);
int 	check_set(char *arg, char *set_name, char set_abbr);
void	get_set(t_fractal *f, char **av);
void	get_julia_values(t_fractal *f, int ac, char **av);
void	error_msg(t_fractal *f);
int		free_everything(t_fractal *f);
int		fractal_atox (t_fractal *f, char *s);
void	init_frac(t_fractal *f);
void	init_mlx(t_fractal *f);
void	draw_fractals(t_fractal *f);
void 	mandelbrot(t_fractal *f, int x , int y);
void 	julia(t_fractal *f, int x , int y);
void	newton(t_fractal *f, int x , int y);
void 	draw_fractals(t_fractal *f);
void 	fractalization(t_fractal *f, int x, int y);
void 	put_pixel(t_fractal *f, int x, int y, int colour);
void	init_fractal_minmax(t_fractal *f);
int		mouse_event(int event, int x, int y, t_fractal *f);
int		key_event(int key, t_fractal *f);
void	zoom(t_fractal *f, double zoom);
void	move(t_fractal *f, double dist, int direction);
void	change_colours(t_fractal *f, int direction);


#endif