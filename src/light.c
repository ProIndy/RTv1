/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:39 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:50:40 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*	Calculates the amount of light that hits the pixels and reflects the light
 *	towards the camera. This is done based on the light intensity of the light
 *	sources, the distance to the light sources and the angle of the surface
 *	vs the ray.s
*/
double	get_intensity(t_rt_data rt_data, t_light *lights, size_t l_count, \
				double total_intensity)
{
	t_vector	hp_to_light;
	t_ray		light_to_hp;
	double		ray_vector_squared;
	double		angle;
	double		falloff;

	while (l_count--)
	{
		hp_to_light = vector_subtract(lights[l_count].position, \
				rt_data.hit_point);
		ray_vector_squared = dot_product(hp_to_light, hp_to_light);
		falloff = lights[l_count].intensity * 10 / ray_vector_squared;
		ray_vector_squared = sqrt(ray_vector_squared);
		hp_to_light = scale_vector(hp_to_light, 1.0 / ray_vector_squared);
		light_to_hp.origin = rt_data.hit_point;
		light_to_hp.direction = hp_to_light;
		if (nearest_object(rt_data.scene, light_to_hp, \
				&ray_vector_squared) != NULL)
			continue ;
		angle = dot_product(hp_to_light, rt_data.hit_normal);
		if (angle > 0.000001)
			total_intensity += falloff * angle;
	}
	return (total_intensity);
}

/*	Limits the light intensity float between 0 and 1
*/
double	check_min_max(double light_intensity)
{
	light_intensity = fmin (1.0, AMBIENT_LIGHT + light_intensity);
	light_intensity = fmax (0.0, light_intensity);
	return (light_intensity);
}
