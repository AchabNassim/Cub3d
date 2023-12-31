#include "cub3d.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

int check_extension(char *file, char *extension) 
{
    char    *file_extension;

    file_extension = ft_strchr(file, '.');
    if (file_extension != NULL) 
    {
        if (ft_strncmp(file_extension, extension, ft_strlen(extension) + 1) == 0 )
            return (0);
        else
            return (1);
    }
    return (1);
}

void    parse_file_content(t_game_data *data)
{
    int v;
    int i;

    i = 0;
    v = 0;
    while (data->file_content[i] != NULL)
    {
        if (empty_line(data->file_content[i]))
            v++;
        if (v == 6)
            break ;
        i++;
    }
    if (store_textures(data, ++i) == 0)
    {
        store_map(data, i);
        check_map(data);
    }
    else {
        printf("Error, Textures needed weren't provided.\n");
        exit(1);
    }
}
