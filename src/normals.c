/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:44 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:50:45 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static t_vector	plane_normal(t_object *object)
{
	return (object->rotation);
}

static t_vector	cone_normal(t_vector hit_point, t_object *object)
{
	t_vector	normal;
	t_vector	hypotenuse;

	hypotenuse = vector_subtract(hit_point, object->position);
	normal = cross_product(hypotenuse, object->rotation);
	normal = cross_product(hypotenuse, normal);
	normal = crop_to_unit_vector(normal);
	if (hit_point.y < object->position.y)
		return (scale_vector (normal, -1));
	return (normal);
}

static t_vector	cylinder_normal(t_vector hit_point, t_object *object)
{
	t_vector	hypotenuse;
	t_vector	normal;
	double		scalar;

	hypotenuse = vector_subtract(hit_point, object->position);
	scalar = dot_product(hypotenuse, object->rotation);
	normal = scale_vector (object->rotation, scalar);
	normal = vector_sum(object->position, normal);
	normal = vector_subtract(hit_point, normal);
	normal = crop_to_unit_vector(normal);
	return (normal);
}

static t_vector	sphere_normal(t_vector hit_point, t_object *object)
{
	t_vector	normal;

	normal = vector_subtract (hit_point, object->position);
	normal = scale_vector (normal, 1.0 / object->radius);
	return (normal);
}

t_vector	get_object_normal(t_vector hit_point, t_object *object)
{
	t_vector	return_vector;

	if (object->type == 3)
		return_vector = cone_normal(hit_point, object);
	if (object->type == 4)
		return_vector = cylinder_normal(hit_point, object);
	if (object->type == 5)
		return_vector = plane_normal(object);
	if (object->type == 6)
		return_vector = sphere_normal(hit_point, object);
	return (return_vector);
}
