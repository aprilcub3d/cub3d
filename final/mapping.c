/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:47:08 by jijoo             #+#    #+#             */
/*   Updated: 2023/05/03 20:06:50 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	numbering(char c)
{
	if (c == ' ')
		return (-1);
	else if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else
		return (c);
}

void	positions(t_map *cub, int i, int j)
{
	cub->position[0] = i;
	cub->position[1] = j;
}

void	mapping(t_map *cub)
{
	int	i;
	int	j;

	cub->map = (int **)malloc(sizeof(int *) * cub->map_height);
	i = 0;
	while (i < cub->map_height)
	{
		cub->map[i] = (int *)malloc(sizeof(int) * ft_strlen(cub->map_split[i]));
		i++;
	}
	i = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < (int)ft_strlen(cub->map_split[i]))
		{
			if (ft_strchr("NSWE", cub->map_split[i][j]))
				positions(cub, i, j);
			cub->map[i][j] = numbering(cub->map_split[i][j]);
			j++;
		}
		i++;
	}
}
