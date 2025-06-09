/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:26:49 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/09 17:38:05 by wjhoe            ###   ########.fr       */
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
	else if (check_set(av[1], "koch", 'k'))
		f->set = KOCH;
	else
		error_msg(f);
}

void	get_julia_values(t_fractal *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2 || ac == 3)
	{
		f->cr = 0.5;
		f->ci = 0.5;
		return ;
	}
	if (!ft_strchr(av[ac - 1], '.'))
		error_msg(f);
	if (!ft_strchr(av[ac - 2], '.'))
		error_msg(f);
	f->cr = ft_atof(av[ac - 2]);
	f->ci = ft_atof(av[ac - 1]);
	if (fabs(f->cr) >= 2 || fabs(f->ci) >= 2)
		error_msg(f);
}

void	error_msg(t_fractal *f)
{
	ft_putendl_fd("jialat", 1);
	free_everything(f);
}

void free_everything(t_fractal *f)
{
	(void) f;
}