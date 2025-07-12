/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:48:45 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/11 11:55:55 by wjhoe            ###   ########.fr       */
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
	if (s[i] && s[i + 1])
	{
		if (s[i] == '0' && (s[i + 1] == 'X' || s[i + 1] == 'x'))
			i += 2;
	}
	return (i);
}

int	fractal_atox(t_fractal *f, char *s)
{
	int	i;
	int	hex_count;
	int	res;

	i = move_space_sign_0x(s);
	res = 0;
	hex_count = 0;
	while (s[i + hex_count] && ft_ishexa(s[i + hex_count]))
	{
		if (ft_isdigit(s[i + hex_count]))
			res = res * 16 + s[i + hex_count] - '0';
		else
			res = res * 16 + (ft_toupper(s[i + hex_count]) - 'A' + 10);
		hex_count++;
	}
	if (hex_count == 6 && !s[i + hex_count])
		return (res);
	else
		error_msg(f);
	return (0);
}
