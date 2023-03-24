/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:55:53 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/23 14:55:55 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long int	ft_atol(const char *str)
{
	int				i;
	long long int	result;
	int				sign;

	i = 0;
	result = 0;
	while (ft_iswhitespace(*str))
		str++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] - 44) * -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - 48);
	return ((long int)result * sign);
}
