/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:11:57 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/20 18:11:25 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	map_end(t_map *cub)
{
	size_t	i;

	i = 0;
	while (cub->buffer[i])
	{
		if (cub->buffer[i] == '\n' && cub->buffer[i + 1] == '\n')
		{
			while (cub->buffer[i])
			{
				if (buf[i] != '\n')
				{
					free(cub->buffer);
					return (1);
				}
				i++;
			}
			return (0);
		}
		i++;
	}
	return (0);
}

int	top_bot(t_map *cub)
{
	int	i;

	i = 0;
	while (cub->map_split[0][i])
	{
		if (cub->map_split[0][i] != '1' \
		&& cub->map_split[0][i] != ' ')
			return (1);
		i++;
	}
	i = 0;
	while (cub->map_split[cub->map_height - 1][i])
	{
		if (cub->map_split[cub->map_height - 1][i] != '1' \
		&& cub->map_split[cub->map_height - 1][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	middle(t_map *cub)
{
	int	h;

	h = 0;
	while (h < cub->map_height)
	{
		h++;
	}
	return (0);
}

int	map_check(t_map *cub)
{
	int	i;

	cub->map_split = ft_split(cup->buffer, '\n');
	cub->map_height = len_split(cub->map_split);
	cub->map_width = 0;
	i = 0;
	while (i < cub->map_height)
	{
		if (cub->map_width < ft_strlen(cub->map_split[i]))
			cub->map_width = ft_strlen(cub->map_split[i]);
		i++;
	}
	if (top_bot(cub))
		return (free_map(cub));
	if (middle(cub))
		return (free_map(cub));
	return (0);
}

int	make_buffer(int fd, t_map *cub)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	cub->buffer = ft_strdup("");
	while (line)
	{
		ft_strcat(cub->buffer, line);
		free(line);
		line = get_next_line(fd);
	}
	if (map_end(cub))
		return (1);
	return (0);
}
