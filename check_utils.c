#include "cub3d.h"

int check_extension(char *file, char *extension) 
{
    char    *file_extension;

    file_extension = ft_strchr(file, '.');
    if (file_extension != NULL) {
        if (ft_strncmp(file_extension, extension, ft_strlen(extension) + 1) == 0 ) 
            return (SUCCESS);
        else
            return (SUCCESS);
    }
    return (FAILURE);
}

int file_line_number(char *path) 
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

int store_map(char *path, t_game_data *data) 
{
    int     i;
    int     fd;
    int     number_of_lines;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (FAILURE);
    i = 0;
    number_of_lines = file_line_number(path);
    data->file_content = ft_calloc(number_of_lines + 1, sizeof(char *));
    while (1)
    {
        data->file_content[i] = get_next_line(fd);
        if (data->file_content[i] == NULL)
            break ;
        i++;
    }
    data->file_content[i] = NULL;
    return (SUCCESS);
}

unsigned long createRGBA(int r, int g, int b, int a)
{   
    return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (a & 0xff);
}

int check_val(t_game_data *)
{
    int v;

    v = 3;
    while ()
}

int parse_map(t_game_data *data)
{

}