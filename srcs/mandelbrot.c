/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:01:18 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/09 19:25:00 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(t_fractal *f, int x , int y)
{
	int		i;
	double	temp;

	f->zr = 0.0;
	f->zi = 0.0;
	f->cr = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
	f->ci = f->min_i + y * (f->max_i - f->min_i) / HEIGHT;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		temp = pow(f->zr, 2) - pow(f->zi, 2) + f->cr;
		f->zr = 2.0 * f->zr * f->zi + f->ci;
		f->zi = temp;
		if (pow(f->zr, 2) + pow(f->zi, 2) > f->max_r)
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
	(void) f;
	(void) x;
	(void) y;
}

void koch(t_fractal *f, int x , int y)
{
	(void) f;
	(void) x;
	(void) y;
}