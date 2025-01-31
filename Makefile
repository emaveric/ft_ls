# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 20:23:00 by mplutarc          #+#    #+#              #
#    Updated: 2019/12/25 16:41:08 by emaveric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FILES = main.c validation.c flags.c sorting.c output.c flags_output.c \
flags_sorting.c free_tree.c columns.c valid_error.c tree_create.c \
files_and_dir.c

SRC = $(addprefix src/, $(FILES))

INC = includes/ft_ls.h

OBJ = $(addprefix obj/, $(FILES:.c=.o))

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror -Weverything

all: $(NAME)

lib:
	@make -C libft

$(NAME): $(OBJ) lib
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

obj/%.o: src/%.c | obj
	gcc -c -I./libft $< -o $@

clean:
	rm -rf $(OBJ)
	make -C libft clean

obj:
	mkdir -p obj

fclean: clean
	/bin/rm -rf $(NAME) ./obj
	make -C libft fclean

re: fclean all
