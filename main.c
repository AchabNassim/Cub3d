#include "cub3d.h"

int main (int ac, char **av) {
    t_game_data     game_data;

    if (ac != 2)
        return (EXIT_FAILURE);
    init_struct(&game_data);
    printf("at init \t\tsky hex val == %ld floor hex val == %ld\n", game_data.textures.sky_hex, game_data.textures.floor_hex);
    if (get_file_content(av[1], &game_data) == 0)
    {
        if (parse_values(&game_data) == 0) {}
            printf("after init \t\tsky hex val == %ld floor hex val == %ld\n", game_data.textures.sky_hex, game_data.textures.floor_hex);
    }
    return (EXIT_SUCCESS);
}