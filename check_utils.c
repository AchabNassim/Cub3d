#include "cub3d.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

void    init_struct(t_game_data *game_data) 
{
    game_data->file_content = NULL;
    game_data->paths.no_path = NULL;
    game_data->paths.so_path = NULL;
    game_data->paths.we_path = NULL;
    game_data->paths.ea_path = NULL;
    game_data->textures.sky_hex = -1;
    game_data->textures.floor_hex = -1;
}

int check_extension(char *file, char *extension) 
{
    char    *file_extension;

    file_extension = ft_strchr(file, '.');
    if (file_extension != NULL) {
        if (ft_strncmp(file_extension, extension, ft_strlen(extension) + 1) == 0 ) 
            return (0);
        else
            return (0);
    }
    return (1);
}

int lines_in_file(char *path) 
{
    int fd;
    int lines;

    fd  = open(path, O_RDONLY);
    lines = 0;
    if (fd < 0)
        return (0);
    while (get_next_line(fd) != NULL) {
        lines++;
    }
    close(fd);
    return (lines);
}

int get_file_content(char *path, t_game_data *data) 
{
    int     i;
    int     fd;
    int     number_of_lines;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (1);
    i = 0;
    number_of_lines = lines_in_file(path);
    data->file_content = ft_calloc(number_of_lines + 1, sizeof(char *));
    while (1)
    {
        data->file_content[i] = get_next_line(fd);
        if (data->file_content[i] == NULL)
            break ;
        i++;
    }
    data->file_content[i] = NULL;
    return (0);
}

int map_line(char *line)
{
    while (*line)
    {
        if (*line != '0' && *line != '1' && *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W' && *line != ' ' && *line != '\t' && *line != '\n')
            return (1);
        line++;
    }
    return (0);
}

int not_empty_line(char *line)
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

int check_valid_values(t_game_data *data)
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

int parse_values(t_game_data *data, int length) 
{
    int i;

    i = 0;
    while (data->file_content[i] != NULL && i < length)
    {
        if (ft_strnstr(data->file_content[i], "NO", ft_strlen(data->file_content[i]))) {
            data->paths.no_path = ft_strnstr(data->file_content[i], "img", ft_strlen(data->file_content[i]));
        }
        else if (ft_strnstr(data->file_content[i], "SO", ft_strlen(data->file_content[i]))) {
            data->paths.so_path = ft_strnstr(data->file_content[i], "img", ft_strlen(data->file_content[i]));
        }
        else if (ft_strnstr(data->file_content[i], "WE", ft_strlen(data->file_content[i]))) {
            data->paths.we_path = ft_strnstr(data->file_content[i], "img", ft_strlen(data->file_content[i]));
        }
        else if (ft_strnstr(data->file_content[i], "EA", ft_strlen(data->file_content[i]))) {
            data->paths.ea_path = ft_strnstr(data->file_content[i], "img", ft_strlen(data->file_content[i]));
        }
        else if (ft_strchr(data->file_content[i], 'F'))
            data->textures.floor_hex = rgb_to_hex(return_rgb_string(data->file_content[i]));
        else if (ft_strchr(data->file_content[i], 'C'))
            data->textures.sky_hex = rgb_to_hex(return_rgb_string(data->file_content[i]));
        i++;
    }
    if (check_valid_values(data) == 0)
        return (0);
    printf("Please enter a valid map with all the textures and rgb values (6 in total)\n");
    return (1);
}

int    store_map(t_game_data *data, int index)
{
    int i;
    int v;

    i = 0;
    v = 0;
    while (data->file_content[index] != NULL)
    {
        if (map_line(data->file_content[index]) == 0 && not_empty_line(data->file_content[index]))
            v = 1;
        if (!not_empty_line(data->file_content[index]))
        {
            if (v == 1)
                return (1);
            else
                index++;
        }
        else
        {
            data->map[i] = data->file_content[index];
            i++;
            index++;
        }
    }
    data->map[i] = NULL;
    return (0);
}

void    check_map(t_game_data *data)
{
    int i;

    i = 0;
    while (data->map[i] != NULL)
    {
        if (map_line(data->map[i]) == 1 || !not_empty_line(data->map[i])) {
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

        if (not_empty_line(data->file_content[i]))
            v++;
        if (v == 6)
            break ;
        i++;
    }
    if (parse_values(data, ++i) == 0)
    {
        store_map(data, i);
        while (data->file_content[i] != NULL)
        {
            if (map_line(data->file_content[i]) == 1) {
                printf("Error, Map can only be composed of 01NSWE.\n");
                exit(1);
            }
            i++;
        }
    }
    else {
        printf("Error, Textures needed weren't provided.\n");
        exit(1);
    }
}





// int check_if_map_line(char *line) 
// {
//     int space;
//     int map_char;
//     int val_char;
//     int i;

//     i = 0;
//     space = 0;
//     val_char = 0;
//     map_char = 0;
//     while (line[i] && line[i] != '\n')
//     {
//         if (line[i] == ' ' || line[i] == '\t')
//             space = 1;
//         else if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
//             val_char = 1;
//         else if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
//             map_char = 1;
//         i++;
//     }
//     if ((i == 0 && line[i] == '\n') || val_char || (space == 1 && map_char == 0))
//         return (1);
//     return (0);
// }