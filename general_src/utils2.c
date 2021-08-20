/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:42:17 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/30 17:06:33 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			sortsprites(t_all *all, int numspr)
{
	int			i;
	int			j;
	t_sprite	*temp;

	i = 0;
	j = 0;
	while (i < numspr)
	{
		j = i + 1;
		while (j < numspr)
		{
			if (all->sprites[i]->spdist < all->sprites[j]->spdist)
			{
				temp = all->sprites[i];
				all->sprites[i] = all->sprites[j];
				all->sprites[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int				cdigits(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * (-1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void			my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int				create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
