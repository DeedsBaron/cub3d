/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_screen_size.m                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <dbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:09:31 by dbaron            #+#    #+#             */
/*   Updated: 2021/03/29 17:13:46 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <AppKit/NSOpenGLView.h>

#include <stdio.h>
#include <math.h>

#include "mlx_int.h"
#include "mlx_new_window.h"

void		mlx_get_screen_size(int *W, int *H)
{
	NSRect e = [[NSScreen mainScreen] frame];
	*H = (int)e.size.height;
	*W = (int)e.size.width;
}