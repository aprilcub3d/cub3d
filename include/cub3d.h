/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:04:06 by jijoo             #+#    #+#             */
/*   Updated: 2023/04/19 19:14:45 by jijoo            ###   ########.fr       */
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
	char	*map;
}	t_map;

#endif
