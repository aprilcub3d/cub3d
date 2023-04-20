/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:04:06 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/20 18:10:57 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define  CUB3D_H

# include "../libft/libft.h"
# include "get_next_line.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>

# define N 0
# define S 1
# define W 2
# define E 3

typedef struct s_map
{
	void	*mlx;
	void	*no_texture;
	void	*so_texture;
	void	*we_texture;
	void	*ea_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	int		direction;
	int		position[2];
	char	*buffer;
	char	**map_split;
	int		**map;
	int		map_width;
	int		map_height;
}	t_map;

int	free_map(t_map *cub);
int	top_bot(t_map *cub);
int	map_end(t_map *cub);
int	make_buffer(int fd, t_map *cub);

int	free_color(char *line, char *color_line, char **color_split, int flag);
int	floor_color(char *line, t_map *cub);
int	ceiling_color(char *line, t_map *cub);
int	fc_color(int fd, t_map *cub);

int	print_error(int fd);
int	len_split(char **s);
int	free_lines(char *l, char **s, int er);
int	file_extension(int argc, char **argv);

int	map_valid(int fd, t_map *cub);
int	texture(int fd, t_map *cub);
int	texture2(int fd, t_map *cub);
int	texture3(int fd, t_map *cub);
int	texture4(int fd, t_map *cub);
#endif
