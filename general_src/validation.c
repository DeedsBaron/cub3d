/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:58:18 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/30 17:13:05 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				check_unique(t_all *all, int i, int j, int *unique)
{
	if (all->map[i][j] == 'N' || all->map[i][j] == 'W' ||
			all->map[i][j] == 'E' || all->map[i][j] == 'S')
		(*unique) += 1;
	if (*unique > 1)
		print_error(all, DUP_PLA);
	return (1);
}

int				check_symbols(t_all *all, int i, int j)
{
	if (all->map[i][j] == '0' ||
			all->map[i][j] == '1' ||
			all->map[i][j] == '2' ||
			all->map[i][j] == 'N' ||
			all->map[i][j] == 'W' ||
			all->map[i][j] == 'E' ||
			all->map[i][j] == 'S' ||
			all->map[i][j] == ' ')
		return (1);
	else
		print_error(all, MAP_SYMB);
	return (0);
}

int				neighbours(t_all *all, int i, int j)
{
	if (all->map[i][j] == '0' ||
			all->map[i][j] == '2' ||
			all->map[i][j] == 'N' ||
			all->map[i][j] == 'W' ||
			all->map[i][j] == 'E' ||
			all->map[i][j] == 'S')
	{
		if (i != 0 && j != 0 && all->map[i + 1] != NULL &&
			all->map[i][j + 1] != '\0' &&
				all->map[i + 1][j] != '\0')
		{
			if (all->map[i - 1][j] != ' ' && all->map[i + 1][j] != ' ' &&
				all->map[i][j + 1] != ' ' && all->map[i][j - 1] != ' ')
				return (1);
			else
				print_error(all, BOUND);
		}
		else
			print_error(all, BOUND);
	}
	return (1);
}

int				check_map(t_all *all)
{
	int i;
	int j;
	int	unique;

	unique = 0;
	i = delete_bn_bef_map(all);
	if (!all->map[i])
		print_error(all, MAP_NO);
	while (all->map[i])
	{
		j = 0;
		if (all->map[i][j] == '\0' && all->map[i + 1] != NULL)
			print_error(all, MAP_BN);
		while (all->map[i][j] != '\0')
		{
			if (check_symbols(all, i, j) &&
				check_unique(all, i, j, &unique) &&
				neighbours(all, i, j))
				j++;
			else
				print_error(all, MAP_SYMB);
		}
		i++;
	}
	return (1);
}

int				validate_args(t_all *all)
{
	if (all->check.no == 1 &&
			all->check.ea == 1 &&
			all->check.we == 1 &&
			all->check.so == 1 &&
			all->check.sp == 1 &&
			all->check.fl == 1 &&
			all->check.ci == 1 &&
			all->check.res == 1)
		return (1);
	else
		return (0);
}
