/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:24:23 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/09 19:14:08 by wjhoe            ###   ########.fr       */
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
	f->colour = 0;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->cr = 0;
	f->ci = 0;
	f->sx = 0;
	f->rx = 0;
	f->offx = 0;
}

void	init_fractal_minmax(t_fractal *f)
{
	if (f->set == MANDELBROT)
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	if (f->set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	if (f->set == KOCH)
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "42fract-ol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->buf = mlx_get_data_addr(f->img, &f->pixel_bits, &f->size_line, &f->endian);
	init_fractal_minmax(f);
}