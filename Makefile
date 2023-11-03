NAME = cub3D

CC = cc

GLFW = $(shell brew --prefix glfw)

FRAMEWORKS = /Users/nachab/Desktop/Cub3d/MLX42/build/libmlx42.a -Iinclude -lglfw -L $(GLFW)/lib/ -framework Cocoa -framework OpenGL -framework IOKit -fsanitize=address

FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRC = main.cpp rgb_conversion.c get_file_data.c init_data.c store_data.c check_map_utils.c file_parser.c check_player.c

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT_SRC = libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strchr.c libft/ft_calloc.c libft/ft_bzero.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_split.c


OBJ = $(SRC:.cpp=.o) $(GNL_SRC:cpp=.o) $(LIBFT_SRC:.cpp=.o)


all: $(NAME) 

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS)  $^ $(FRAMEWORKS) -o $@


%.o: %.cpp
	$(CC) $(FLAGS)  -Imlx -c $< -o $@

clean :
	@find . -name "*.o" -type f -delete

fclean : clean
	@rm -rf $(NAME)

re : fclean all
