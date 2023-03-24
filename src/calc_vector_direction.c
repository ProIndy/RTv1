/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vector_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:05:53 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/23 15:06:01 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*	Calculate the angular position in vectors based on given degrees
*/
static t_vector	calc_x_rotation(double x, t_vector unit_vector)
{
	t_vector	temp;

	temp.y = unit_vector.y;
	temp.z = unit_vector.z;
	unit_vector.y = temp.y * cos(x) - temp.z * sin(x);
	unit_vector.z = temp.y * sin(x) + temp.z * cos(x);
	return (unit_vector);
}

static t_vector	calc_y_rotation(double y, t_vector unit_vector)
{
	t_vector	temp;

	temp.x = unit_vector.x;
	temp.z = unit_vector.z;
	unit_vector.x = temp.x * cos(y) + temp.z * sin(y);
	unit_vector.z = temp.z * cos(y) - temp.x * sin(y);
	return (unit_vector);
}

static t_vector	calc_z_rotation(double z, t_vector unit_vector)
{
	t_vector	temp;

	temp.x = unit_vector.x;
	temp.y = unit_vector.y;
	unit_vector.x = temp.x * cos(z) - temp.y * sin(z);
	unit_vector.y = temp.x * sin(z) + temp.y * cos(z);
	return (unit_vector);
}

t_vector	calc_vector_direction(t_vector unit_vector, t_vector \
				position_degree)
{
	const double	radian = M_PI / 180.0;

	unit_vector = calc_x_rotation(radian * position_degree.x, unit_vector);
	unit_vector = calc_y_rotation(radian * position_degree.y, unit_vector);
	unit_vector = calc_z_rotation(radian * position_degree.z, unit_vector);
	return (unit_vector);
}
