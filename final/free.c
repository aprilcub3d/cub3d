/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:44:02 by seonjeon          #+#    #+#             */
/*   Updated: 2023/05/08 19:48:33 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	free_texture(int **t)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (t[i])
			free(t[i]);
		i++;
	}
	if (t)
		free(t);
	return (-1);
}

int	free_path(t_map *cub)
{
	if (cub->no_texture)
		free(cub->no_texture);
	if (cub->so_texture)
		free(cub->so_texture);
	if (cub->we_texture)
		free(cub->we_texture);
	if (cub->ea_texture)
		free(cub->ea_texture);
	return (1);
}

int	texture_err(t_map *cub)
{
	int	fd;

	fd = open(cub->no_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(cub->so_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(cub->we_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(cub->ea_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}
