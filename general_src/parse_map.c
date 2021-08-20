/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:59:58 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/29 16:47:22 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char		**parse_map(int fd)
{
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		map = (char **)ft_realloc(map, i);
		map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		ft_strlcpy(map[i], line, ft_strlen(line) + 1);
		i++;
		free(line);
	}
	map = (char **)ft_realloc(map, i);
	map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	ft_strlcpy(map[i], line, ft_strlen(line) + 1);
	map = (char **)ft_realloc(map, ++i);
	map[i] = NULL;
	free(line);
	return (map);
}
