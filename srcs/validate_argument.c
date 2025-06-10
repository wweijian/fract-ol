/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:26:49 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/10 17:27:34 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	validate_argument(t_fractal *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 3)
		error_msg(f);
	else if (f->set == JULIA && ac > 5)
		error_msg(f);
	get_julia_values(f, ac, av);
	if (ac == 3 || (ac == 5 && f->set == JULIA))
		f->colour = fractal_atox(f, av[2]);
	else
		f->colour = 0xFF00FF;
}

int check_set(char *arg, char *set_name, char set_abbr)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		arg[i] = ft_tolower(arg[i]);
		i++;
	}
	if (!ft_strncmp(arg, set_name, ft_strlen(set_name) + 1))
		return (1);
	if (arg[0] == set_abbr && arg[1] == 0)
		return (1);
	return (0);
}

void	get_set(t_fractal *f, char **av)
{
	if (check_set(av[1], "mandelbrot", 'm'))
		f->set = MANDELBROT;
	else if (check_set(av[1], "julia", 'j'))
		f->set = JULIA;
	else if (check_set(av[1], "newton", 'n'))
		f->set = NEWTON;
	else
		error_msg(f);
}

void	get_julia_values(t_fractal *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2 || ac == 3)
	{
		f->c.re = 0.5;
		f->c.im = 0.5;
		return ;
	}
	if (!ft_strchr(av[ac - 1], '.'))
		error_msg(f);
	if (!ft_strchr(av[ac - 2], '.'))
		error_msg(f);
	f->c.re = ft_atof(av[ac - 2]);
	f->c.im = ft_atof(av[ac - 1]);
	if (fabs(f->c.re) >= 2 || fabs(f->c.im) >= 2)
		error_msg(f);
}
