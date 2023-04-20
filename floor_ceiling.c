/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:01:52 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/20 16:53:28 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	free_color(char *line, char *color_line, char **color_split, int flag)
{
	if (flag)
		dobby(color_split, len_split(color_split));
	free(line);
	free(color_line);
	return (1);
}

int	floor_color(char *line, t_map *cub)
{
	char	*color_line;
	char	**color_split;
	int		i;

	if (ft_strncmp(line, "F ", 2))
	{
		free(line);
		return (1);
	}
	color_line = ft_strdup(line + 2);
	color_split = ft_split(color_line, ',');
	if (len_split(color_split) != 3)
		return (free_color(line, color_line, color_split, 1));
	i = 0;
	while (i < 3)
	{
		if ((ft_atoi(color_split[i]) < 0) || (ft_atoi(color_split[i]) > 255))
			return ((free_color(line, color_line, color_split, 1)));
		cub->floor_color[i] = ft_atoi(color_split[i]);
		i++;
	}
	free_color(line, color_line, color_split, 1);
	return (0);
}

int	ceiling_color(char *line, t_map *cub)
{
	char	*color_line;
	char	**color_split;
	int		i;

	if (ft_strncmp(line, "C ", 2))
	{
		free(line);
		return (1);
	}
	color_line = ft_strdup(line + 2);
	color_split = ft_split(color_line, ',');
	if (len_split(color_split) != 3)
		return (free_color(line, color_line, color_split, 1));
	i = 0;
	while (i < 3)
	{
		if ((ft_atoi(color_split[i]) < 0) || (ft_atoi(color_split[i]) > 255))
			return ((free_color(line, color_line, color_split, 1)));
		cub->ceiling_color[i] = ft_atoi(color_split[i]);
		i++;
	}
	free_color(line, color_line, color_split, 1);
	return (0);
}

int	fc_color(int fd, t_map *cub)
{
	char	*line;

	line = get_next_line(fd);
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (floor_color(line, cub))
		return (1);
	line = get_next_line(fd);
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (ceiling_color(line, cub))
		return (1);
	return (0);
}
