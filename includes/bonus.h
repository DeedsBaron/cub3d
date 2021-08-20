/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:59:09 by dbaron            #+#    #+#             */
/*   Updated: 2021/04/05 15:48:43 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "cub3d.h"

void		draw_map(t_all *all, int color);
void		draw_player(t_all *all, int color);
void		draw_sq(t_all *all, int i, int j, int color);
void		music(t_all *all);
#endif
