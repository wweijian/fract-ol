/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:45:37 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/10 12:15:39 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	fx_div_fprime(double re, double im)
{
	t_complex	z;
	t_complex	top;
	t_complex	btm;

	top.re = pow(re, 4) - pow(re, 2) * pow(im, 2) * 6 - pow(im, 2) - 1;
	top.im = 4 * pow(re, 3) * im - 4 * pow(im, 3) * re;
	btm.re = (pow(re, 3) - 3 * re * pow (im, 2)) * 4;
	btm.im = (3 * pow(re, 2) * im - pow(im, 3)) * 4;
	if (pow(btm.re, 2) + pow(btm.im, 2) == 0)
	{
		z.re = 0;
		z.im = 0;
		return (z);
	}
	z.re = (top.re * btm.re + btm.im * top.im) / (pow(btm.re, 2) + pow(btm.im, 2));
	z.im = (top.im * btm.im - top.im * btm.re) / (pow(btm.re, 2) + pow(btm.im, 2));
	return (z);
}

void	newton(t_fractal *f, int x, int y)
{
	int			i;
	t_complex	z;

	f->zr = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
	f->zi = f->min_i + y * (f->max_i - f->min_i) / HEIGHT;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		z = fx_div_fprime(f->zr, f->zi);
		if (0.001 > fabs(z.re) || 0.001 > fabs(z.im))
			break ;
		f->zr = z.re;
		f->zi = z.im;
		i++;
	}
	if (i == MAX_ITERATIONS)
		put_pixel(f, x, y, 0x000000);
	else
		put_pixel(f, x, y, f->colour * i);
}
