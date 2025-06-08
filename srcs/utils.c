/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 09:56:16 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 20:39:09 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_space_sign_0x(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '+')
		i++;
	if(s[i] && s[i + 1])
	{
		if (s[i] == '0')
		{
			if (s[i+1] == 'x' || s[i + 1] == 'X')
				i += 2;
		}
	}
	return (i);
}

int	fractal_atox(t_fractal *f, char *s)
{
	int	i;
	int	hexa_count;
	int	res;

	i = move_space_sign_0x(s);
	res = 0;
	hexa_count = 0;
	while (s[i] && ft_ishexa(s[i]))
	{
		if (ft_isdigit(s[i]))
			res = res * 16 + s[i] - '0';
		else
			res = res * 16 + (ft_toupper(s[i]) - 'A' + 10);
		i++;
		hexa_count++;
	}
	if (hexa_count == 6 && !s[i])
		return (res);
	else
		display_help(f);
	return (0);
}
