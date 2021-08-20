/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:05:28 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/29 16:29:33 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			check_args(t_all *all, int size, int map_flag, char *line)
{
	if (size == 0)
	{
		free(line);
		print_error(all, MAP_NO);
	}
	if (map_flag < 8)
	{
		free(line);
		print_error(all, FEW_ARGS);
	}
}

void			check_res(t_all *all)
{
	int		x;
	int		y;

	if (all->win.xr <= 0 || all->win.yr <= 0)
		print_error(all, RES_ER);
	mlx_get_screen_size(&x, &y);
	if (all->win.xr > x)
		all->win.xr = x;
	if (all->win.yr > y)
		all->win.yr = y;
}

int				check_res_str(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) || line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

void			check_identifiers(t_all *all, char *line, int *map_flag)
{
	if (line[0] == 'R')
		parse_res(line, all, map_flag);
	else if (line[0] == 'N' && line[1] == 'O')
		parse_tex(line, all, map_flag, 2);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_tex(line, all, map_flag, 3);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_tex(line, all, map_flag, 1);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_tex(line, all, map_flag, 0);
	else if (line[0] == 'S' && (line[1] == ' ' || line[1] == '.'))
		parse_tex(line, all, map_flag, 4);
	else if (line[0] == 'F' && (line[1] == ' ' || ft_isdigit(line[1]) == 1))
		parse_fcolor(++line, all, map_flag);
	else if (line[0] == 'C' && (line[1] == ' ' || ft_isdigit(line[1]) == 1))
		parse_ccolor(++line, all, map_flag);
	else if (line[0] != '\0')
		print_error(all, KEY_ER);
}

int				check_color_str(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == ',')
			i++;
		else
			return (0);
	}
	return (1);
}
