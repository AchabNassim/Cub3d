#include "cub3d.h"

void    init_struct(t_game_data *game_data) 
{
    game_data->file_content = NULL;
    game_data->paths.no_path = NULL;
    game_data->paths.so_path = NULL;
    game_data->paths.we_path = NULL;
    game_data->paths.ea_path = NULL;
    game_data->map = NULL;
    game_data->textures.sky_hex = -1;
    game_data->textures.floor_hex = -1;
    game_data->player.direction = 0;
    game_data->player.i = 0;
    game_data->player.j = 0;
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

void init_game(char *path_file, t_game_data *data)
{
    init_struct(data);
    if (check_extension(path_file, ".cub") == 1)
    {
        printf("Please enter a map folder with the correct extension (\".cub\")");
        exit (1);
    }
    get_file_content(path_file, data);
    parse_file_content(data);
    duplicate_player(data);
    get_player_pos(data);
    check_dimensions(data);
    check_walls(data);
    check_valid_path(data);
    printf("runs well\n");
}