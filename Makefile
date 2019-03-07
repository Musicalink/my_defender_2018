##
## EPITECH PROJECT, 2019
## Makfile
## File description:
## defender
##

SRC     =       src/main.c		\
                src/menu.c		\
                src/game_start.c\
                src/obj_gen_help.c\
                src/object_generation.c\
                src/totem_up.c\
                src/totem_update.c\

OBJ     =       $(SRC:.c=.o)

NAME    =       my_defender

CFLAGS  =       -Iinclude

SFFLAGS =       -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -Llib/my -lmy

all:    $(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(OBJ) $(SFFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:  fclean all
