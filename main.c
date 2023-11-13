#include "MLX42/include/MLX42/MLX42.h"
#include "cub3d.h"

int main (int ac, char **av) {
    t_game_data     game_data;
    void            *mlx;
    mlx_texture_t *texture;

    if (ac != 2)
    {
        printf("Please provide a map file with .cub extenstion in the maps directory");
        return (EXIT_FAILURE);
    }
    init_game(av[1], &game_data);
    mlx = mlx_init(1080, 1000, "hey", false);
    texture = mlx_load_png("./brickwall.png");
    mlx_image_t *img = mlx_texture_to_image(mlx, texture);
    mlx_image_to_window(mlx, img, 0, 0);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}