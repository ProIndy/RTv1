/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:00:23 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/23 15:01:10 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/* Dot product of two vectors
*/
double	dot_product(t_vector vector_1, t_vector vector_2)
{
	double	result;

	result = vector_1.x * vector_2.x + vector_1.y * vector_2.y + vector_1.z * \
			vector_2.z;
	return (result);
}

/* Calculates the scalar length of a vector
*/
double	vector_length(t_vector vector)
{
	double	result;

	result = dot_product(vector, vector);
	result = sqrt(result);
	return (result);
}

t_vector	vector_sum(t_vector vector_1, t_vector vector_2)
{
	vector_1.x += vector_2.x;
	vector_1.y += vector_2.y;
	vector_1.z += vector_2.z;
	return (vector_1);
}

t_vector	vector_subtract(t_vector vector_1, t_vector vector_2)
{
	vector_1.x -= vector_2.x;
	vector_1.y -= vector_2.y;
	vector_1.z -= vector_2.z;
	return (vector_1);
}
