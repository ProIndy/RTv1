/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:30 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:50:31 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	solve_quadratic_equation(double a, double b, double c)
{
	const double	discriminant = b * b - 4 * a * c;
	double			square_root_of_discriminant;
	double			root_1;
	double			root_2;

	if (discriminant < 0)
		return (-1);
	square_root_of_discriminant = sqrt(discriminant);
	root_1 = (-b - square_root_of_discriminant) / (2 * a);
	root_2 = (-b + square_root_of_discriminant) / (2 * a);
	if ((root_1 <= root_2 && root_1 >= 0) || (root_1 >= 0 && root_2 < 0))
		return (root_1);
	else if ((root_2 <= root_1 && root_2 >= 0) || (root_1 < 0 && root_2 >= 0))
		return (root_2);
	return (-1);
}
