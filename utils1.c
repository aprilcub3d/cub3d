/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:59:52 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/20 18:06:37 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	print_error(int fd)
{
	close(fd);
	perror("Error\n");
	return (1);
}

int	len_split(char **s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	free_map(t_map *cub)
{
	free(cub->buffer);
	dobby(cub->map_split, len_split(map_split));
	return (1);
}
