/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:36:16 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/10 18:29:19 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "events_bonus.h"

/* int	mouse_event(int event, int x, int y, t_fractal *f)
{
	double mouse_r;
	double mouse_i;
	
	if (event == UP_SCROLL)
		f->zoom = 0.9;
	else if (event == DOWN_SCROLL)
		f->zoom = 1.1;
	else
		return (0);
	mouse_r = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
	mouse_i = f->min_i + x * (f->max_i - f->min_i) / HEIGHT;
	zoom_to_point(f, f->zoom, mouse_r, mouse_i);
	draw_fractals(f);
	return (0);
} */

int	key_event(int key, t_fractal *f)
{
	if (key == ESC)
		free_and_exit(f);
	else if(key == UP)
		move(f, 0.05, UP);
	else if(key == DOWN)
		move(f, 0.05, DOWN);
	else if(key == LEFT)
		move(f, 0.05, LEFT);
	else if(key == RIGHT)
		move(f, 0.05, RIGHT);
	else if(key == UC_Z || key == LC_Z)
		change_colours(f, UC_Z);
	else if(key == UC_X || key == LC_X)
		change_colours(f, UC_X);
	else if(key == ZERO)
		init_fractal_minmax(f);
	else
		return (1);
	draw_fractals(f);
	return (0);
}
/* 
void	zoom_to_point(t_fractal *f, double zoom, double x, double y)
{
	if (fabs(x + (f->max_r - x) * zoom - x + (f->min_r - x) * zoom) > MAX_ZOOM
			&& fabs(y + (f->max_i - y) * zoom - y + (f->min_i - y) * zoom) > MAX_ZOOM)
	{
		f->min_r = x + (f->min_r - x) * zoom;
		f->max_r = x + (f->max_r - x) * zoom;
		f->min_i = y + (f->min_i - y) * zoom;
		f->max_i = y + (f->max_i - y) * zoom;
	}
} */

void	move(t_fractal *f, double dist, int direction)
{
	double	mid_r;
	double	mid_i;

	mid_r = f->max_r - f->min_r;
	mid_i = f->max_i - f->min_i;
	if (direction == UP)
	{
		f->min_i += mid_i * dist;
		f->max_i += mid_i * dist;
	}
	if (direction == DOWN)
	{
		f->min_i -= mid_i * dist;
		f->max_i -= mid_i * dist;
	}
	if (direction == LEFT)
	{
		f->min_r -= mid_r * dist;
		f->max_r -= mid_r * dist;
	}
	if (direction == RIGHT)
	{
		f->min_r += mid_r * dist;
		f->max_r += mid_r * dist;
	}
}

void	change_colours(t_fractal *f, int direction)
{
	if (direction == UC_Z)
	{
		if (f->colour < 32)
			f->colour = MAX_COLOUR - (32 - f->colour);
		else
			f->colour -= 32;
	}
	if (direction == UC_X)
	{
		if (f->colour > MAX_COLOUR - 32)
			f->colour = MIN_COLOUR + 32 - (MAX_COLOUR - f->colour);
		else
			f->colour += 32;
	}
}

int	mouse_event(int event, int x, int y, t_fractal *f)
{
	double mouse_r;
	double mouse_i;
	
	if (event == UP_SCROLL)
		zoom_to_point(f, 1, x, y);
	else if (event == DOWN_SCROLL)
		zoom_to_point(f, -1, x, y);
	else
		return (0);
	draw_fractals(f);
	return (0);
}

void	zoom_to_point(t_fractal *f, double zoom, double x, double y)
{
	double	factor;

	factor = 1.1;
	if (zoom > 0)
	{
		f->off_x = (x / f->zoom + f->off_x) - (x / (f->zoom * factor));
		f->off_y = (y / f->zoom + f->off_y) - (y / (f->zoom * factor));
		f->zoom *= factor;
	}
	if (zoom < 0)
	{
		f->off_x = (x / f->zoom + f->off_x) - (x / (f->zoom / factor));
		f->off_y = (y / f->zoom + f->off_y) - (y / (f->zoom / factor));
		f->zoom /= factor;
	}
	else
		return ;
}

/* 
f->cr = x / f->zoom + f->off_x;
f->ci = y / f->zoom + f->off_y;
*/