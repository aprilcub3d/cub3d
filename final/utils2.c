/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:59:52 by jijoo             #+#    #+#             */
/*   Updated: 2023/05/12 05:35:12 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	config_init(t_map *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		cub->config_box[i] = 0;
		i++;
	}
}

int	config_fin(t_map *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (cub->config_box[i] != 1)
			return (1);
		i++;
	}
	return (0);
}

int	compare(char *line, char **split, t_map *cub)
{
	if (!ft_strncmp(split[0], "NO", 3))
		return (texture(line, split, cub));
	else if (!ft_strncmp(split[0], "SO", 3))
		return (texture2(line, split, cub));
	else if (!ft_strncmp(split[0], "WE", 3))
		return (texture3(line, split, cub));
	else if (!ft_strncmp(split[0], "EA", 3))
		return (texture4(line, split, cub));
	else if (!ft_strncmp(split[0], "F", 2))
		return (floor_color(line, split, cub));
	else if (!ft_strncmp(split[0], "C", 2))
		return (ceiling_color(line, split, cub));
	else
	{
		free(line);
		dobby(split, len_split(split));
		return (1);
	}
}

int	config(int fd, t_map *cub)
{
	char	*line;
	char	**split;
	int		i;
	int		err;

	err = 0;
	i = 0;
	while (i++ < 6)
	{
		line = get_next_line(fd);
		while (line && line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
		}
		if (!line)
			return (1);
		split = ft_split(line, ' ');
		err += compare(line, split, cub);
	}
	return (err + config_fin(cub));
}
