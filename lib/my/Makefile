##
## EPITECH PROJECT, 2019
## Makefile 1
## File description:
## Makefile
##

SRC	=	my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_putchar.c \
		my_putstr.c \
		my_put_nbr.c \
		my_revstr.c \
		my_showstr.c \
		my_sort_int_array.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_strupcase.c \
		my_swap.c \
		print_error.c \
		is_alpha.c \
		is_num.c \
		my_strtol.c \
		my_memset.c \
		my_put_double.c \
		my_printf.c \
		printf_funcs_part1.c \
		printf_funcs_part2.c \
		printf_funcs_part3.c \
		printf_funcs_part4.c \
		flags.c \
		my_itos.c \
		my_str_split.c \
		my_str_split2char.c \
		arr2d_destroy.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	Test

all:	$(NAME)

$(NAME):	$(OBJ)
	cp my.h ../../include/
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)
	find . -name "*[#|~]" -delete  -o -name "[#]*" -delete

fclean:	clean
	rm -f $(NAME)
auteur:
	echo $(USER) > auteur
