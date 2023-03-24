/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:33 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:27:35 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <SDL2/SDL.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# include "../libft/includes/libft.h"
# include "static_values.h"
# include "typedefs.h"

/*	calc_vector_direction.c	*/
t_vector		calc_vector_direction(t_vector unit_vector, t_vector \
						position_degree);

/*	check_for_hit.c	*/
double			check_for_hit(t_ray ray, t_object object);

/*	exit.c	*/
void			rtv1_error(char *output, t_sdl *sdl);
void			rtv1_exit(char *output, t_sdl *sdl);

/*	solve_quadratic_equation.c	*/
double			solve_quadratic_equation(double a, double b, double c);

/*	light.c	*/
double			get_intensity(t_rt_data rt_data, t_light *lights, \
						size_t l_count, double total_intensity);
double			check_min_max(double light_intensity);

/*	normals.c	*/
t_vector		get_object_normal(t_vector hit_point, t_object *object);

/*	raytrace.c	*/
t_object		*nearest_object(t_scene *scene, t_ray ray, double *min_t);
t_ray			ray_from_camera_to_pixel(int x, int y, t_camera camera);
t_color_float	raytrace(t_scene *scene, t_ray ray);

/*	read_file.c	*/
void			read_file(char *file, t_sdl *sdl, int ret);

/*	render.c	*/
t_color_float	color_brightness(t_color_float color, double light_intensity);
void			render(t_sdl *sdl, int x, int y);

/*	scene.c	*/
void			set_camera(char **object_data, t_sdl *sdl);
void			add_light(char **object_data, t_sdl *sdl);
void			add_shape(char **object_data, int count, int type, t_sdl *sdl);

/*	vector_calculations.c	*/
double			dot_product(t_vector vector_1, t_vector vector_2);
double			vector_length(t_vector vector);
t_vector		vector_reflec(t_vector d, t_vector n);
t_vector		vector_sum(t_vector vector_1, t_vector vector_2);
t_vector		vector_subtract(t_vector vector_1, t_vector vector_2);

/*	vector_calculations_2.c	*/
t_vector		crop_to_unit_vector(t_vector vector);
t_vector		scale_vector(t_vector vector, double scalar);
t_vector		cross_product(t_vector vector_1, t_vector vector_2);
t_vector		get_default_unit_vector(void);

#endif
