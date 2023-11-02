
#include "cub3d.h"

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

void    check_dimensions(t_game_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j] && data->map[i][j] != '\n')
            j++;
        if (j > 30)
        {
            printf("Column width surpassed (max 30)\n");
            exit (1);
        }
        i++;
    }
    if (i > 20)
    {
        printf("Row height surpassed (max 20)");
        exit (1);
    }
}


void    check_valid_path(t_game_data *data, int i, int j)
{
    printf("char found is %c\n", data->map[i][j]);
    if ((i < 0 || j < 0) || !data->map[i] || !data->map[i][j] || data->map[i][j] == '1' || data->map[i][j] == '\n')
        return ;
    else if (data->map[i][j] == ' ' || data->map[i][j] == '\t' || data->map[i][j] == '\n')
    {
        printf("char found is %c\n", data->map[i][j]);
        printf("Path is not valid\n");
        exit (1);
    }
    printf("char found is %c\n", data->map[i][j]);
    check_valid_path(data, i, j + 1);
    check_valid_path(data, i, j - 1);
    check_valid_path(data, i + 1, j);
    check_valid_path(data, i - 1, j);
}