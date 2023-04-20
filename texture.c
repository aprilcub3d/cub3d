/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:55:19 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/20 15:59:17 by jijoo            ###   ########.fr       */
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
	free(l);
	return (er);
}

int	texture2(int fd, t_map *cub)
{
	char	*line;
	char	**split;
	int		room;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "SO", 2))
		return (free_lines(line, split, 1));
	cub->so_texture = mlx_xpm_file_to_image(cub->mlx, split[1], &room, &room);
	free_lines(line, split, 0);
	return (0);
}

int	texture3(int fd, t_map *cub)
{
	char	*line;
	char	**split;
	int		room;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "WE", 2))
		return (free_lines(line, split, 1));
	cub->we_texture = mlx_xpm_file_to_image(cub->mlx, split[1], &room, &room);
	free_lines(line, split, 0);
	return (0);
}

int	texture4(int fd, t_map *cub)
{
	char	*line;
	char	**split;
	int		room;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "EA", 2))
		return (free_lines(line, split, 1));
	cub->ea_texture = mlx_xpm_file_to_image(cub->mlx, split[1], &room, &room);
	free_lines(line, split, 0);
	return (0);
}

int	texture(int fd, t_map *cub)
{
	char	*line;
	char	**split;
	int		room;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "NO", 2))
		return (free_lines(line, split, 1));
	cub->no_texture = mlx_xpm_file_to_image(cub->mlx, split[1], &room, &room);
	free_lines(line, split, 0);
	if (texture2(fd, cub) || texture3(fd, cub) || texture4(fd, cub))
		return (1);
	if (!cub->no_texture || !cub->so_texture \
	|| !cub->we_texture || !cub->ea_texture)
		return (0); // 1로 바꿔야 함!!
	return (0);
}
