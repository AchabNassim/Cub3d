#include "cub3d.h"

int main (int ac, char **av) {
    t_game_data     game_data;

    if (ac != 2)
        return (EXIT_FAILURE);
    init_game(av[1], &game_data);
    return (EXIT_SUCCESS);
}