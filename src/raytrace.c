/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:04:26 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/23 15:04:29 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static t_color_float	transfer_color_to_float(t_object *object)
{
	t_color_float	color;

	color.r = 0.0;
	color.g = 0.0;
	color.b = 0.0;
	if (object->color == C_WHITE || object->color == C_RED || \
			object->color == C_YELLOW || object->color == C_MAGENTA)
		color.r += 1.0;
	if (object->color == C_WHITE || object->color == C_YELLOW || \
			object->color == C_GREEN || object->color == C_CYAN)
		color.g += 1.0;
	if (object->color == C_WHITE || object->color == C_CYAN || \
			object->color == C_BLUE || object->color == C_MAGENTA)
		color.b += 1.0;
	if (object->color == C_BLACK)
	{
		color.r = 0.1;
		color.g = 0.1;
		color.b = 0.1;
	}
	return (color);
}

static t_color_float	background(void)
{
	t_color_float	color;

	color.r = 0.0L;
	color.g = 0.0L;
	color.b = AMBIENT_LIGHT;
	return (color);
}

/* Find the closest object along the ray
*/
t_object	*nearest_object(t_scene *scene, t_ray ray, double *ray_length)
{
	t_object	*nearest;
	int			i;
	double		distance;

	nearest = NULL;
	i = 0;
	distance = 0;
	while (i < scene->object_count)
	{
		distance = check_for_hit(ray, scene->objects[i]);
		if (distance > 0.000001 && distance < *ray_length)
		{
			*ray_length = distance;
			nearest = &scene->objects[i];
		}
		i++;
	}
	return (nearest);
}

/* Projects a ray from camera the direction determined by the pixel coordinates
*/
t_ray	ray_from_camera_to_pixel(int x, int y, t_camera camera)
{
	const double	unit_width = 1.0 / (WIN_WIDTH / 3);
	const double	unit_height = 1.0 / (WIN_HEIGHT / 2) * -1;
	t_ray			ray;

	ray.origin = camera.position;
	ray.direction.x = (x - WIN_WIDTH / 2) * unit_width * \
			(VIEWPORT_WIDTH / WIN_WIDTH);
	ray.direction.y = (y - WIN_HEIGHT / 2) * unit_height * \
			(VIEWPORT_HEIGHT / WIN_HEIGHT);
	ray.direction.z = 1.0;
	ray.direction = calc_vector_direction(ray.direction, camera.rotation);
	return (ray);
}

/* 	This function calculates the color of every pixel-sized object hitpoint in
 *	its view. The color depends on the color of the object, and possible light
 *	ray or rays that hit it. If no light from a given light source hit the 
 *	object, it is drawn with the ambient light brightness.
 *
 *	Also background is of ambient brightness.
*/
t_color_float	raytrace(t_scene *scene, t_ray ray)
{
	t_rt_data		rt_data;
	t_color_float	color;
	double			light_intensity;

	rt_data.scene = scene;
	rt_data.ray = ray;
	rt_data.ray_length = INFINITY;
	rt_data.nearest = nearest_object(scene, ray, &rt_data.ray_length);
	if (!rt_data.nearest)
		return (background());
	color = transfer_color_to_float(rt_data.nearest);
	rt_data.hit_point = vector_sum (ray.origin, scale_vector (ray.direction, \
			rt_data.ray_length));
	rt_data.hit_normal = get_object_normal(rt_data.hit_point, rt_data.nearest);
	light_intensity = get_intensity(rt_data, scene->lights, \
			scene->light_count, 0.0);
	light_intensity = check_min_max(light_intensity);
	color = color_brightness(color, light_intensity);
	return (color);
}
