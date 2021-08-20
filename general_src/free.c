/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:01:04 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/30 18:56:31 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			free_map(t_all *all)
{
	int		i;

	i = 0;
	while (all->map[i])
	{
		free(all->map[i]);
		i++;
	}
	free(all->map);
}

void			free_spr(t_all *all)
{
	int		i;

	i = 0;
	while (all->sprites[i])
	{
		free(all->sprites[i]);
		i++;
	}
	free(all->sprites);
}

void			free_tex(t_all *all)
{
	int		i;

	i = 0;
	while (all->tex[i])
	{
		if (all->tex[i]->img)
			mlx_destroy_image(all->win.mlx, all->tex[i]->img);
		free(all->tex[i]);
		i++;
	}
	free(all->tex);
}

int				free_all(t_all *all)
{
	int		i;

	i = 0;
	if (all->sprites)
		free_spr(all);
	if (all->tex)
		free_tex(all);
	if (all->fcolor)
		free(all->fcolor);
	if (all->ccolor)
		free(all->ccolor);
	if (all->map)
		free_map(all);
	if (all->win.img)
		mlx_destroy_image(all->win.mlx, all->win.img);
	if (all->win.mlx_win)
		mlx_destroy_window(all->win.mlx, all->win.mlx_win);
	if (all->win.mlx)
		free(all->win.mlx);
	if (all->check.song == 1)
		system("killall afplay");
	exit(1);
	return (1);
}

void			print_error(t_all *all, char *s)
{
	write(1, s, ft_strlen(s));
	free_all(all);
}
