/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:50:02 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:50:03 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color_float	color_brightness(t_color_float color, double light_intensity)
{
	color.r *= light_intensity;
	color.g *= light_intensity;
	color.b *= light_intensity;
	return (color);
}

static unsigned int	draw_pixel(t_color_float color_float)
{
	unsigned int	color;

	color_float.r = (color_float.r * 255);
	color_float.g = (color_float.g * 255);
	color_float.b = (color_float.b * 255);
	color = (unsigned int)color_float.r << (8 * 2);
	color += (unsigned int)color_float.g << (8 * 1);
	color += (unsigned int)color_float.b << (8 * 0);
	return (color);
}

void	render(t_sdl *sdl, int x, int y)
{
	unsigned int	*pixel;
	t_color_float	color;
	t_ray			pixel_ray;

	SDL_LockSurface (sdl->surface);
	pixel = (unsigned int *)(sdl->surface->pixels);
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_ray = ray_from_camera_to_pixel(x, y, sdl->scene.camera);
			color = raytrace(&sdl->scene, pixel_ray);
			*pixel = draw_pixel(color);
			pixel++;
			x++;
		}
		y++;
	}
	SDL_UnlockSurface (sdl->surface);
	SDL_UpdateWindowSurface (sdl->win);
}
