/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:11:13 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/30 14:10:49 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			draw_line(t_all *all, int start, int end, int x)
{
	int		y;

	y = start;
	while (y < end)
	{
		my_mlx_pixel_put(&(all->win), x, y, 0x2e8b57);
		y++;
	}
}

void			draw_floor_ciel(t_all *all, int fl_color, int ci_color)
{
	int		x;
	int		y;

	x = 0;
	while (x < all->win.xr)
	{
		y = 0;
		while (y < all->win.yr)
		{
			if (y < all->win.yr / 2)
				my_mlx_pixel_put(&all->win, x, y, ci_color);
			else
				my_mlx_pixel_put(&all->win, x, y, fl_color);
			y++;
		}
		x++;
	}
}
