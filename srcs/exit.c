/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:19:11 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 14:43:04 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_everything(t_fractal *f)
{
	if (!f)
		exit(1);
	if (f->palette)
		free(f->palette);
	// if (f->img)
	// 	mlx_destroy_image(f->mlx, f->img);
	// if (f->win && f->mlx)
	// 	mlx_destroy_window(f->mlx, f->win);
	// if (f->mlx)
	// {
	// 	mlx_loop_end(f->mlx);
	// 	mlx_destroy_display(f->mlx);
	// 	free(f->mlx);
	// }
	exit(1);
}