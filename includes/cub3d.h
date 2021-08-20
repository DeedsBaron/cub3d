/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:02:04 by imac              #+#    #+#             */
/*   Updated: 2021/03/30 17:13:24 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include "./structures.h"
# include "./errors.h"
# include "./binds.h"
# include "./bonus.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
char		*ft_dup_n_free(char *line, char *ost, int check);
char		*check_ost(char **ost, char **line);
int			init_gnl(char **line, char **buff, int fd, int *size);
void		*ft_realloc(char **ptr, int i);
char		**parse_map(int fd);
void		print_map(char **map);
int			cdigits(int n);
void		ft_putnbr(int nb);
void		sortsprites(t_all *all, int numspr);
int			create_rgb(int r, int g, int b);
void		my_mlx_pixel_put(t_win *data, int x, int y, int color);
int			delete_bn_bef_map(t_all *all);
void		delete_back_n_lines(t_all *all, int i);
t_all		init(t_all all, int fd);
void		init_screen(t_all *all);
void		init_sprites(t_all *all);
int			init_tex_n_color(t_all *all);
void		open_tex_n_sp(t_all *all);
int			init_tex_n_color(t_all *all);
void		find_pla(t_all *all);
int			malloc_sprites(t_all *all);
void		parse_args(int fd, t_all *all);
void		my_mlx_pixel_put(t_win *data, int x, int y, int color);
void		ft_cast_rays(t_all	*all);
void		mal_sp(t_all *all);
void		turn_right(t_all *all);
void		turn_left(t_all *all);
void		m_forward(t_all *all);
void		m_backward(t_all *all);
void		m_left(t_all *all);
void		m_right(t_all *all);
int			buttons(int keycode, t_all *all);
void		draw_tex(t_all *all, int x);
void		sprites(t_all *all, double zbuff[]);
void		ft_cast_rays(t_all *all);
void		start_n(t_all *all, int i, int j);
void		start_s(t_all *all, int i, int j);
void		start_w(t_all *all, int i, int j);
void		start_e(t_all *all, int i, int j);
void		init_start(t_all *all);
int			validate_args(t_all *all);
int			check_map(t_all *all);
int			check_color_str(char *line);
void		print_error(t_all *all, char *s);
int			free_all(t_all *all);
void		free_map(t_all *all);
void		draw_sq(t_all *all, int i, int j, int color);
void		draw_line(t_all *all, int start, int end, int x);
void		draw_floor_ciel(t_all *all, int fl_color, int ci_color);
void		parse_res(char *line, t_all *all, int *map_flag);
void		parse_tex(char *line, t_all *all, int *map_flag, int i);
void		parse_fcolor(char *line, t_all *all, int *map_flag);
void		parse_ccolor(char *line, t_all *all, int *map_flag);
void		parse_args(int fd, t_all *all);
void		check_args(t_all *all, int size, int map_flag, char *line);
void		check_res(t_all *all);
int			check_res_str(char *line);
void		check_identifiers(t_all *all, char *line, int *map_flag);
int			check_color_str(char *line);
void		take_screenshot(t_all *all);
#endif
