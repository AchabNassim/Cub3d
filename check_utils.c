#include "cub3d.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

// returns 1 if the string contains a character that isn't a map character
int is_map_line(char *line)
{
    while (*line)
    {
        if (*line != '0' && *line != '1' && *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W' && *line != ' ' && *line != '\t' && *line != '\n')
            return (1);
        line++;
    }
    return (0);
}


// returns 1 if line isn't empty
int empty_line(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] != '\n')
    {
        if (line[i] != ' ' && line[i] != '\t')
            return (1);
        i++;
    }
    return (0);
}

int check_path_rgb(t_game_data *data)
{
    if (data->paths.no_path == NULL)
        return (1);
    if (data->paths.so_path == NULL)
        return (1);
    if (data->paths.we_path == NULL)
        return (1);
    if (data->paths.ea_path == NULL)
        return (1);
    if (data->textures.floor_hex == -1)
        return (1);
    if (data->textures.sky_hex == -1)
        return (1);
    return (0);
}

void    check_map(t_game_data *data)
{
    int i;

    i = 0;
    while (data->map[i] != NULL)
    {
        if (is_map_line(data->map[i]) == 1 || !empty_line(data->map[i])) {
            printf("Error, Map can only be composed of 01NSWE.\n");
            exit(1);
        }
        i++;
    }
}

void    get_values(t_game_data *data)
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
