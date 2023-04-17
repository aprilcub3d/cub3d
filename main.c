#include "include/cub3d.h"

int file_extension(int argc, char **argv)
{
    if (argc != 2)
    {
        perror("Error\n");
        return (1);
    }
    if (!ft_strchr(argv[1], '.'))
    {
        perror("Error\n");
        return (1);
    }
    if (ft_strncmp(ft_strchr(argv[1], '.'), ".cub", 5))
    {
        perror("Erorr\n");
        return (1);
    }
    return (0);
}

int main(int argc, char *argv[])
{
    if (file_extension(argc, argv))
        return (1);
    return (0);
}