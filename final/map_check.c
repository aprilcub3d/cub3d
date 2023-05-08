/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:11:57 by jijoo             #+#    #+#             */
/*   Updated: 2023/05/08 20:33:59 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	top_bot(t_map *cub)
{
	int	i;

	i = 0;
	while (cub->map_split[0][i])
	{
		if (cub->map_split[0][i] != '1' \
		&& (cub->map_split[0][i] != ' '))
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
	int		h;
	int		i;
	char	**split;

	h = 0;
	while (h < cub->map_height)
	{
		split = ft_split(cub->map_split[h], ' ');
		i = 0;
		while (i < len_split(split))
		{
			if (split[i][0] != '1' || split[i][ft_strlen(split[i]) - 1] != '1')
			{
				dobby(split, len_split(split));
				return (1);
			}
			i++;
		}
		dobby(split, len_split(split));
		h++;
	}
	return (0);
}

int	middle2(t_map *cub)
{
	int	i;
	int	j;

	i = 1;
	while (i < cub->map_height - 1)
	{
		j = 0;
		while (j < (int)ft_strlen(cub->map_split[i]))
		{
			if (cub->map_split[i - 1][j] == ' ' \
			|| cub->map_split[i + 1][j] == ' ')
			{
				if (cub->map_split[i][j] == '0')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	other_char(t_map *cub)
{
	int	i;
	int	position;

	i = 0;
	while (i < (int)ft_strlen(cub->buffer))
	{
		if (ft_strchr("01 ", cub->buffer[i]) == 0 && cub->buffer[i] != '\n' && \
		ft_strchr("NSWE", cub->buffer[i]) == 0)
			return (1);
		i++;
	}
	i = 0;
	position = 0;
	while (i < (int)ft_strlen(cub->buffer))
	{
		if (ft_strchr("NSWE", cub->buffer[i]))
		{
			position++;
			cub->direction = cub->buffer[i];
		}
		i++;
	}
	if (position != 1)
		return (1);
	return (0);
}

int	map_check(t_map *cub)
{
	int	i;

	cub->map_split = ft_split(cub->buffer, '\n');
	cub->map_height = len_split(cub->map_split);
	cub->map_width = 0;
	i = 0;
	while (i < cub->map_height)
	{
		if (cub->map_width < (int)ft_strlen(cub->map_split[i]))
			cub->map_width = (int)ft_strlen(cub->map_split[i]);
		i++;
	}
	if (other_char(cub))
		return (free_map(cub));
	if (top_bot(cub))
		return (free_map(cub));
	if (middle(cub))
		return (free_map(cub));
	if (middle2(cub))
		return (free_map(cub));
	return (0);
}
