/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:01:52 by jijoo             #+#    #+#             */
/*   Updated: 2023/05/12 05:33:16 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	free_color(char *line, char **split, char *color_line, char **color_split)
{
	dobby(color_split, len_split(color_split));
	free(line);
	free(color_line);
	dobby(split, len_split(split));
	return (1);
}

int	floor_color(char *line, char **split, t_map *cub)
{
	char	*color_line;
	char	**color_split;
	int		i;

	color_line = ft_strdup(line + 2);
	color_split = ft_split(color_line, ',');
	if (cub->config_box[4])
		return (free_color(line, split, color_line, color_split));
	if (len_split(color_split) != 3)
		return (free_color(line, split, color_line, color_split));
	i = 0;
	while (i < 3)
	{
		if ((ft_atoi(color_split[i]) < 0) || (ft_atoi(color_split[i]) > 255))
			return ((free_color(line, split, color_line, color_split)));
		cub->floor_color[i] = ft_atoi(color_split[i]);
		i++;
	}
	free_color(line, split, color_line, color_split);
	cub->config_box[4] = 1;
	return (0);
}

int	ceiling_color(char *line, char **split, t_map *cub)
{
	char	*color_line;
	char	**color_split;
	int		i;

	color_line = ft_strdup(line + 2);
	color_split = ft_split(color_line, ',');
	if (cub->config_box[5])
		return (free_color(line, split, color_line, color_split));
	if (len_split(color_split) != 3)
		return (free_color(line, split, color_line, color_split));
	i = 0;
	while (i < 3)
	{
		if ((ft_atoi(color_split[i]) < 0) || (ft_atoi(color_split[i]) > 255))
			return ((free_color(line, split, color_line, color_split)));
		cub->ceiling_color[i] = ft_atoi(color_split[i]);
		i++;
	}
	free_color(line, split, color_line, color_split);
	cub->config_box[5] = 1;
	return (0);
}
