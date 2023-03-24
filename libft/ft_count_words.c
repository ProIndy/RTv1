/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:56:01 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/23 14:56:03 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		words++;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			while (str[i] == c && str[i] != '\0')
				i++;
			if (str[i])
				words++;
			continue ;
		}
		i++;
	}
	return (words);
}
