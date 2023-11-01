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