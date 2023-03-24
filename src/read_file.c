/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:51:00 by ijaaskel          #+#    #+#             */
/*   Updated: 2023/02/20 16:51:01 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	scene_init(t_sdl *sdl)
{
	sdl->scene.object_count = 0;
	sdl->scene.light_count = 0;
	sdl->scene.camera_set = CAM_NOT_SET;
}

static int	determine_object_type(char *str)
{
	int			i;
	const char	*types[] = {
		"null",
		"camera",
		"light",
		"cone",
		"cylinder",
		"plane",
		"sphere"
	};

	if (!str || str[0] == '\0' || str[0] == '\n')
		return (0);
	i = 1;
	while (i < 7)
	{
		if (!ft_strcmp(types[i], str))
			return (i);
		i++;
	}
	return (0);
}

static void	parse_line(char *line, t_sdl *sdl)
{
	char	**object_data;
	int		type;
	int		array_elements;

	object_data = ft_strsplit(line, ',');
	if (!object_data)
		rtv1_error("malloc fail while reading file: exit\n", sdl);
	array_elements = ft_count_words(line, ',');
	type = determine_object_type(object_data[ELEMENT_TYPE]);
	if (type == 0)
	{
		if (ft_array_size((void *)object_data) == 0 || line[0] == '#')
		{
			ft_free_array2(&object_data, array_elements);
			return ;
		}
		rtv1_error("incompatible object type: exit\n", sdl);
	}
	else if (type == 1)
		set_camera(object_data, sdl);
	else if (type == 2)
		add_light(object_data, sdl);
	else if (type > 2)
		add_shape(object_data, sdl->scene.object_count, type, sdl);
	ft_free_array2(&object_data, array_elements);
}

void	read_file(char *file, t_sdl *sdl, int ret)
{
	int		fd;
	char	*line;

	scene_init(sdl);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		rtv1_error("failed to open given file: exit\n", sdl);
	ret = get_next_line(fd, &line);
	if (ret < 1)
		rtv1_error("not a file or file empty: exit\n", sdl);
	parse_line(line, sdl);
	free(line);
	while (get_next_line(fd, &line))
	{
		parse_line(line, sdl);
		free(line);
	}
	free(line);
	close(fd);
}
