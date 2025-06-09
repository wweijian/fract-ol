/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:12:23 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/09 17:46:53 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractals(t_fractal *f)
{
	int	x;
	int	y;

	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			fractalization(f, x, y);
			x++;
		}
		y++;
	}
}

void fractalization(t_fractal *f, int x, int y)
{
	if (f->set == MANDELBROT)
		mandelbrot(f, x, y);
	else if (f->set == JULIA)
		julia(f, x, y);
	else if (f->set == MANDELBROT)
		koch(f, x, y);
	else
		error_msg(f);
}

void put_pixel(t_fractal *f, int x, int y, int colour)
{
	int	*buffer;
	
	buffer = f->buf;
	buffer[(y * f->size_line / 4) + x] = colour; // why? 
}