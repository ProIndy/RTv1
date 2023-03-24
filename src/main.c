/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:49:53 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:49:54 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static char	*build_window_title(char *file_name)
{
	char	*window_title;

	window_title = (char *)malloc(sizeof(window_title) * (ft_strlen(TITLE) + \
			ft_strlen(TITLE_SPACE) + ft_strlen(file_name)));
	window_title = ft_strcpy(window_title, TITLE);
	window_title = ft_strcat(window_title, TITLE_SPACE);
	window_title = ft_strcat(window_title, file_name);
	return (window_title);
}

static void	init_sdl(t_sdl *sdl, char *file_name)
{
	int		sdl_init_return;
	char	*window_title;

	sdl_init_return = SDL_Init(SDL_INIT_VIDEO);
	if (sdl_init_return != 0)
		rtv1_error("SDL initialization failed: exit\n", sdl);
	else
		sdl->status = S_RUNNING;
	window_title = build_window_title(file_name);
	sdl->win = SDL_CreateWindow (window_title, SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	free(window_title);
	if (!sdl->win)
		rtv1_error("SDL window creation failed: exit\n", sdl);
	sdl->surface = SDL_GetWindowSurface (sdl->win);
	if (!sdl->surface)
		rtv1_error("SDL surface creation failed: exit\n", sdl);
}

int	main(int ac, char **av)
{
	t_sdl		sdl;
	SDL_Event	event;

	sdl.status = S_UNINITIALIZED;
	if (ac != 2)
		rtv1_error("Usage: ./rtv1 [scene_descriptor_file]\n", &sdl);
	read_file(av[1], &sdl, 0);
	if (sdl.scene.camera_set == CAM_NOT_SET)
		rtv1_error("no camera set: exit\n", &sdl);
	init_sdl(&sdl, av[1]);
	render(&sdl, 0, 0);
	while (sdl.status == S_RUNNING)
	{
		while (SDL_PollEvent(&event))
		{
			if (SDL_QUIT == event.type || (SDL_KEYDOWN == event.type \
					&& SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				sdl.status = S_QUIT;
		}
	}
	SDL_Quit();
	rtv1_exit("Program shut down successfully\n", &sdl);
}
