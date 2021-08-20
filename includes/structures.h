/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:52:29 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/30 18:49:05 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_cord
{
	double		x;
	double		y;
}				t_cord;

typedef struct	s_win
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			xr;
	int			yr;
}				t_win;

typedef struct	s_pla
{
	t_cord		pos;
	t_cord		dir;
	t_cord		plane;
}				t_pla;

typedef struct	s_ray
{
	t_cord		tex;
	t_cord		cor;
	t_cord		dir;
	t_cord		sidedist;
	t_cord		deltadist;
	double		len;
	double		camera;
	int			hit;
	int			stepx;
	int			stepy;
	int			mapx;
	int			mapy;
	int			side;
	int			start;
	int			end;
}				t_ray;

typedef	struct	s_sprite
{
	int			numspr;
	t_cord		cor;
	int			spdist;
}				t_sprite;

typedef struct	s_tex
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	char		*path;
}				t_tex;

typedef struct	s_draw
{
	int			lineh;
	double		wallx;
	int			texx;
	int			texy;
	double		texpos;
	double		step;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			vmscr;
	int			sprh;
	int			starty;
	int			endy;
	int			sprwid;
	int			startx;
	int			endx;
	int			d;
}				t_draw;

typedef struct	s_check
{
	int			no;
	int			ea;
	int			we;
	int			so;
	int			sp;
	int			fl;
	int			ci;
	int			res;
	int			song;
}				t_check;

typedef struct	s_all
{
	t_tex		**tex;
	t_sprite	**sprites;
	t_sprite	sp;
	t_win		win;
	t_pla		pla;
	t_ray		ray;
	t_draw		draw;
	t_check		check;
	char		**map;
	int			*fcolor;
	int			*ccolor;
	int			screenshot;
}				t_all;
#endif
