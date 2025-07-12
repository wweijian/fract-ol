/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:24:23 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/11 12:08:13 by wjhoe            ###   ########.fr       */
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
	f->c.re = 0;
	f->c.im = 0;
	f->zoom = 1;
}

void	init_fractal_minmax(t_fractal *f)
{
	if (f->set == MANDELBROT)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
	}
	if (f->set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
	}
	if (f->set == NEWTON)
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = 4.0;
	}
}

void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_putendl_fd("intialization failed", 1);
		free_and_exit(f);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "42fract-ol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || !f->win)
	{
		ft_putendl_fd("intialization failed", 1);
		free_and_exit(f);
	}
	f->buf = mlx_get_data_addr(f->img, &f->pixel_bits,
			&f->size_line, &f->endian);
	if (!f->buf)
	{
		ft_putendl_fd("intialization failed", 1);
		free_and_exit(f);
	}
	init_fractal_minmax(f);
}
