/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:54:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/11 12:34:30 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(t_fractal *f)
{
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("this assignment offers 3 sets: ", 1);
	ft_putendl_fd("Mandelbrot, Julia & Newton", 1);
	ft_putendl_fd("you can call this program with the following formatting", 1);
	ft_putstr_fd("./fractol [set] [colour - optional]", 1);
	ft_putendl_fd(" [julia c values - optional]", 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("For Mandelbrot, you can type mandelbrot or m", 1);
	ft_putendl_fd("For Julia, you can type Julia or j", 1);
	ft_putendl_fd("For Newton, you can type Newton or n", 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("Colours are in (0x-optional) 6 digit hexcode", 1);
	ft_putendl_fd("TIP: use brighter colours for better results", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Julia coordinates come in a pair (x , y) ", 1);
	ft_putendl_fd("both values are be between -2.0 and 2.0", 1);
	ft_putstr_fd("Please also include the decimal point", 1);
	ft_putendl_fd(" for the Julia coordinates", 1);
	ft_putchar_fd('\n', 1);
	free_and_exit(f);
}

int	free_and_exit(t_fractal *f)
{
	if (f)
	{
		if (f->img)
			mlx_destroy_image(f->mlx, f->img);
		if (f->win)
			mlx_destroy_window(f->mlx, f->win);
		if (f->mlx)
		{
			mlx_destroy_display(f->mlx);
			free(f->mlx);
		}
		free(f);
	}
	exit(0);
}
