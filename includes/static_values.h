/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_values.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:42 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:27:43 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATIC_VALUES_H
# define STATIC_VALUES_H

/*	window options	*/
# define TITLE "RTv1"
# define TITLE_SPACE " : "
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define VIEWPORT_WIDTH 600.0L
# define VIEWPORT_HEIGHT 400.0L

/*	SDL status	*/
# define S_UNINITIALIZED 0
# define S_RUNNING 1
# define S_QUIT 2

/*	array elements	*/
# define ELEMENT_TYPE 0
# define ELEMENT_POSX 1
# define ELEMENT_POSY 2
# define ELEMENT_POSZ 3
# define ELEMENT_ROTX 4
# define ELEMENT_ROTY 5
# define ELEMENT_ROTZ 6
# define ELEMENT_SIZEX 7
# define ELEMENT_COLOR 8

# define ELEMENT_LIGHT_INT 4

/*	object element numbers*/
# define CAM_ARRAY_SIZE 7
# define LIGHT_ARRAY_SIZE 5
# define OBJECT_ARRAY_SIZE 9

/*	object restrictions	*/
# define CAM_NOT_SET 0
# define CAM_SET 1
# define MAX_NBR_OF_LIGHTS 4
# define MAX_NBR_OF_OBJECTS 9

/*	colors	*/
# define C_WHITE 1
# define C_RED 2
# define C_YELLOW 3
# define C_GREEN 4
# define C_CYAN 5
# define C_BLUE 6
# define C_MAGENTA 7
# define C_BLACK 8

/*	ambient light on objects	*/
# define AMBIENT_LIGHT 0.1

#endif
