/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:49:44 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:49:46 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	rtv1_error(char *output, t_sdl *sdl)
{
	ft_putstr_fd(output, 2);
	if (sdl->status == S_RUNNING || sdl->status == S_QUIT)
		SDL_Quit();
	exit (1);
}

void	rtv1_exit(char *output, t_sdl *sdl)
{
	ft_putstr(output);
	if (sdl->status == S_RUNNING || sdl->status == S_QUIT)
		SDL_Quit();
	exit (0);
}
