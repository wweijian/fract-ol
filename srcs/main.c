/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 06:09:21 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 17:15:08 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_fractal	f;
	
	if (ac < 2)
		return (0);
	init_frac(&f);
	parse_arg(&f, ac, av);
	init_mlx(&f);
	render(&f);
	printf("%d \n", f.set);
	printf("%f \n", f.real);
	printf("%f \n", f.i);
	printf("%d \n", f.colour);
}