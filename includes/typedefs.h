/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:50 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:27:52 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color_float
{
	double	r;
	double	g;
	double	b;
}	t_color_float;

typedef struct s_quadratic_coefficients
{
	double	a;
	double	b;
	double	c;
}	t_qc;

typedef struct s_object
{
	int			type;
	t_vector	position;
	t_vector	rotation;
	double		radius;
	int			color;
}	t_object;

typedef struct s_camera
{
	t_vector	position;
	t_vector	rotation;
}	t_camera;

typedef struct s_light
{
	t_vector	position;
	double		intensity;
}	t_light;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_scene
{
	t_object	objects[MAX_NBR_OF_OBJECTS];
	int			object_count;
	t_light		lights[MAX_NBR_OF_LIGHTS];
	int			light_count;
	t_camera	camera;
	int			camera_set;
}	t_scene;

typedef struct s_raytrace_data {
	t_scene		*scene;
	t_object	*nearest;
	t_ray		ray;
	double		ray_length;
	t_vector	hit_point;
	t_vector	hit_normal;
	double		total_intensity;
}	t_rt_data;

typedef struct s_sdl
{
	int			status;
	SDL_Window	*win;
	SDL_Surface	*surface;
	t_scene		scene;
}	t_sdl;

#endif
