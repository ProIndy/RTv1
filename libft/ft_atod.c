/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:55:43 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/23 14:55:47 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

double	ft_atod(const char *str)
{
	const int	decimal = ft_atoi (str);
	double		fractional;
	double		mul;
	char		*cp;

	fractional = 0.00;
	mul = 0.10;
	cp = ft_strchr (str, '.');
	if (!cp)
		return ((double)(1.0 * decimal));
	while (ft_isdigit (*(++cp)))
	{
		fractional += (double)(*cp - '0') *mul;
		mul *= 0.10;
	}
	if (decimal < 0)
		fractional *= -1.0;
	return ((double)(decimal + fractional));
}
