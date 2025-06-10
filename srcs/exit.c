/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:54:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/10 15:03:27 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(t_fractal *f)
{
	ft_putendl_fd("jialat", 1);
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