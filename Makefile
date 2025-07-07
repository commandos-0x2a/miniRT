NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
CPPFLAGS = -IMLX42/include
LDFLAGS =  -lmlx42 -lglfw -LMLX42/build -L"/opt/homebrew/Cellar/glfw/3.4/lib"
SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re