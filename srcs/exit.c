/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:54:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/10 17:11:07 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(t_fractal *f)
{
	ft_putendl_fd("this assignment offers 3 sets: Mandelbrot, Julia & Newton", 1);
	ft_putendl_fd("you can call this program with the following formatting", 1);
	ft_putendl_fd("./fractol [set] [colour - optional] [julia c values- optional]", 1);
	ft_putendl_fd("you can call this program with the following formatting", 1);
	ft_putendl_fd("For Mandelbrot, you can type mandelbrot or m",1);
	ft_putendl_fd("For Julia, you can type Julia or j", 1);
	ft_putendl_fd("For Newton, you can type Newton or n", 1);
	ft_putendl_fd("For colours, (0x-optional) 6 digit hexcode", 1);
	ft_putendl_fd("For Julia coordinates, they have to be between -2.0 and 2.0", 1);
	ft_putendl_fd("Please include the decimal point for the Julia coordinates", 1);
	free_and_exit(f);
}

int free_and_exit(t_fractal *f)
{
	if (f)
	{
		if (f->mlx)
			free(f->mlx);
		if (f->win)
			free(f->win);
		if (f->img)
			free(f->img);
		if (f->buf)
			free(f->buf);
		free(f);		
	}
	exit(0);
}