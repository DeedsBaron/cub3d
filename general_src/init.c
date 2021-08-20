/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:32:24 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/29 17:21:07 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			init_sprites(t_all *all)
{
	int i;
	int j;
	int k;

	if (malloc_sprites(all) == 0)
		print_error(all, MAL_ER_SPR);
	open_tex_n_sp(all);
	i = -1;
	k = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j] != '\0')
		{
			if (all->map[i][j] == '2')
			{
				all->sprites[++k]->cor.x = j + 0.5;
				all->sprites[k]->cor.y = i + 0.5;
				all->map[i][j] = '0';
			}
		}
	}
}

void			init_check_flags(t_all *all)
{
	all->check.no = 0;
	all->check.ea = 0;
	all->check.we = 0;
	all->check.so = 0;
	all->check.sp = 0;
	all->check.fl = 0;
	all->check.ci = 0;
	all->check.res = 0;
}

void			init_screen(t_all *all)
{
	if (!(all->win.mlx = mlx_init()))
		print_error(all, SCR_ER1);
	if (all->screenshot != 1)
		if (!(all->win.mlx_win = mlx_new_window(all->win.mlx,
					all->win.xr, all->win.yr, "1")))
			print_error(all, SCR_ER2);
	if (!(all->win.img = mlx_new_image(all->win.mlx, all->win.xr, all->win.yr)))
		print_error(all, SCR_ER2);
	all->win.addr = mlx_get_data_addr(all->win.img,
		&(all->win.bits_per_pixel), &(all->win.line_length),
			&(all->win.endian));
}

void			init_all_pointers(t_all *all)
{
	all->win.mlx = NULL;
	all->win.mlx_win = NULL;
	all->win.img = NULL;
	all->tex = NULL;
	all->sprites = NULL;
	all->map = NULL;
	all->fcolor = NULL;
	all->ccolor = NULL;
}

t_all			init(t_all all, int fd)
{
	init_all_pointers(&all);
	if (!init_tex_n_color(&all))
		print_error(&all, MAL_ER_TEX);
	init_check_flags(&all);
	parse_args(fd, &all);
	all.sp.numspr = 0;
	all.map = parse_map(fd);
	check_map(&all);
	find_pla(&all);
	init_screen(&all);
	init_sprites(&all);
	return (all);
}
