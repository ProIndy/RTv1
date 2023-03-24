/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculations_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:40 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/23 15:00:07 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*	Crop a vector into a unit vector (divide vector by its length)
*/
t_vector	crop_to_unit_vector(t_vector vector)
{
	double	length;

	length = vector_length(vector);
	vector = scale_vector(vector, 1 / length);
	return (vector);
}

/*	Scale length of vector with a scalar
*/
t_vector	scale_vector(t_vector vector, double scalar)
{
	vector.x *= scalar;
	vector.y *= scalar;
	vector.z *= scalar;
	return (vector);
}

/*	Cross product of two vectors
*/
t_vector	cross_product(t_vector vector_1, t_vector vector_2)
{
	t_vector	result_vector;

	result_vector.x = vector_1.y * vector_2.z - vector_1.z * vector_2.y;
	result_vector.y = vector_1.z * vector_2.x - vector_1.x * vector_2.z;
	result_vector.z = vector_1.x * vector_2.y - vector_1.y * vector_2.x;
	return (result_vector);
}

/*	Returns a 0,1,0 unit vector
*/
t_vector	get_default_unit_vector(void)
{
	t_vector	unit_vector;

	unit_vector.x = 0.0;
	unit_vector.y = 1.0;
	unit_vector.z = 0.0;
	return (unit_vector);
}
