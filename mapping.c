/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:47:08 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/20 21:27:13 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	mapping(t_map *cub)
{
	int	i;
	int	j;

	cub->map = (int **)malloc(sizeof(int) * cub->map_height);
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
			if (cub->map_split[i][j] == ' ')
				cub->map[i][j] =  -1;
			else if (cub->map_split[i][j] == '0')
				cub->map[i][j] = 0;
			else if (cub->map_split[i][j] == '1')
				cub->map[i][j] = 1;
			else
				cub->map[i][j] = cub->map_split[i][j];
			j++;
		}
		i++;
	}

	printf("map test\n");
	for (i = 0; i < cub->map_height; i++)
	{
		for (j = 0; j < (int)ft_strlen(cub->map_split[i]); j++)
		{
			printf("%d", cub->map[i][j]);
		}
		printf("\n");
	}
}
