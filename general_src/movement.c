/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:55:19 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/27 21:31:17 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				buttons(int keycode, t_all *all)
{
	if (keycode == W)
		m_forward(all);
	if (keycode == S)
		m_backward(all);
	if (keycode == A)
		m_left(all);
	if (keycode == D)
		m_right(all);
	if (keycode == LEFT)
		turn_left(all);
	if (keycode == RIGHT)
		turn_right(all);
	if (keycode == ESC)
	{
		free_all(all);
		exit(0);
	}
	return (1);
}

void			m_forward(t_all *all)
{
	if (all->map[(int)all->pla.pos.y]
		[(int)(all->pla.pos.x + all->pla.dir.x
		* SPEED + 0.001)] == '0' ||
		all->map[(int)all->pla.pos.y]
		[(int)(all->pla.pos.x + all->pla.dir.x
		* SPEED + 0.001)] == ' ')
		all->pla.pos.x += all->pla.dir.x
		* SPEED + 0.001;
	if (all->map[(int)(all->pla.pos.y
		+ all->pla.dir.y * SPEED + 0.001)]
		[(int)all->pla.pos.x] == '0' ||
		all->map[(int)(all->pla.pos.y
		+ all->pla.dir.y * SPEED + 0.001)]
		[(int)all->pla.pos.x] == ' ')
		all->pla.pos.y += all->pla.dir.y
		* SPEED + 0.001;
}

void			m_backward(t_all *all)
{
	if (all->map[(int)all->pla.pos.y]
		[(int)(all->pla.pos.x - all->pla.dir.x
		* SPEED + 0.001)] == '0' ||
		all->map[(int)all->pla.pos.y]
		[(int)(all->pla.pos.x - all->pla.dir.x
		* SPEED + 0.001)] == ' ')
		all->pla.pos.x -= all->pla.dir.x
		* SPEED + 0.001;
	if (all->map[(int)(all->pla.pos.y
		- all->pla.dir.y * SPEED + 0.001)]
		[(int)all->pla.pos.x] == '0' ||
		all->map[(int)(all->pla.pos.y
		- all->pla.dir.y * SPEED + 0.001)]
		[(int)all->pla.pos.x] == ' ')
		all->pla.pos.y -= all->pla.dir.y
		* SPEED + 0.001;
}

void			m_left(t_all *all)
{
	if (all->map[(int)all->pla.pos.y]
		[(int)(all->pla.pos.x - all->pla.plane.x
		* SPEED + 0.001)] == '0' ||
		all->map[(int)all->pla.pos.y]
		[(int)(all->pla.pos.x - all->pla.plane.x
		* SPEED + 0.001)] == ' ')
		all->pla.pos.x -= all->pla.plane.x
		* SPEED + 0.001;
	if (all->map[(int)(all->pla.pos.y
		- all->pla.plane.y * SPEED + 0.001)]
		[(int)all->pla.pos.x] == '0' ||
		all->map[(int)(all->pla.pos.y
		- all->pla.plane.y * SPEED + 0.001)]
		[(int)all->pla.pos.x] == ' ')
		all->pla.pos.y -= all->pla.plane.y
		* SPEED + 0.001;
}

void			m_right(t_all *all)
{
	if (all->map[(int)all->pla.pos.y]
		[(int)(all->pla.pos.x + all->pla.plane.x
		* SPEED + 0.001)] == '0' ||
		all->map[(int)all->pla.pos.y]
		[(int)(all->pla.pos.x + all->pla.plane.x
		* SPEED + 0.001)] == ' ')
		all->pla.pos.x += all->pla.plane.x
		* SPEED + 0.001;
	if (all->map[(int)(all->pla.pos.y
		+ all->pla.plane.y * SPEED + 0.001)]
		[(int)all->pla.pos.x] == '0' ||
		all->map[(int)(all->pla.pos.y
		+ all->pla.plane.y * SPEED + 0.001)]
		[(int)all->pla.pos.x] == ' ')
		all->pla.pos.y += all->pla.plane.y
		* SPEED + 0.001;
}
