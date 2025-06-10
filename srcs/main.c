/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:12:53 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/10 17:13:51 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int ac, char **av)
{
	t_fractal	*f;
	
	f = malloc(sizeof(*f));
	if (ac < 2)
		error_msg(f);
	if (!f)
	{
		ft_putendl_fd("initialization failed", 1);
		free_and_exit(f);
	}
	init_frac(f);
	validate_argument(f, ac, av);
	init_mlx(f);
	draw_fractals(f);
	mlx_key_hook(f->win, key_event, f);
	mlx_mouse_hook(f->win, mouse_event, f);
	mlx_hook(f->win, 17, 0, free_and_exit, f);
	mlx_loop(f->mlx);
}
