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


typedef struct  s_game_data {
    char    **file_content;
} t_game_data;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
int     ft_strncmp(const char *s1, const char *s2, size_t n);

int     check_extension(char *file, char *extension);
int     store_map(char *path, t_game_data *data);


# endif