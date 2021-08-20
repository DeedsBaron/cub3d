/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:26:20 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/29 18:23:57 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			parse_res(char *line, t_all *all, int *map_flag)
{
	if (all->check.res == 1)
		print_error(all, DUP_ARG);
	line++;
	if (!check_res_str(line))
		print_error(all, RES_ER);
	while (*line == ' ')
		line++;
	all->win.xr = ft_atoi(line);
	line += cdigits(all->win.xr);
	if (all->win.xr < 0)
		line++;
	while (*line == ' ')
		line++;
	all->win.yr = ft_atoi(line);
	line += cdigits(all->win.yr);
	if ((*line) != '\0')
		print_error(all, RES_ER);
	all->check.res = 1;
	(*map_flag)++;
	check_res(all);
}

void			parse_tex(char *line, t_all *all, int *map_flag, int i)
{
	if ((all->check.we && i == 0) || (all->check.ea && i == 1) ||
		(all->check.no && i == 2) || (all->check.so && i == 3) ||
		(all->check.sp && i == 4))
		print_error(all, DUP_ARG);
	if (i == 4)
		line++;
	else
		line += 2;
	while (*line == ' ')
		line++;
	line++;
	all->tex[i]->path = ft_strdup(line);
	if (i == 0)
		all->check.we = 1;
	if (i == 1)
		all->check.ea = 1;
	if (i == 2)
		all->check.no = 1;
	if (i == 3)
		all->check.so = 1;
	if (i == 4)
		all->check.sp = 1;
	(*map_flag)++;
}

void			parse_fcolor(char *line, t_all *all, int *map_flag)
{
	int		i;

	i = -1;
	if (!check_color_str(line))
		print_error(all, FCLR_ER);
	if (all->check.fl == 1)
		print_error(all, DUP_ARG);
	while (++i < 3)
	{
		while (*line == ' ')
			line++;
		all->fcolor[i] = ft_atoi(line);
		if (all->fcolor[i] > 255 || all->fcolor[i] < 0)
			print_error(all, FCLR_ER);
		while (ft_isdigit(*line))
			line++;
		if (i != 2 && *line != ',' && !ft_isdigit(*(line + 1)))
			print_error(all, FCLR_ER);
		if (i != 2)
			line++;
		if (i == 2 && *line != '\0')
			print_error(all, FCLR_ER);
	}
	all->check.fl = 1;
	(*map_flag)++;
}

void			parse_ccolor(char *line, t_all *all, int *map_flag)
{
	int		i;

	i = -1;
	if (!check_color_str(line))
		print_error(all, CCLR_ER);
	if (all->check.ci == 1)
		print_error(all, DUP_ARG);
	while (++i < 3)
	{
		while (*line == ' ')
			line++;
		all->ccolor[i] = ft_atoi(line);
		if (all->ccolor[i] > 255 || all->ccolor < 0)
			print_error(all, CCLR_ER);
		while (ft_isdigit(*line))
			line++;
		if (i != 2 && *line != ',' && !ft_isdigit(*(line + 1)))
			print_error(all, CCLR_ER);
		if (i != 2)
			line++;
		if (i == 2 && *line != '\0')
			print_error(all, CCLR_ER);
	}
	all->check.ci = 1;
	(*map_flag)++;
}

void			parse_args(int fd, t_all *all)
{
	char	*line;
	int		size;
	int		map_flag;

	line = NULL;
	map_flag = 0;
	while ((validate_args(all) == 0) && (size = get_next_line(fd, &line)))
	{
		check_identifiers(all, line, &map_flag);
		free(line);
	}
	check_args(all, size, map_flag, line);
}
