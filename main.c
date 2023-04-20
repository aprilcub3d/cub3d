/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:11:07 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/20 17:59:19 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

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

int	map_valid(int fd, t_map *cub)
{
	if (texture(fd, cub))
		return (1);
	if (fc_color(fd, cub))
		return (1);
	if (make_buffer(fd, cub))
		return (1);
	if (map_check(cub))
		return (1);
	return (0);
}

void	leak(void)
{
	system("leaks cub3d");
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	cub;

	atexit(leak);
	if (file_extension(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error());
	if (map_valid(fd, &cub))
		return (print_error(fd));
	close(fd);
	exit (0);
	return (0);
}
