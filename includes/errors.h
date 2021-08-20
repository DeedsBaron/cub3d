/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:06:03 by dbaron            #+#    #+#             */
/*   Updated: 2021/04/05 15:38:58 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# define ERR "\033[0;31mError\n\033[0;34m"
# define MAL_ER_BUFF ERR "While malloc zbuff\n"
# define MAL_ER_TEX ERR "While malloc array for textures\n"
# define MAL_ER_SPR ERR "While malloc array for sprites\n"
# define LOAD_TEX ERR "Cant load tex\n"
# define DUP_ARG ERR "Repeated parametrs\n"
# define FCLR_ER ERR "The floor color value is incorrect\n"
# define CCLR_ER ERR "The cieling color value is incorrect\n"
# define FEW_ARGS ERR "Invalid quantity of parametrs\n"
# define MAP_SYMB ERR "Invalid map symbols\n"
# define MAP_NO ERR "No map or invalid parametrs\n"
# define MAP_BN ERR "After map \\n\n"
# define MAP_N ERR "No MAP or \\n after map, cunning boy\n"
# define SCR_ER1 ERR "Cant init screen\n"
# define SCR_ER2 ERR "Cant create window\n"
# define SCR_ER3 ERR "Cant create image\n"
# define RES_ER ERR "Incorrect resolution\n"
# define DUP_PLA ERR "Duplicated player symbols\n"
# define BOUND ERR "Map is not bounded\n"
# define NO_PLA ERR "No player\n"
# define KEY_ER ERR "Invalid identifiers\n"
# define ARG_ER ERR "Invalid quantity of arguments\n"
# define SEC_ARG ERR "Invalid second argument\n"
# define ER_FILE ERR "File doesnt exist\n"
# define WR_EX ERR "Wrong extension of the argument\n"
#endif
