/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:36:16 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/10 00:42:54 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "events_bonus.h"

int	mouse_event(int event, int x, int y, t_fractal *f)
{
	if (event == UP_SCROLL)
	{
		zoom(f, 0.5);
		x -= WIDTH - 2;
		y -= HEIGHT - 2;
		if (x < 0)
			move(f, x * -1 / WIDTH, LEFT);
		else if (x > 0)
			move(f, x / WIDTH, RIGHT);
		if (y < 0)
			move(f, x * -1 / HEIGHT, LEFT);
		else if (y > 0)
			move(f, x / HEIGHT, RIGHT);
	}
	else if (event == DOWN_SCROLL)
		zoom(f, 1.0);
	else
		return (0);
	draw_fractals(f);
	return (0);
}

int	key_event(int key, t_fractal *f)
{
	if (key == ESC)
		free_everything(f);
	else if(key == UP)
		move(f, 0.01, UP);
	else if(key == DOWN)
		move(f, 0.01, DOWN);
	else if(key == LEFT)
		move(f, 0.01, LEFT);
	else if(key == RIGHT)
		move(f, 0.01, RIGHT);
	else if(key == Z)
		change_colours(f, Z);
	else if(key == X)
		change_colours(f, X);
	else
		return (1);
	draw_fractals(f);
	return (0);
}

void	zoom(t_fractal *f, double zoom)
{
	double	mid_r;
	double	mid_i;
	
	mid_r = f->min_r - f->max_r;
	mid_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (zoom * mid_r - mid_r) / 2;
	f->min_r = f->max_r + zoom * mid_r;
	f->min_i = f->min_i * (zoom * mid_i - mid_i) / 2;
	f->max_i = f->min_i * zoom * mid_i;
}

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
	if (direction == Z)
		f->colour -= 24;
	if (direction == X)
		f->colour += 24;
}