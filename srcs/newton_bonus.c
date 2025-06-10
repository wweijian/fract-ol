/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:45:37 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/10 18:44:13 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	fx_div_fprime(double re, double im)
{
	t_complex	z;
	t_complex	top;
	t_complex	btm;

	top.re = re * re * re * re - re * re * im * im * 6 - im * im - 1;
	top.im = 4 * re * re * re * im - 4 * im * im * im * re;
	btm.re = (re * re * re - 3 * re * im * im) * 4;
	btm.im = (3 * re * re * im - im * im * im) * 4;
	if (btm.re * btm.re + btm.im * btm.im == 0)
	{
		z.re = 0;
		z.im = 0;
		return (z);
	}
	z.re = (top.re * btm.re + btm.im * top.im) / (btm.re * btm.re + btm.im * btm.im);
	z.im = (top.im * btm.im - top.im * btm.re) / (btm.re * btm.re + btm.im * btm.im);
	return (z);
}

void	newton(t_fractal *f, int x, int y)
{
	int			i;
	t_complex	a;

	f->z.re = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
	f->z.im = f->min_i + y * (f->max_i - f->min_i) / HEIGHT;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		a = fx_div_fprime(f->z.re, f->z.im);
		if (0.001 > fabs(a.re) || 0.001 > fabs(a.im))
			break ;
		f->z.re = a.re;
		f->z.im = a.im;
		i++;
	}
	if (i == MAX_ITERATIONS)
		put_pixel(f, x, y, 0x000000);
	else
		put_pixel(f, x, y, f->colour * i);
}
