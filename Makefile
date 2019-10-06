NAME = RTv1
WFLAGS = -Wall -Werror -Wextra
SRC = ./src/cone.c ./src/control.c ./src/cylinder.c ./src/get_pixel_color.c ./src/image.c ./src/init_scene.c ./src/lightning.c ./src/main.c ./src/plane.c ./src/sphere.c
OBJ = $(SRC:.c=.o)
INC = -I ./libgm/include -I ./libft/includes -I ./includes
LIBFT = -L ./libft -lft
LIBGM = -L ./libgm -lgm
LIBS = -lmlx -lm -framework OpenGL -framework AppKit

all : make_lib $(NAME)

$(NAME) : $(OBJ)
	gcc $(WFLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBS) $(LIBFT) $(LIBGM)

make_lib :
	make -C ./libft
	make -C ./libgm

%.o : %.c
	gcc -g $(WFLAGS) $(INC) -o $@ -c $<

clean :
	make -C ./libft clean
	make -C ./libgm clean
	rm $(OBJ)

fclean : clean
	make -C ./libft fclean
	make -C ./libgm fclean
	rm $(NAME)

re : fclean all
