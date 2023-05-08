/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:04:06 by jijoo             #+#    #+#             */
/*   Updated: 2023/05/08 20:34:42 by jijoo            ###   ########.fr       */
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

typedef struct s_map
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	int		direction;
	int		position[2];
	int		buffer_size;
	char	*buffer;
	char	**map_split;
	int		**map;
	int		map_width;
	int		map_height;
}	t_map;

int		texture_err(t_map *cub);
int		numbering(char c);
void	mapping(t_map *cub);
int		get_size(char *file);
int		cmp(char c, char *charset);
void	ft_res(int str_len, int *table, char **res, char *str);
int		*ft_table(int str_len, char *str, char *charset);
char	**ft_split2(char *str, char *charset);

int		white_space(char c);
int		other_char(t_map *cub);
int		middle1(t_map *cub);
int		middle2(t_map *cub);
int		free_map(t_map *cub);
int		top_bot(t_map *cub);
int		map_end(t_map *cub);
int		make_buffer(int fd, t_map *cub);
int		map_check(t_map *cub);

int		free_color(char *line, char *color_line, char **color_split, int flag);
int		floor_color(char *line, t_map *cub);
int		ceiling_color(char *line, t_map *cub);
int		fc_color(int fd, t_map *cub);

int		print_error(int fd);
int		len_split(char **s);
int		free_lines(char *l, char **s, int er);
int		file_extension(int argc, char **argv);

int		map_valid(int fd, t_map *cub);
int		texture(int fd, t_map *cub);
int		texture2(int fd, t_map *cub);
int		texture3(int fd, t_map *cub);
int		texture4(int fd, t_map *cub);

int		make_window(t_map *cub);
#endif
