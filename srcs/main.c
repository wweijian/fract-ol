/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:12:53 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/09 17:43:36 by wjhoe            ###   ########.fr       */
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
	printf("set:\t%d \n", f->set);
	printf("r:\t%f \n", f->cr);
	printf("i:\t%f \n", f->ci);
	printf("col:\t%d \n", f->colour);
	mlx_loop(f->mlx);
}
