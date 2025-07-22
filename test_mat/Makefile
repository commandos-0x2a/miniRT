NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS += -I../MLX42/include -Iobject_ -I../libft/include 
LDFLAGS =  -lmlx42 -lglfw -lm -Lbuild -L../libft -lft

include debug/log.mk

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LDFLAGS += -ldl -pthread 
else ifeq ($(UNAME_S), Darwin)
	LDFLAGS += -L"/opt/homebrew/Cellar/glfw/3.4/lib"
	CPPFLAGS += -I"/opt/homebrew/Cellar/glfw/3.4/include"
endif

SRC = main_.c							\
	object_/object_.c						\
	object_/cube_.c						\
	object_/mesh_.c						\
	object_/camera_.c						\
	object_/drawing_.c					\
	object_/model_.c						\
	object_/matrix_.c						\

OBJ = $(SRC:%.c=build/%.o)

all: MLX42 $(NAME)

MLX42:
	cmake -S ../MLX42 -B build -Wno-dev
	cmake --build build -j4

libft:
	$(MAKE) -C ../libft

$(NAME): $(OBJ) | libft
	$(CC) -o $@ $^ $(LDFLAGS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

test:
	$(CC) $(CFLAGS) $(CPPFLAGS) -o test_projection projection/test_projection.c $(LDFLAGS)

re: fclean all

.PHONY: all clean fclean re MLX42 test libft