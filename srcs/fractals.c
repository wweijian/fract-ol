/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:01:18 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/10 17:26:44 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(t_fractal *f, int x , int y)
{
	int		i;
	double	temp;

	f->z.re = 0.0;
	f->z.im = 0.0;
	f->c.re = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
	f->c.im = f->min_i + y * (f->max_i - f->min_i) / HEIGHT;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		temp = pow(f->z.re, 2) - pow(f->z.im, 2) + f->c.re;
		f->z.im = 2.0 * f->z.re * f->z.im + f->c.im;
		f->z.re = temp;
		if (pow(f->z.re, 2) + pow(f->z.im, 2) > 4.0)
			break;
		i++;
	}
	if (i == MAX_ITERATIONS)
		put_pixel(f, x, y, 0x000000);
	else
		put_pixel(f, x, y, f->colour * i);
}

void julia(t_fractal *f, int x , int y)
{
	int		i;
	double	temp;
	
	f->z.re = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
	f->z.im = f->min_i + y * (f->max_i - f->min_i) / HEIGHT;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		temp = f->z.re;
		f->z.re = pow(f->z.re, 2) - pow(f->z.im, 2) + f->c.re;
		f->z.im = 2 * f->z.im * temp + f->c.im;
		if (pow(f->z.re, 2) + pow(f->z.im, 2) > 4.0)
			break;
		i++;
	}
	if (i == MAX_ITERATIONS)
		put_pixel(f, x, y, 0x000000);
	else
		put_pixel(f, x, y, f->colour * i);
}
