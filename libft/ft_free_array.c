/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:56:09 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/23 14:56:12 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_free_array2(char ***result, int size)
{
	while (size >= 0)
		ft_strdel(&(result[0][size--]));
	free(*result);
	return (NULL);
}
