# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: euan <ehollidg@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 15:51:09 by euan           #+#    #+#                 #
#    Updated: 2019/06/06 11:46:48 by ehollidg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = main drawinfo hookcontrols read_file closeprogram fdfloop plotpoint \
      inbounds swap dlgradient fpart rfpart drawline doubletocolour 
SRCF = $(SRC:%=srcs/%.c)
OBJ = $(SRC:%=%.o)
NAME = fdf
MINILIBX = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
LIBFT = -I libft/includes -L libft -lft

all: $(NAME)

$(NAME): $(SRCF)
	make -C libft/ fclean && make -C libft/
	make -C minilibx/ clean && make -C minilibx/ 
	clang -Wall -Werror -Wextra -I minilibx -I libft/includes -c $(SRCF)
	clang -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)

clean:
	make -C libft/ clean
	make -C minilibx/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
