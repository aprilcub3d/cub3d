/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:59:52 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/20 21:12:56 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	map_end(t_map *cub)
{
	int	i;

	i = 0;
	while (cub->buffer[i])
	{
		if (cub->buffer[i] == '\n' && cub->buffer[i + 1] == '\n')
		{
			while (cub->buffer[i])
			{
				if (cub->buffer[i] != '\n')
					return (1);
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	print_error(int fd)
{
	if (fd != -1)
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
	dobby(cub->map_split, len_split(cub->map_split));
	return (1);
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
	cub->buffer = malloc(cub->buffer_size);
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
