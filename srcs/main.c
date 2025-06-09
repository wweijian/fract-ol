/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:12:53 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/09 22:41:05 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int ac, char **av)
{
	t_fractal	*f;
	
	if (ac < 2)
		return (0);
	f = malloc(sizeof(*f));
	init_frac(f);
	validate_argument(f, ac, av);
	init_mlx(f);
	draw_fractals(f);
	mlx_key_hook(f->win, key_event, f);
	mlx_mouse_hook(f->win, mouse_event, f);
	mlx_hook(f->win, 17, 0, free_everything, f);
	printf("set:\t%d \n", f->set);
	printf("r:\t%f \n", f->cr);
	printf("i:\t%f \n", f->ci);
	printf("col:\t%d \n", f->colour);
	
	mlx_loop(f->mlx);
}
