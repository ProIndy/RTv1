/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:22 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:50:23 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*	Some convoluted math. Basicly, we check if the given ray hits the given
 *	object. If it does, we return the distance to the hit point.
 *
 *	By examining the objects geometric dimensions, we can form a quadratic
 *	equation. Depending on if the equation has 0-roots, we can determine if the
 *	ray passes the object.
*/

static double	check_plane(t_ray ray, t_object object)
{
	t_qc	coefficients;
	double	distance;

	coefficients.a = dot_product(vector_subtract(ray.origin, object.position), \
	object.rotation);
	coefficients.b = dot_product(ray.direction, object.rotation);
	distance = -coefficients.a / coefficients.b;
	if (coefficients.b >= 0 || (coefficients.a < 0 && coefficients.b < 0) || \
			(coefficients.a > 0 && coefficients.b > 0) || distance <= 0.000001)
		return (-1);
	return (distance);
}

static double	check_cone(t_ray ray, t_object object, t_vector location_delta)
{
	t_qc		coefficients;
	double		i;
	double		j;
	double		k;
	double		distance;

	location_delta = vector_subtract(ray.origin, object.position);
	i = object.radius * object.radius;
	j = dot_product(ray.direction, object.rotation);
	k = dot_product(location_delta, object.rotation);
	coefficients.a = dot_product(ray.direction, ray.direction) - i * pow(j, 2) \
			- pow(j, 2);
	coefficients.b = 2 * ((dot_product(ray.direction, location_delta) - (i * \
			j) * k - j * k));
	coefficients.c = dot_product(location_delta, location_delta) - (i * pow(k, \
			2)) - pow(k, 2);
	distance = solve_quadratic_equation(coefficients.a, coefficients.b, \
			coefficients.c);
	return (distance);
}

static double	check_cylinder(t_ray ray, t_object object)
{
	t_qc		coefficients;
	t_vector	location_delta;
	double		i;
	double		j;
	double		distance;

	location_delta = vector_subtract(ray.origin, object.position);
	i = dot_product(ray.direction, object.rotation);
	j = dot_product(location_delta, object.rotation);
	coefficients.a = dot_product(ray.direction, ray.direction) - pow(i, 2);
	coefficients.b = 2 * (dot_product(ray.direction, location_delta) - (i * j));
	coefficients.c = dot_product(location_delta, location_delta) - pow(j, 2) - \
			pow(object.radius, 2);
	distance = solve_quadratic_equation(coefficients.a, coefficients.b, \
			coefficients.c);
	return (distance);
}

static double	check_sphere(t_ray ray, t_object object)
{
	t_qc		coefficients;
	t_vector	location_delta;
	double		distance;

	location_delta = vector_subtract(ray.origin, object.position);
	coefficients.a = dot_product(ray.direction, ray.direction);
	coefficients.b = 2 * dot_product(location_delta, ray.direction);
	coefficients.c = dot_product(location_delta, location_delta) - \
			(object.radius * object.radius);
	distance = solve_quadratic_equation(coefficients.a, coefficients.b, \
			coefficients.c);
	return (distance);
}

double	check_for_hit(t_ray ray, t_object object)
{
	double		distance;
	t_vector	generic_vector;

	generic_vector.x = 0;
	generic_vector.y = 0;
	generic_vector.z = 0;
	if (object.type == 3)
		distance = check_cone(ray, object, generic_vector);
	if (object.type == 4)
		distance = check_cylinder(ray, object);
	if (object.type == 5)
		distance = check_plane(ray, object);
	if (object.type == 6)
		distance = check_sphere(ray, object);
	return (distance);
}
