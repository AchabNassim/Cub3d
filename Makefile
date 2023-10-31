NAME = cub3d

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = main.cpp check_utils.c

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT_SRC = libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strchr.c libft/ft_calloc.c libft/ft_bzero.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_split.c

OBJ = $(SRC:.cpp=.o) $(GNL_SRC:cpp=.o) $(LIBFT_SRC:.cpp=.o)


all: $(NAME) 

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $^ -o $@


%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@find . -name "*.o" -type f -delete

fclean : clean
	@rm -rf $(NAME)

re : fclean all
