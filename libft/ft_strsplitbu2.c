/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:08:49 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/14 13:51:13 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*ft_get_delim_str(const char *s, char c, int i)
{
	char	*new;
	int		len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	i -= len;
	len++;
	new = ft_strnew((size_t)len + 1);
	if (!new)
		return (NULL);
	len = 0;
	while (s[i] != '\0' && s[i] != c)
		new[len++] = s[i++];
	return (new);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (c == '\0')
		return (NULL);
	result = ft_memalloc(sizeof(char **) * (size_t)(ft_count_words2(s, c) + 1));
	if (!result || sizeof(result) == 0)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = ft_get_delim_str(s, c, i);
			if (!result[j])
				return (ft_free_array2(&result, j - 1));
			i += ft_strlen(result[j++]);
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}
