/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:15:41 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/29 16:48:22 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void					calc_dist(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->sp.numspr)
	{
		all->sprites[i]->spdist = ((all->pla.pos.x - all->sprites[i]->cor.x) *
			(all->pla.pos.x - all->sprites[i]->cor.x) +
				(all->pla.pos.y - all->sprites[i]->cor.y)
				* (all->pla.pos.y - all->sprites[i]->cor.y));
		i++;
	}
}

static void				calc_sprites(t_all *all, int i)
{
	all->draw.spritex = all->sprites[i]->cor.x - all->pla.pos.x;
	all->draw.spritey = all->sprites[i]->cor.y - all->pla.pos.y;
	all->draw.invdet = 1.0 / (all->pla.plane.x * all->pla.dir.y -
		all->pla.dir.x * all->pla.plane.y);
	all->draw.transformx = all->draw.invdet * (all->pla.dir.y *
		all->draw.spritex - all->pla.dir.x * all->draw.spritey);
	all->draw.transformy = all->draw.invdet * (-all->pla.plane.y *
		all->draw.spritex + all->pla.plane.x * all->draw.spritey);
	all->draw.spritescreenx = (int)((all->win.xr / 2) *
		(1 + all->draw.transformx / all->draw.transformy));
	all->draw.vmscr = (int)(VMOVE / all->draw.transformy);
	all->draw.sprh = abs((int)(all->win.yr / (all->draw.transformy))) / VDIV;
	all->draw.starty = -all->draw.sprh / 2 + all->win.yr / 2 + all->draw.vmscr;
	if (all->draw.starty < 0)
		all->draw.starty = 0;
	all->draw.endy = all->draw.sprh / 2 + all->win.yr / 2 + all->draw.vmscr;
	if (all->draw.endy >= all->win.yr)
		all->draw.endy = all->win.yr - 1;
	all->draw.sprwid = abs((int)(all->win.yr / (all->draw.transformy))) / UDIV;
	all->draw.startx = -all->draw.sprwid / 2 + all->draw.spritescreenx;
	if (all->draw.startx < 0)
		all->draw.startx = 0;
	all->draw.endx = all->draw.sprwid / 2 + all->draw.spritescreenx;
	if (all->draw.endx >= all->win.xr)
		all->draw.endx = all->win.xr - 1;
}

static void				draw_sprites(t_all *all)
{
	int				y;
	unsigned int	color;

	y = all->draw.starty;
	while (y < all->draw.endy)
	{
		all->draw.d = (y - all->draw.vmscr) * 256 - all->win.yr
			* 128 + all->draw.sprh * 128;
		all->draw.texy = ((all->draw.d * TEXHEIGHT) / all->draw.sprh) / 256;
		color = ((unsigned int *)(all->tex[4]->addr))[TEXHEIGHT
			* all->draw.texy + all->draw.texx];
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&all->win, all->draw.startx, y, color);
		y++;
	}
}

void					sprites(t_all *all, double zbuff[])
{
	int				i;

	i = 0;
	calc_dist(all);
	sortsprites(all, all->sp.numspr);
	while (i < all->sp.numspr)
	{
		calc_sprites(all, i);
		while (all->draw.startx < all->draw.endx)
		{
			all->draw.texx = (int)(256 * (all->draw.startx -
				(-all->draw.sprwid / 2 + all->draw.spritescreenx))
					* TEXWIDTH / all->draw.sprwid) / 256;
			if (all->draw.transformy > 0 &&
				all->draw.startx > 0 &&
				all->draw.startx < all->win.xr &&
				all->draw.transformy < zbuff[all->draw.startx])
				draw_sprites(all);
			all->draw.startx++;
		}
		i++;
	}
}
