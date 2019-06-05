# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: euan <ehollidg@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 15:51:09 by euan           #+#    #+#                 #
#    Updated: 2019/06/05 12:00:22 by ehollidg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = main
SRCF = $(SRC:%=srcs/%.c)
OBJ = $(SRC:%=%.o)
NAME = fdf
FRAMEWORK = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(SRCF)
	make -C minilibx/ clean && make -C minilibx/
	clang -Wall -Werror -Wextra -I minilibx -c $(SRCF)
	clang -o $(NAME) $(OBJ) -I minilibx -L minilibx $(FRAMEWORK)

clean:
	make -C minilibx/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
