/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 05:25:36 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 22:04:39 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> // delete before submission
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <OpenGL/gl3.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 1024
# define HEIGHT 1024
# define MAX_ITERATIONS 50

# define MANDELBROT 1
# define JULIA 2
# define KOCH 3

typedef struct s_fractal
{
	void	*mlx;	// MLX context pointer (mlx_init result) --> required to create a window or image
	void	*win;	// MLX window pointer (mlx_new_window()) --> represents the pogram window
	void	*img;	// MLX image pointer (mlx_new_image()) --> where the fractal will be drawn
	char	*buf;	// image buffer (mlx_get_data_addr() result)
	int		set;	// an identifier for fractal type? (e.g. 0 = mandelbrot, 1 = julia, etc.)
	double	min_real;	// real axis on the complex plane (controls zoom and view area)
	double	max_real;
	double	min_i;	// imaginary axis bounds
	double	max_i;
	double	real;		//constant and imaginary parts for julia sets c = kr + ki* i
	double	i;		// ditto
	double	sx;
	double	rx;
	double	fx;
	int		*palette;	// an array of colours used to render the fractal
	int		colour_range; // determine which colour mapping to use (like choosing a palette type)
	int		colour;	// a single colour
}	t_fractal;

/* INIT.C */
void	init_frac(t_fractal *f);
void	get_fractal_layout(t_fractal *f);
void	init_mlx(t_fractal *f);

/* ARG_PARSE.C */
void	parse_arg(t_fractal *f, int ac, char **av);
int		check_set(char *arg, char *str, char c);
void	get_set(t_fractal *f, char **av);
void	set_julia_values(t_fractal *f, int ac, char **av);

/* RENDER.C */
void	render(t_fractal *f);
int		fractalization(t_fractal *f, double px_r, double px_i);
void	set_pixel(t_fractal *f, int x, int y, int colour);

/* FRACTALS */
int	mandelbrot(double real, double imaginary);

/* UTILS.C */
int	move_space_sign_0x(char *s);
int	fractal_atox(t_fractal *f, char *s);

/* HELP.C */
void	display_help(t_fractal *frac);

/* EXIT.C */
void	free_everything(t_fractal *f);


void	get_colours(t_fractal *f);
void	reinit_img(t_fractal *f);
void	init_img(t_fractal *f);

#endif