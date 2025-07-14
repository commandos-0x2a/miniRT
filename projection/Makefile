NAME = projection

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -I../MLX42/include -I../object
LDFLAGS =  -lmlx42 -lglfw -lm -Lbuild

ifeq ($(DEBUG), 1)
	CFLAGS += -DDEBUG
endif

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LDFLAGS += -ldl -pthread 
else ifeq ($(UNAME_S), Darwin)
	LDFLAGS += -L"/opt/homebrew/Cellar/glfw/3.4/lib"
	CPPFLAGS += -I"/opt/homebrew/Cellar/glfw/3.4/include"
endif

SRC = ../object/object.c						\
	../object/cube.c						\
	../object/mesh.c						\
	../object/camera.c						\
	../object/drawing.c					\
	../object/model.c						\
	projection.c						\
	test_projection.c


OBJ = $(SRC:%.c=build/%.o)

all: MLX42 $(NAME)

MLX42:
	cmake -S ../MLX42 -B build -Wno-dev
	cmake --build build -j4

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re MLX42