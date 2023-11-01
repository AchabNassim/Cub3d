#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

#define SUCCESS 1
#define FAILURE -1

typedef struct s_paths {
    char    *no_path;
    char    *so_path;
    char    *we_path;
    char    *ea_path;
} t_paths;

typedef struct  s_textures {
    // unsigned long   no_texture;
    // unsigned long   so_texture;
    // unsigned long   we_texture;
    // unsigned long   ea_texture;
    long   sky_hex;
    long   floor_hex;
} t_textures;

typedef struct  s_game_data {
    char        **file_content;
    char        **map;
    t_paths     paths;
    t_textures  textures;
} t_game_data;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

void    init_struct(t_game_data *game_data);
int     check_extension(char *file, char *extension);
int     get_file_content(char *path, t_game_data *data);
char    *return_rgb_string(char *line);
long    rgb_to_hex(char *line);
int     parse_values(t_game_data *data, int length);
int     check_if_map_line(char *line);
void    get_values(t_game_data *data);
int    store_map(t_game_data *data, int index);


# endif