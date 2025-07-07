NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
CPPFLAGS = -IMLX42/include
LDFLAGS =  -lmlx42 -lglfw -lm -Lbuild


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LDFLAGS += -ldl -pthread 
else ifeq ($(UNAME_S), Darwin)
	LDFLAGS += -L"/opt/homebrew/Cellar/glfw/3.4/lib"
endif


SRC = main.c
OBJ = $(SRC:%.c=build/%.o)



all: MLX42 $(NAME)

MLX42:
	cmake -S MLX42 -B build
	cmake --build build -j4

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

build/%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re MLX42