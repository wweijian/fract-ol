/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:57:20 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 21:34:31 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_fractal *f)
{
	int		x;
	int		y;
	double	px_r;
	double	px_i;
	int		iteration;
	
	mlx_clear_window(f->mlx, f->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			px_r = f->min_real + (double)x * (f->max_real - f->min_real) / WIDTH;
			px_i = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			iteration = fractalization(f, px_r, px_i);
			set_pixel(f, x, y, f->palette[iteration]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	fractalization(t_fractal *f, double px_r, double px_i)
{
	if (f->set == MANDELBROT)
		return(mandelbrot(px_r, px_i));
	// else if (f->set == JULIA)
	// 	return(julia(px_r, px_i));
	// else if (f->set == KOCH)
	// 	return(koch(px_r, px_i));
	return (1);
}

void	set_pixel(t_fractal *f, int x, int y, int colour)
{
	f->buf[x * 4 + y * WIDTH * 4] = colour;
	f->buf[x * 4 + y * WIDTH * 4 + 1] = colour >> 8;
	f->buf[x * 4 + y * WIDTH * 4 + 2] = colour >> 16;
	f->buf[x * 4 + y * WIDTH * 4 + 3] = colour >> 24;
}