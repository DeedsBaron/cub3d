/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:48:36 by imac              #+#    #+#             */
/*   Updated: 2021/03/30 17:13:21 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			free_2dim(char **ptr, int i)
{
	int		k;

	k = 0;
	while (k < i)
	{
		free(ptr[k]);
		k++;
	}
	free(ptr);
}

void			*ft_realloc(char **ptr, int i)
{
	char	**newptr;
	int		k;

	k = 0;
	if (ptr == 0)
		return (malloc(sizeof(char *) * (i + 1)));
	newptr = (char **)malloc(sizeof(char *) * (i + 1));
	while (k < i)
	{
		newptr[k] = (char *)malloc(sizeof(char) * (ft_strlen(ptr[k]) + 1));
		ft_strlcpy(newptr[k], ptr[k], ft_strlen(ptr[k]) + 1);
		k++;
	}
	free_2dim(ptr, i);
	return (newptr);
}

int				delete_bn_bef_map(t_all *all)
{
	int i;

	i = 0;
	while (all->map[i] != NULL && all->map[i][0] == '\0')
	{
		delete_back_n_lines(all, i);
	}
	if (i == 0)
		return (i);
	return (i - 1);
}

void			delete_back_n_lines(t_all *all, int i)
{
	int		k;
	char	*tmp;

	k = (i);
	tmp = all->map[i];
	while (all->map[i])
	{
		all->map[i] = all->map[i + 1];
		i++;
	}
	free(tmp);
}
