/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:17:31 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/29 15:30:20 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		tex_init(t_all *all)
{
	all->draw.lineh = (int)(all->win.yr / all->ray.len);
	all->ray.start = -all->draw.lineh / 2 + all->win.yr / 2;
	if (all->ray.start < 0)
		all->ray.start = 0;
	all->ray.end = all->draw.lineh / 2 + all->win.yr / 2;
	if (all->ray.end >= all->win.yr)
		all->ray.end = all->win.yr - 1;
	if (all->ray.side == 0 || all->ray.side == 1)
		all->draw.wallx = all->pla.pos.y + all->ray.len * all->ray.dir.y;
	else
		all->draw.wallx = all->pla.pos.x + all->ray.len * all->ray.dir.x;
	all->draw.wallx -= floor((all->draw.wallx));
	all->draw.texx = (int)(all->draw.wallx * (double)(TEXWIDTH));
	if ((all->ray.side == 0 || all->ray.side == 1) && all->ray.dir.x >= 0)
		all->draw.texx = TEXWIDTH - all->draw.texx - 1;
	if ((all->ray.side == 2 || all->ray.side == 3) && all->ray.dir.y <= 0)
		all->draw.texx = TEXWIDTH - all->draw.texx - 1;
	all->draw.step = 1.0 * TEXHEIGHT / all->draw.lineh;
	all->draw.texpos = (all->ray.start - all->win.yr / 2 +
		all->draw.lineh / 2) * all->draw.step;
}

void			draw_tex(t_all *all, int x)
{
	unsigned int	color;
	int				y;

	tex_init(all);
	y = all->ray.start;
	while (y <= all->ray.end)
	{
		all->draw.texy = (int)all->draw.texpos & (TEXHEIGHT - 1);
		all->draw.texpos += all->draw.step;
		if (all->ray.side == 0)
			color = ((unsigned int *)(all->tex[0]->addr))[TEXHEIGHT *
				all->draw.texy + all->draw.texx];
		else if (all->ray.side == 1)
			color = ((unsigned int *)(all->tex[1]->addr))[TEXHEIGHT *
				all->draw.texy + all->draw.texx];
		else if (all->ray.side == 2)
			color = ((unsigned int *)(all->tex[2]->addr))[TEXHEIGHT *
				all->draw.texy + all->draw.texx];
		else if (all->ray.side == 3)
			color = ((unsigned int *)(all->tex[3]->addr))[TEXHEIGHT *
				all->draw.texy + all->draw.texx];
		my_mlx_pixel_put(&all->win, x, y, color);
		y++;
	}
}
