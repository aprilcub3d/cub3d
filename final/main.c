/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:11:07 by jijoo             #+#    #+#             */
/*   Updated: 2023/05/08 20:35:26 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/raycasting.h"

int	file_extension(int argc, char **argv)
{
	if (argc != 2)
		return (print_error(-1));
	if (!ft_strchr(argv[1], '.'))
		return (print_error(-1));
	if (ft_strncmp(ft_strchr(argv[1], '.'), ".cub", 5))
		return (print_error(-1));
	return (0);
}

int	map_valid(int fd, t_map *cub)
{
	if (texture_err(cub))
		return (free_path(cub));
	if (make_buffer(fd, cub))
		return (free_path(cub));
	if (map_check(cub))
		return (free_path(cub));
	mapping(cub);
	return (0);
}

int	get_size(char *file)
{
	int		fd;
	int		size;
	char	*line;

	fd = open(file, O_RDONLY);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size += (int)ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (size);
}

void	leak_check(void)
{
	system("leaks --list -- cub3D");
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		flag;
	t_map	cub;

	atexit(leak_check);
	flag = 0;
	if (file_extension(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error(-1));
	cub.buffer_size = get_size(argv[1]);
	config_init(&cub);
	if (config(fd, &cub))
		exit(print_error(fd));
	if (map_valid(fd, &cub))
		exit(print_error(fd));
	close(fd);
	if (make_window(&cub))
		flag = print_error(0);
	free_map(&cub);
	exit(flag);
}
