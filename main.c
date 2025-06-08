/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 05:17:18 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 14:36:43 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"

#include "mlx.h"

int main(void)
{
    void    *mlx;
    void    *win;
    int     x, y;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 500, 500, "Pixel Grid");

    y = 0;
    while (y < 150)
    {
        x = 0;
        while (x < 100)
        {
            mlx_pixel_put(mlx, win, 50 + x, 50 + y, 0xFFFF); // red pixel
            x++;
        }
        y++;
    }

    mlx_loop(mlx);
    return 0;
}
