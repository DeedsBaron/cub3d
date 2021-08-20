/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:12:55 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/29 17:21:48 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		bmp_header(t_all *all, int fd)
{
	char	c;
	int		size;

	c = 'B';
	write(fd, &c, 1);
	c = 'M';
	write(fd, &c, 1);
	size = all->win.yr * all->win.xr * 4 + 54;
	write(fd, &size, sizeof(size));
	size = (unsigned int)0;
	write(fd, &size, sizeof(size));
	size = 54;
	write(fd, &size, sizeof(size));
}

void		bmp_infoheader(t_all *all, int fd)
{
	unsigned int	size;
	int				i;

	size = 40;
	write(fd, &size, sizeof(size));
	write(fd, &all->win.xr, sizeof(all->win.xr));
	write(fd, &all->win.yr, sizeof(all->win.yr));
	size = 1;
	write(fd, &size, 2);
	size = 32;
	write(fd, &size, 2);
	i = -1;
	size = 0;
	while (++i < 6)
		write(fd, &size, sizeof(int));
}

void		pixel_data(t_all *all, int fd)
{
	int				i;
	int				j;
	unsigned int	*tmp;

	i = (all->win.yr - 1) * all->win.xr;
	tmp = (unsigned int *)all->win.addr;
	while (i >= 0)
	{
		j = 0;
		while (j < all->win.xr)
		{
			write(fd, &tmp[i], sizeof(unsigned int));
			j++;
			i++;
		}
		i -= 2 * all->win.xr;
	}
}

void		take_screenshot(t_all *all)
{
	int		fd;

	fd = open("map.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	bmp_header(all, fd);
	bmp_infoheader(all, fd);
	pixel_data(all, fd);
	free_all(all);
}
