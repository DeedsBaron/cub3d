/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:02:46 by dbaron            #+#    #+#             */
/*   Updated: 2021/04/05 15:47:26 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			raycast_init(t_all *all, int x)
{
	all->ray.hit = 0;
	all->ray.camera = 2 * x / (double)all->win.xr - 1;
	all->ray.dir.x = all->pla.dir.x + all->pla.plane.x * all->ray.camera;
	all->ray.dir.y = all->pla.dir.y + all->pla.plane.y * all->ray.camera;
	all->ray.mapx = (int)(all->pla.pos.x);
	all->ray.mapy = (int)(all->pla.pos.y);
	all->ray.deltadist.x = fabs(1 / all->ray.dir.x);
	all->ray.deltadist.y = fabs(1 / all->ray.dir.y);
	all->ray.mapx = (int)(all->pla.pos.x);
	all->ray.mapy = (int)(all->pla.pos.y);
}

static void			side_dist_calc(t_all *all)
{
	if (all->ray.dir.x < 0)
	{
		all->ray.stepx = -1;
		all->ray.sidedist.x = (all->pla.pos.x - all->ray.mapx) *
			all->ray.deltadist.x;
	}
	else
	{
		all->ray.stepx = 1;
		all->ray.sidedist.x = (all->ray.mapx + 1.0 - all->pla.pos.x) *
			all->ray.deltadist.x;
	}
	if (all->ray.dir.y < 0)
	{
		all->ray.stepy = -1;
		all->ray.sidedist.y = (all->pla.pos.y - all->ray.mapy) *
			all->ray.deltadist.y;
	}
	else
	{
		all->ray.stepy = 1;
		all->ray.sidedist.y = (all->ray.mapy + 1.0 - all->pla.pos.y) *
			all->ray.deltadist.y;
	}
}

static void			calc_dist(t_all *all)
{
	if (all->ray.side == 0 || all->ray.side == 1)
		all->ray.len = (all->ray.mapx - all->pla.pos.x +
			(1 - all->ray.stepx) / 2) / all->ray.dir.x;
	else
		all->ray.len = (all->ray.mapy - all->pla.pos.y +
			(1 - all->ray.stepy) / 2) / all->ray.dir.y;
}

static void			dda(t_all *all)
{
	while (all->ray.hit == 0)
	{
		if (all->ray.sidedist.x < all->ray.sidedist.y)
		{
			all->ray.sidedist.x += all->ray.deltadist.x;
			all->ray.mapx += all->ray.stepx;
			if (all->ray.stepx == -1)
				all->ray.side = 0;
			else if (all->ray.stepx == 1)
				all->ray.side = 1;
		}
		else
		{
			all->ray.sidedist.y += all->ray.deltadist.y;
			all->ray.mapy += all->ray.stepy;
			if (all->ray.stepy == -1)
				all->ray.side = 2;
			else if (all->ray.stepy == 1)
				all->ray.side = 3;
		}
		if (all->map[all->ray.mapy][all->ray.mapx] == '1')
			all->ray.hit = 1;
	}
	calc_dist(all);
}

void				ft_cast_rays(t_all *all)
{
	int		x;
	double	*zbuff;

	x = 0;
	if (!(zbuff = (double *)malloc(sizeof(double) * all->win.xr)))
		print_error(all, MAL_ER_BUFF);
	while (x < all->win.xr)
	{
		raycast_init(all, x);
		side_dist_calc(all);
		dda(all);
		draw_tex(all, x);
		zbuff[x] = all->ray.len;
		x++;
	}
	sprites(all, zbuff);
	free(zbuff);
}
