/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:11:07 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/19 20:22:02 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	print_error(void)
{
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

int	free_lines(char *l, char **s, int er)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	dobby(s, i);
	free(l);
	return (er);
}

int	file_extension(int argc, char **argv)
{
	if (argc != 2)
		return (print_error());
	if (!ft_strchr(argv[1], '.'))
		return (print_error());
	if (ft_strncmp(ft_strchr(argv[1], '.'), ".cub", 5))
		return (print_error());
	return (0);
}

int	texture2(int fd, t_map *cub)
{
	char	*line;
	char	**split;
	int		room;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "SO", 2))
		return (free_lines(line, split, 1));
	cub->so_texture = mlx_xpm_file_to_image(cub->mlx, split[1], &room, &room);
	free_lines(line, split, 0);
	return (0);
}

int	texture3(int fd, t_map *cub)
{
	char	*line;
	char	**split;
	int		room;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "WE", 2))
		return (free_lines(line, split, 1));
	cub->we_texture = mlx_xpm_file_to_image(cub->mlx, split[1], &room, &room);
	free_lines(line, split, 0);
	return (0);
}

int	texture4(int fd, t_map *cub)
{
	char	*line;
	char	**split;
	int		room;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "EA", 2))
		return (free_lines(line, split, 1));
	cub->ea_texture = mlx_xpm_file_to_image(cub->mlx, split[1], &room, &room);
	free_lines(line, split, 0);
	return (0);
}

int	texture(int fd, t_map *cub)
{
	char	*line;
	char	**split;
	int		room;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (1);
	split = ft_split(line, ' ');
	if (len_split(split) != 2)
		return (free_lines(line, split, 1));
	if (ft_strncmp(split[0], "NO", 2))
		return (free_lines(line, split, 1));
	cub->no_texture = mlx_xpm_file_to_image(cub->mlx, split[1], &room, &room);
	free_lines(line, split, 0);
	if (texture2(fd, cub) || texture3(fd, cub) || texture4(fd, cub))
		return (1);
	if (!cub->no_texture || !cub->so_texture \
	|| !cub->we_texture || !cub->ea_texture)
		return (0); // 1로 바꿔야 함!!
	return (0);
}
/*
int	fc_color(int fd, t_map *cub)
{
	char	*line;
	int		room;

	line = get_next_line(fd);
	while (ft_strlen(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (ft_strncmp(line, "F ", 2))
	{
		free(line);
		return (1);
	}
	return (0);
}*/

int	map_valid(int fd, t_map *cub)
{
	if (texture(fd, cub))
		return (1);
//	if (fc_color(fd, cub))
//		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	cub;

	if (file_extension(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error());
	if (map_valid(fd, &cub))
		return (print_error());
	close(fd);
	return (0);
}
