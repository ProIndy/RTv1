/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:51:08 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:51:09 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int	determine_object_color(char *str)
{
	int			i;
	const char	*colors[] = {
		"null",
		"white",
		"red",
		"yellow",
		"green",
		"cyan",
		"blue",
		"magenta",
		"black"
	};

	if (!str)
		return (0);
	i = 0;
	while (i < 9)
	{
		if (ft_strcmp(colors[i], str) == 0)
			return (i);
		i++;
	}
	return (0);
}

static void	check_angles(t_vector rotation, t_sdl *sdl)
{
	if (rotation.x < -180.0 || rotation.x > 180.0 || rotation.y < -180.0 || \
			rotation.y > 180.0 || rotation.z < -180.0 || rotation.z > 180.0)
		rtv1_error("invalid angle value: exit\n", sdl);
}

void	set_camera(char **object_data, t_sdl *sdl)
{
	if (ft_array_size((void *)object_data) != CAM_ARRAY_SIZE)
		rtv1_error("camera data format incorrect: exit\n", sdl);
	if (sdl->scene.camera_set == CAM_SET)
		rtv1_error("only one camera can be set: exit\n", sdl);
	sdl->scene.camera.position.x = ft_atod(object_data[ELEMENT_POSX]);
	sdl->scene.camera.position.y = ft_atod(object_data[ELEMENT_POSY]);
	sdl->scene.camera.position.z = ft_atod(object_data[ELEMENT_POSZ]);
	sdl->scene.camera.rotation.x = ft_atod(object_data[ELEMENT_ROTX]);
	sdl->scene.camera.rotation.y = ft_atod(object_data[ELEMENT_ROTY]);
	sdl->scene.camera.rotation.z = ft_atod(object_data[ELEMENT_ROTZ]);
	check_angles(sdl->scene.camera.rotation, sdl);
	sdl->scene.camera_set = CAM_SET;
}

void	add_light(char **object_data, t_sdl *sdl)
{
	double	intensity;

	if (ft_array_size ((void *)object_data) != LIGHT_ARRAY_SIZE)
		rtv1_error("light data format incorrect: exit\n", sdl);
	if (sdl->scene.light_count == MAX_NBR_OF_LIGHTS)
		rtv1_error("too many lights: exit\n", sdl);
	sdl->scene.lights[sdl->scene.light_count].position.x = \
			ft_atod(object_data[ELEMENT_POSX]);
	sdl->scene.lights[sdl->scene.light_count].position.y = \
			ft_atod(object_data[ELEMENT_POSY]);
	sdl->scene.lights[sdl->scene.light_count].position.z = \
			ft_atod(object_data[ELEMENT_POSZ]);
	intensity = ft_atod(object_data[ELEMENT_LIGHT_INT]);
	if (intensity < 1.0 || intensity > 1000.0)
		rtv1_error("invalid light intensity value: exit\n", sdl);
	sdl->scene.lights[sdl->scene.light_count].intensity = \
			ft_atod(object_data[ELEMENT_LIGHT_INT]);
	sdl->scene.light_count++;
}

void	add_shape(char **object_data, int count, int type, t_sdl *sdl)
{
	t_vector	unit_vector;

	unit_vector = get_default_unit_vector();
	if (ft_array_size ((void *)object_data) != OBJECT_ARRAY_SIZE)
		rtv1_error("object data format incorrect: exit\n", sdl);
	if (count == MAX_NBR_OF_OBJECTS)
		rtv1_error("too many objects: exit\n", sdl);
	sdl->scene.objects[count].color = \
			determine_object_color(object_data[ELEMENT_COLOR]);
	if (sdl->scene.objects[count].color == 0)
		rtv1_error("incompatible object color: exit\n", sdl);
	sdl->scene.objects[count].type = type;
	sdl->scene.objects[count].position.x = ft_atod(object_data[ELEMENT_POSX]);
	sdl->scene.objects[count].position.y = ft_atod(object_data[ELEMENT_POSY]);
	sdl->scene.objects[count].position.z = ft_atod(object_data[ELEMENT_POSZ]);
	sdl->scene.objects[count].rotation.x = ft_atod(object_data[ELEMENT_ROTX]);
	sdl->scene.objects[count].rotation.y = ft_atod(object_data[ELEMENT_ROTY]);
	sdl->scene.objects[count].rotation.z = ft_atod(object_data[ELEMENT_ROTZ]);
	check_angles(sdl->scene.objects[count].rotation, sdl);
	sdl->scene.objects[count].rotation = calc_vector_direction(unit_vector, \
			sdl->scene.objects[count].rotation);
	sdl->scene.objects[count].radius = \
			ft_atod(object_data[ELEMENT_SIZEX]);
	sdl->scene.object_count++;
}
