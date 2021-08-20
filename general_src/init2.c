/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:04:41 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/29 15:38:36 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			open_tex_n_sp(t_all *all)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (!(all->tex[i]->img = mlx_xpm_file_to_image(all->win.mlx,
			all->tex[i]->path, &all->tex[i]->width, &all->tex[i]->height)))
			print_error(all, LOAD_TEX);
		all->tex[i]->addr = mlx_get_data_addr(all->tex[i]->img,
			&(all->tex[i]->bits_per_pixel), &(all->tex[i]->line_length),
				&(all->tex[i]->endian));
		i++;
	}
}

int				init_tex_n_color(t_all *all)
{
	int		i;

	i = 0;
	if (!(all->tex = (t_tex **)malloc(sizeof(t_tex *) * 6)))
		return (0);
	while (i < 5)
	{
		if (!(all->tex[i] = (t_tex *)malloc(sizeof(t_tex))))
			return (0);
		all->tex[i]->img = NULL;
		i++;
	}
	all->tex[i] = NULL;
	if (!(all->fcolor = (int *)malloc(sizeof(int) * 3)))
		return (0);
	if (!(all->ccolor = (int *)malloc(sizeof(int) * 3)))
		return (0);
	return (1);
}

void			find_pla(t_all *all)
{
	int i;
	int j;

	i = -1;
	init_start(all);
	while (all->map[++i])
	{
		j = 0;
		while (all->map[i][j] != '\0')
		{
			if (all->map[i][j] == '2')
				all->sp.numspr += 1;
			if (all->map[i][j] == 'N')
				start_n(all, i, j);
			else if (all->map[i][j] == 'S')
				start_s(all, i, j);
			else if (all->map[i][j] == 'W')
				start_w(all, i, j);
			else if (all->map[i][j] == 'E')
				start_e(all, i, j);
			j++;
		}
	}
	if (all->pla.pos.x == -1 && all->pla.pos.y == -1)
		print_error(all, NO_PLA);
}

int				malloc_sprites(t_all *all)
{
	int		i;

	i = 0;
	if (!(all->sprites = (t_sprite **)malloc(sizeof(t_sprite *)
		* all->sp.numspr + 1)))
		return (0);
	while (i < all->sp.numspr)
	{
		if (!(all->sprites[i] = (t_sprite *)malloc(sizeof(t_sprite))))
			return (0);
		i++;
	}
	all->sprites[i] = NULL;
	return (1);
}
