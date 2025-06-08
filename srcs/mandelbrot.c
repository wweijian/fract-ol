/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:52:23 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 21:48:42 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double real, double imaginary)
{
	int		n;
	double	mand_r;
	double	mand_i;
	double	temp;
	
	n = 0;
	mand_r = 0;
	mand_i = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((mand_r * mand_r + mand_i * mand_i) > 4.0)
			break ;
		temp = 2 * mand_r * mand_i + imaginary;
		mand_r = mand_r * mand_r - mand_i * mand_i + real;
		mand_i = temp;
		n++;
	}
	return (n);
}

