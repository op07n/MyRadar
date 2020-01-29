##
## EPITECH PROJECT, 2019
## CPE_BSQ_2019
## File description:
## Makefile
##

SRC		=		$(wildcard src/*.c) \
				$(wildcard src/tower/*.c) \
				$(wildcard src/aircraft/*.c) \
				$(wildcard src/quadtree/*.c) \
				$(wildcard src/window/*.c) \
				$(wildcard src/imgs/*.c) \

OBJ		=		$(SRC:.c=.o)

NAME	=		my_radar

CFLAGS	+=		-g3

LIBS	=		-L./lib/my -lmy \
				-lcsfml-graphics -lcsfml-system -lcsfml-window -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	make -C lib/my clean
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
