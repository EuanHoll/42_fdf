# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: euan <ehollidg@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 15:51:09 by euan           #+#    #+#                 #
#    Updated: 2019/06/07 17:16:33 by ehollidg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = main drawinfo hookcontrols read_file closeprogram fdfloop plotpoint \
    	inbounds doubletocolour bcolour isoproject drawmap convert_file
SRCF = $(SRC:%=srcs/%.c)
OBJ = $(SRC:%=%.o)
NAME = fdf
MINILIBX = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
LIBFT = -I libft/includes -L libft -lft
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCF)
	@echo "Compiling Libaries"
	@make -C libft/
	@make -C minilibx/
	@echo "Compiling Program"
	@clang $(FLAGS) -I minilibx -I libft/includes -c $(SRCF) -g
	@clang -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX) -g
	@echo "Finished"

clean:
	@echo "Cleaning Libaries"
	@make -C libft/ clean
	@make -C minilibx/ clean
	@echo "Cleaning Program"
	@rm -f $(OBJ)
	@echo "Finished Cleaning Program"

fclean: clean
	@echo "Removing Libaries"
	@make -C libft/ fclean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@echo "Finished"

re: fclean all
