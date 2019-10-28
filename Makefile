NAME = RTv1
WFLAGS = -Wall -Werror -Wextra
SRC = cone.c control.c cylinder.c get_pixel_color.c image.c init_scene.c lightning.c main.c plane.c sphere.c read_scene.c parse.c
SRC_DIR = ./src
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_DIR = ./obj
INC = -I ./libgm/include -I ./libft/includes -I ./includes
LIBFT = -L ./libft -lft
LIBGM = -L ./libgm -lgm
LIBS = -lmlx -lm -framework OpenGL -framework AppKit

all : make_lib $(NAME)

$(NAME) : $(OBJ)
	gcc $(WFLAGS) $(OBJ) $(INC) $(LIBFT) $(LIBGM) $(LIBS) -o $(NAME)

make_lib :
	make -C ./libft
	make -C ./libgm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc -g $(WFLAGS) $(INC) -o $@ -c $<

clean :
	make -C ./libft clean
	make -C ./libgm clean
	rm -rf $(OBJ_DIR)

fclean : clean
	make -C ./libft fclean
	make -C ./libgm fclean
	rm -f $(NAME)

re : fclean all
