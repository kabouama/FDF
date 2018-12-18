# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: sbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/23 14:23:54 by sbedene      #+#   ##    ##    #+#        #
#    Updated: 2018/12/17 00:18:18 by kabouama    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

HEADER = ./includes

MINILIB = ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

SRC = src/main.c				\
	  src/fdf.c					\
	  src/segment_algo.c		\
	  src/fdf_parsing.c			\
	  src/projection_oblique.c	\
	  src/projection_iso.c		\
	  src/key_hook.c			\
	  src/stock_point.c			\
	  src/put_str_win.c			\

FLAGS = -Wall -Wextra -Werror

OBJ= $(SRC:.c=.o)

all: 	$(NAME)
	@make -C libft

$(NAME): $(OBJ)
	 $(MAKE)  -C libft
	 $(MAKE)  -C minilibx_macos
	 gcc -I includes -o $@ $^ libft/libft.a $(FLAGS) -I $(HEADER) -L $(MINILIB)

%.o: %.c includes/fdf.h libft/libft.h
	 gcc -I includes -o $@ -c $< $(FLAGS)

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -rf libft/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
