/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:55:19 by jijoo             #+#    #+#             */
/*   Updated: 2023/05/08 20:23:34 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	free_lines(char *l, char **s, int er)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	dobby(s, i);
	if (l)
		free(l);
	return (er);
}

int	texture2(int fd, t_map *cub)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	cub->so_texture = NULL;
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "SO", 2))
		return (free_lines(line, split, 1));
	cub->so_texture = ft_strdup(split[1]);
	cub->so_texture[ft_strlen(cub->so_texture) - 1] = 0;
	free_lines(line, split, 0);
	return (0);
}

int	texture3(int fd, t_map *cub)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	cub->we_texture = NULL;
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "WE", 2))
		return (free_lines(line, split, 1));
	cub->we_texture = ft_strdup(split[1]);
	cub->we_texture[ft_strlen(cub->we_texture) - 1] = 0;
	free_lines(line, split, 0);
	return (0);
}

int	texture4(int fd, t_map *cub)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	cub->ea_texture = NULL;
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "EA", 2))
		return (free_lines(line, split, 1));
	cub->ea_texture = ft_strdup(split[1]);
	cub->ea_texture[ft_strlen(cub->ea_texture) - 1] = 0;
	free_lines(line, split, 0);
	return (0);
}

int	texture(int fd, t_map *cub)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	cub->no_texture = NULL;
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "NO", 2))
		return (free_lines(line, split, 1));
	cub->no_texture = ft_strdup(split[1]);
	cub->no_texture[ft_strlen(cub->no_texture) - 1] = 0;
	free_lines(line, split, 0);
	if (texture2(fd, cub) || texture3(fd, cub) || texture4(fd, cub))
		return (1);
	return (0);
}
