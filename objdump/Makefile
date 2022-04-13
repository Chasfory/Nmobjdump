##
## EPITECH PROJECT, 2022
## B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
## File description:
## Makefile
##

SRC			=	src/main.c								\
				src/open_file.c							\
				src/get_elf_descriptor.c				\
				src/32_type/display_32.c				\
				src/32_type/gettype.c					\
				src/32_type/obtain_elf_descriptor_32.c	\
				src/32_type/space.c						\
				src/64_type/display_64.c				\
				src/64_type/gettype.c					\
				src/64_type/obtain_elf_descriptor_64.c	\
				src/64_type/space.c						\

OBJ			=	$(SRC:.c=.o)

NAME		=	./../my_objdump

CFLAGS		+=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include

CC		=	gcc

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

debug: CFLAGS += -g3
debug: re
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean