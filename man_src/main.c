/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:01:28 by imac              #+#    #+#             */
/*   Updated: 2021/03/30 16:50:14 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				render_next_frame(t_all *all)
{
	draw_floor_ciel(all,
		create_rgb(all->fcolor[0], all->fcolor[1], all->fcolor[2]),
		create_rgb(all->ccolor[0], all->ccolor[1], all->ccolor[2]));
	ft_cast_rays(all);
	if (all->screenshot != 1)
		mlx_put_image_to_window(all->win.mlx, all->win.mlx_win,
				all->win.img, 0, 0);
	else
		take_screenshot(all);
	return (1);
}

int				check_ext(char *s)
{
	while (*s != '.')
		s++;
	if (ft_strncmp(s, ".cub", 4) == 0)
		return (1);
	else
		return (0);
}

int				main(int argc, char *argv[])
{
	int		fd;
	t_all	all;

	if (argc < 2 || argc > 3)
		print_error(&all, ARG_ER);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		all.screenshot = 1;
	else if (argc == 3)
		print_error(&all, SEC_ARG);
	if (!check_ext(argv[1]))
		print_error(&all, WR_EX);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(&all, ER_FILE);
	all = init(all, fd);
	mlx_loop_hook(all.win.mlx, render_next_frame, &all);
	if (all.screenshot != 1)
	{
		mlx_hook(all.win.mlx_win, 2, 1L << 0, buttons, &all);
		mlx_hook(all.win.mlx_win, 17, 0, free_all, &all);
	}
	mlx_loop(all.win.mlx);
	return (1);
}
