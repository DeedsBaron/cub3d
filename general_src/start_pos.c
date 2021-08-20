/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:17:40 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/26 19:49:51 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_start(t_all *all)
{
	all->pla.pos.x = -1;
	all->pla.pos.y = -1;
	all->pla.dir.x = 0.0;
	all->pla.dir.y = 0.0;
	all->pla.plane.x = 0.0;
	all->pla.plane.y = 0.0;
}

void		start_n(t_all *all, int i, int j)
{
	all->pla.pos.x = j + 0.5;
	all->pla.pos.y = i + 0.5;
	all->pla.dir.x = 0.0;
	all->pla.dir.y = -1.0;
	all->pla.plane.x = 0.66;
	all->pla.plane.y = 0.0;
	all->map[i][j] = '0';
}

void		start_s(t_all *all, int i, int j)
{
	all->pla.pos.x = j + 0.5;
	all->pla.pos.y = i + 0.5;
	all->pla.dir.x = 0.0;
	all->pla.dir.y = 1.0;
	all->pla.plane.x = -0.66;
	all->pla.plane.y = 0;
	all->map[i][j] = '0';
}

void		start_w(t_all *all, int i, int j)
{
	all->pla.pos.x = j + 0.5;
	all->pla.pos.y = i + 0.5;
	all->pla.dir.x = -1.0;
	all->pla.dir.y = 0.0;
	all->pla.plane.x = 0.0;
	all->pla.plane.y = -0.66;
	all->map[i][j] = '0';
}

void		start_e(t_all *all, int i, int j)
{
	all->pla.pos.x = j + 0.5;
	all->pla.pos.y = i + 0.5;
	all->pla.dir.x = 1.0;
	all->pla.dir.y = 0.0;
	all->pla.plane.x = 0.0;
	all->pla.plane.y = 0.66;
	all->map[i][j] = '0';
}
