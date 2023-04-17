#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define N 0
#define S 1
#define W 2
#define E 3

typedef struct s_map
{
    // 동서남북 텍스쳐
    int     floor_color[3];
    int     ceiling_color[3];
    int     direction;
    int     position[2];
    char    *map
} t_map;


#endif