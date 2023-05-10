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

int	texture2(char *line, char **split, t_map *cub)
{
	if (cub->config_box[1])
		return (free_lines(line, split, 1));
	cub->so_texture = NULL;
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	cub->so_texture = ft_strdup(split[1]);
	cub->so_texture[ft_strlen(cub->so_texture) - 1] = 0;
	free_lines(line, split, 0);
	cub->config_box[1] = 1;
	return (0);
}

int	texture3(char *line, char **split, t_map *cub)
{
	if (cub->config_box[2])
		return (free_lines(line, split, 1));
	cub->we_texture = NULL;
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	cub->we_texture = ft_strdup(split[1]);
	cub->we_texture[ft_strlen(cub->we_texture) - 1] = 0;
	free_lines(line, split, 0);
	cub->config_box[2] = 1;
	return (0);
}

int	texture4(char *line, char **split, t_map *cub)
{
	if (cub->config_box[3])
		return (free_lines(line, split, 1));
	cub->ea_texture = NULL;
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	cub->ea_texture = ft_strdup(split[1]);
	cub->ea_texture[ft_strlen(cub->ea_texture) - 1] = 0;
	free_lines(line, split, 0);
	cub->config_box[3] = 1;
	return (0);
}

int	texture(char *line, char **split, t_map *cub)
{
	if (cub->config_box[0])
		return (free_lines(line, split, 1));
	cub->no_texture = NULL;
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	cub->no_texture = ft_strdup(split[1]);
	cub->no_texture[ft_strlen(cub->no_texture) - 1] = 0;
	free_lines(line, split, 0);
	cub->config_box[0] = 1;
	return (0);
}
