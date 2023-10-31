#include "cub3d.h"

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

int check_if_map_line(char *line) 
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '0' && line[i] != '1' && line[i] != ' ' 
        && line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
        {
            return (1);
        }
        i++;
    }
    return (0);
}

char    *return_rgb_string(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != 'F' && line[i] != 'C' && line[i] != ' ' && line[i] != '\t')
            return (&line[i]);
        i++;
    }
    return (NULL);
}

long    rgb_to_hex(char *line) 
{
    char    **values;
    int     r;
    int     g;
    int     b;

    values = ft_split(line, ',');
    if (values && values[0] && values[1] && values[2])
    {
        r = ft_atoi(values[0]);
        g = ft_atoi(values[1]);
        b = ft_atoi(values[2]);
        if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
        {
            long hex_val = ((long)r << 16) | ((long)g << 8) | (long)b;
            return (hex_val);
        }
    }
    return (-1);
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

int parse_values(t_game_data *data) 
{
    int i;

    i = 0;
    while (data->file_content[i] != NULL)
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
    return (1);
}