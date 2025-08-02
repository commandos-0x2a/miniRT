NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
CPPFLAGS = -IMLX42/include -Iobject -Ilibft/include -Icomponents -Iutils -Iprojection -Idebug
LDFLAGS =  -lmlx42 -lglfw -lm -Lbuild -Llibft -lft # -fsanitize=address

include debug/log.mk

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LDFLAGS += -ldl -pthread 
else ifeq ($(UNAME_S), Darwin)
	LDFLAGS += -L"/opt/homebrew/Cellar/glfw/3.4/lib"
	CPPFLAGS += -I"/opt/homebrew/Cellar/glfw/3.4/include"
endif

SRC += main.c							\
	components/cube.c					\
	object/object.c						\
	object/model.c						\
	object/camera.c						\
	utils/drawing.c						\
	utils/matrix.c						\
	projection/perspective_projection.c	\

TEST_SRC = utils/read_content.c
TEST_OBJ = $(TEST_SRC:%.c=build/%.o)
TEST_NAME = test

OBJ = $(SRC:%.c=build/%.o)


all: MLX42 $(NAME)

MLX42:
	cmake -S MLX42 -B build -Wno-dev
	cmake --build build -j4

libft:
	$(MAKE) -C libft

$(NAME): $(OBJ) | libft
	$(CC) -o $@ $^ $(LDFLAGS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

test: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

re: fclean all

.PHONY: all clean fclean re MLX42 test libft