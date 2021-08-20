/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:57:21 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/27 21:30:37 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	turn_left(t_all *all)
{
	double olddirx;
	double oldplanex;

	olddirx = all->pla.dir.x;
	oldplanex = all->pla.plane.x;
	all->pla.dir.x = all->pla.dir.x * cos(-ROTSPEED) -
		all->pla.dir.y * sin(-ROTSPEED);
	all->pla.dir.y = olddirx * sin(-ROTSPEED) + all->pla.dir.y * cos(-ROTSPEED);
	all->pla.plane.x = all->pla.plane.x * cos(-ROTSPEED) -
		all->pla.plane.y * sin(-ROTSPEED);
	all->pla.plane.y = oldplanex * sin(-ROTSPEED) +
		all->pla.plane.y * cos(-ROTSPEED);
}

void	turn_right(t_all *all)
{
	double olddirx;
	double oldplanex;

	olddirx = all->pla.dir.x;
	oldplanex = all->pla.plane.x;
	all->pla.dir.x = all->pla.dir.x * cos(ROTSPEED) -
		all->pla.dir.y * sin(ROTSPEED);
	all->pla.dir.y = olddirx * sin(ROTSPEED) +
		all->pla.dir.y * cos(ROTSPEED);
	all->pla.plane.x = all->pla.plane.x * cos(ROTSPEED) -
		all->pla.plane.y * sin(ROTSPEED);
	all->pla.plane.y = oldplanex * sin(ROTSPEED) +
		all->pla.plane.y * cos(ROTSPEED);
}
