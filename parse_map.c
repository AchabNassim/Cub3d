#include "cub3d.h"

int get_map_index(t_game_data *data)
{
    int i;

    i = 0;
    while (data->file_content[i] && check_if_map_line(data->file_content[i]))
    {
        i++;
    }
    return (i);
}

// int check_newlines(t_game_data *data)
// {
//     int i;
//     int j;
//     int v;

//     i = 0;
//     while (data->file_content[i] && check_if_map_line(data->file_content[i]))
//     {
//         i++;
//     }
//     while (data->file_content[i])
//     {
//         while (data->file_content[i][j])
//         {

//         }
//     }
//     while 
// }