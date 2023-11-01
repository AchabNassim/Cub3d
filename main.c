#include "cub3d.h"

int main (int ac, char **av) {
    t_game_data     game_data;

    if (ac != 2)
        return (EXIT_FAILURE);
    init_struct(&game_data);
    if (get_file_content(av[1], &game_data) == 0)
    {
        get_values(&game_data);
        for (int i = 0; game_data.map[i] != NULL; i++) {
            printf("%s", game_data.map[i]);
        }
    }
    return (EXIT_SUCCESS);
}