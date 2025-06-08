/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 06:29:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 21:56:43 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_frac(t_fractal *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->set = -1;
	f->min_real = 0;
	f->max_real = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->real = 0;
	f->i = 0;
	f->sx = 0;
	f->rx = 0;
	f->fx = 0;
	f->palette = NULL;
	f->colour_range = -1;
	f->colour = 0;
}

void	get_fractal_layout(t_fractal *f)
{
	if (f->set == MANDELBROT)
	{
		f->min_real = -4.0;
		f->max_real = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_real - f->min_real * HEIGHT / WIDTH);
	}
	if (f->set == JULIA)
	{
		f->min_real = -2.0;
		f->max_real = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_real - f->min_real * HEIGHT / WIDTH);
	}
	if (f->set == KOCH)
	{
		f->min_real = -4.0;
		f->max_real = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_real - f->min_real * HEIGHT / WIDTH);
	}
}

void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		free_everything(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "42fractol");
	if (!f->win)
		free_everything(f);
	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
	get_fractal_layout(f);
	get_colours(f);
}