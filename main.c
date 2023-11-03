#include "MLX42/include/MLX42/MLX42.h"
#include "cub3d.h"

int main (int ac, char **av) {
    t_game_data     game_data;
    void            *mlx;
    // mlx_image_t *img;

    // if (ac != 2)
    // {
    //     printf("Please provide a map file with .cub extenstion in the maps directory");
    //     return (EXIT_FAILURE);
    // }
    // init_game(av[1], &game_data);
    mlx = mlx_init(1080, 1000, "hey", false);
    // img = mlx_new_image(mlx, 1000, 1000);
    // mlx_image_to_window(mlx, img, 0, 0);
    mlx_loop(mlx);
    // mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}