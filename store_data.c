#include "cub3d.h"

int store_textures(t_game_data *data, int length) 
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
    if (check_path_rgb(data) == 0)
        return (0);
    printf("Please enter a valid map with all the textures and rgb values (6 in total)\n");
    exit (1);
}

int map_length(t_game_data *data, int index)
{
    int i;

    i = 0;
    while (data->file_content[index] != NULL)
    {
        i++;
        index++;
    }
    return (i);
}

int    store_map(t_game_data *data, int index)
{
    int i;

    i = 0;
    while (data->file_content[index] != NULL && (empty_line(data->file_content[index]) == 0))
        index++;
    data->map = malloc((map_length(data, index) + 1) * sizeof(char *));
    while (data->file_content[index] != NULL)
    {
        data->map[i] = data->file_content[index];
        i++;
        index++;
    }
    data->map[i] = NULL;
    return (0);
}