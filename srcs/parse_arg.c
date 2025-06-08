/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 07:26:34 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 16:42:21 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_arg(t_fractal *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 3)
		display_help(f);
	else if (f->set == JULIA && ac > 5)
		display_help(f);
	set_julia_values(f, ac, av);
	if (ac == 3 || (ac == 5 && f->set == JULIA))
		f->colour = fractal_atox(f, av[2]);
	else
		f->colour = 0xFF00FF;
}

int	check_set(char *arg, char *str, char c)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		arg[i] = ft_tolower(arg[i]);
		i++;
	}
	if (!ft_strncmp(arg, str, ft_strlen(str) + 1))
		return (1);
	else if (arg[0] == c && arg[1] == 0)
		return (1);
	return (0);
}

void	get_set(t_fractal *f, char **av)
{
	if (check_set(av[1], "mandelbrot", 'm'))
		f->set = MANDELBROT;
	else if (check_set(av[1], "julia", 'j'))
		f->set = JULIA;
	else if (check_set(av[1], "koch", 'k'))
		f->set = KOCH;
	else
		display_help(f);
}

void	set_julia_values(t_fractal *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2 || ac == 3)
	{
		f->real = -0.5;
		f->i = -0.5;
		return ;
	}
	if (!ft_strchr(av[ac - 1], '.'))
		display_help(f);
	if (!ft_strchr(av[ac - 2], '.'))
		display_help(f);
	f->real = ft_atof(av[ac - 2]);
	f->i = ft_atof(av[ac - 1]);	
	if (fabs(f->real) >= 2 || fabs(f->i) >= 2)
		display_help(f);
}
