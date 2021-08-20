/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:56:38 by dbaron            #+#    #+#             */
/*   Updated: 2021/04/05 15:47:55 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			draw_sq(t_all *all, int i, int j, int color)
{
	int x;
	int y;
	int buff;

	buff = 0;
	x = all->win.xr * 0.005 * j;
	y = all->win.xr * 0.005 * i;
	while (x < all->win.xr * 0.005 * (j + 1))
	{
		y = all->win.xr * 0.005 * i;
		while (y < all->win.xr * 0.005 * (i + 1))
		{
			my_mlx_pixel_put(&all->win, x, y, color);
			y++;
		}
		x++;
	}
}

void			draw_map(t_all *all, int color)
{
	int i;
	int j;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j] != '\0')
		{
			if (all->map[i][j] == '1')
				draw_sq(all, i, j, color);
			j++;
		}
		i++;
	}
}

void			draw_player(t_all *all, int color)
{
	draw_sq(all, all->pla.pos.y, all->pla.pos.x, color);
}
